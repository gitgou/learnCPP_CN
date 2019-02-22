///
 /// @file    Timer.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-20 19:52:12
 ///

#include "Timer.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/timerfd.h>
#include <errno.h>
#include <poll.h>

#include <iostream>

using std::cout;
using std::endl;
namespace yll
{
Timer::Timer(TimerCallback && callback, int initialTime, int periodcTime)
:_fd(creatTimerfd())
,_initialTime(initialTime)
,_periodicTime(periodcTime)
,_callback(std::move(callback))
,_isStart(false)
{}

Timer::~Timer()
{
	if(_isStart == false)
		stop();
}
int Timer::creatTimerfd()
{
	int fd = ::timerfd_create(CLOCK_REALTIME, 0);
	if(fd == -1){
		perror("timerfd_create");
	}
	return fd;
}
void Timer::handleRead()
{
	uint64_t howmany = 0;
	int ret = ::read(_fd, &howmany, sizeof(uint64_t));
	if(ret != sizeof(howmany)){
		perror(">> read");
	}
}
void Timer::start()
{
	struct pollfd pfd;	
	pfd.fd = _fd;
	pfd.events = POLLIN;

	_isStart = true;
	setTimefd(_initialTime, _periodicTime);

	while(_isStart)
	{
		int ready = ::poll(&pfd, 1, 5000);
		if(ready == -1 && errno == EINTR)
			continue;
		else if(ready == -1)
		{
			perror(">> poll");
			exit(EXIT_FAILURE);
		}else if(ready == 0){
			cout << ">> poll timeout!" << endl;
		}else{
			if(pfd.fd == _fd && (pfd.events & POLLIN)){
				handleRead();
				if(_callback)
					_callback();
			}
		}
	}
}

void Timer::stop()
{
	if(_isStart == true)
	{
		_isStart = false;
		setTimefd(0, 0);//new_value 设置= 0,表示停止定时器
	}

}

void Timer::setTimefd(int initialTime, int periodcTime)
{
	struct itimerspec value;
	value.it_value.tv_sec = initialTime;
	value.it_value.tv_nsec = 0;
	value.it_interval.tv_sec = periodcTime;
	value.it_interval.tv_nsec = 0;
	int ret = timerfd_settime(_fd, 0, &value, nullptr);
	if(ret == -1){
		perror("timerfd_settime");
	}
}
}// end of namespace yll
