 ///
 /// @file    TimerThread.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-21 21:08:30
 ///

#include "TimeThread.h"

namespace yll
{
TimerThread::TimerThread(TimerCallback && cb, int initialTime, int periodicTime)
:_timer(std::move(cb), initialTime, periodicTime)
,_thread(std::bind(&Timer::start, &_timer))  //不加取地址符号。则进行的是值传递
{}	                                        //std::bind支持值传递，引用传递。和指针传递

void TimerThread::start()
{
	_thread.start();
}

void TimerThread::stop()
{
	_timer.stop();
	_thread.join();
}
}//end of namespace yll
