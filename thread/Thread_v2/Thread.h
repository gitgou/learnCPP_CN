 ///
 /// @file    Thread.h
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-10 21:55:17
 ///
#ifndef __YLL_THREAD_H__
#define __YLL_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>

namespace yll
{
class Thread
:Noncopyable
{
public:
	//
	using callback = std::function<void()>;
	Thread(callback && callbackThread);
	void start();//开启子进程
	void join();//阻塞子线程
	pthread_t getPthid()	{	return _pthid; }
	~Thread();
	bool isRunning() { return _isRunning;	}
private:
	//不需要run方法
	static void * threadFunc(void * arg);//pthread_create函数参数
private:
	callback _callbackThread;
	pthread_t _pthid;
	bool _isRunning;
};
}//end of namespace yll

















#endif  
