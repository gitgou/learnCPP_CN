 ///
 /// @file    TimeThread.h
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-21 20:58:34
 ///

#ifndef __YLL_TIMETHREAD_H__
#define __YLL_TIMETHREAD_H__

#include "Timer.h"
#include "Thread.h"
namespace yll
{
class TimerThread
{
public:
	using TimerCallback = std::function<void()>;
	TimerThread(TimerCallback && callback, int initalTime, int periodcTimer);

	void start();
	void stop();

private:
	yll::Timer _timer;
	yll::Thread _thread;
};

}// end of namesapce yll

#endif 
