 ///
 /// @file    Timer.h
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-20 19:45:54
 ///

#ifndef __YLL_TIMER_H__
#define __YLL_TIMER_H__

#include <functional>

namespace yll
{
class Timer
{
public:
	using TimerCallback = std::function<void()>;
	Timer(TimerCallback && callback, int initialTime, int periodcTime);
	~Timer();

	int creatTimerfd();
	void start();
	void stop();
	void handleRead();
	void setTimefd(int initialTime, int periodcTime);
private:
	int _fd;
	int _initialTime;
	int _periodicTime;//周期时间
	TimerCallback _callback;
	bool _isStart;
};


}//end of namespace yll


#endif
