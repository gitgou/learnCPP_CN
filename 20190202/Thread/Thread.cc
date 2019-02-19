//
 ///
 /// @file    Thread.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-10 22:07:27
 ///
#include "Thread.h"
#include <pthread.h>
namespace yll
{
	Thread::Thread()
	:_pthid(0)
	,_isRunning(false)
	{}

	void Thread::start()
	{
		pthread_create(&_pthid, NULL, threadFunc, this);
		_isRunning = true;
	}
	void * Thread::threadFunc(void * arg)
	{
		//得到arg的值为this指针的值,需要将其类型转换
		Thread * p = static_cast<Thread *>(arg);
		if(p){
			p->run();
			p->_isRunning = true;
		}
		return NULL;
	}
	void Thread::join()
	{
		if(_isRunning)
		{
			pthread_join(_pthid, NULL);
			_isRunning = false;
		}
	}
	Thread::~Thread()
	{
		if(_isRunning)
		{
			pthread_detach(_pthid);
			_isRunning = false;
		}
	}
}// end of namespace yll
