 ///
 /// @file    Thread.h
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-10 21:55:17
 ///
#ifndef __YLL_THREAD_H__
#define __YLL_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace yll
{
class Thread
:public Noncopyable
{
public:
	Thread();
	void start();//开启子进程
	void join();//阻塞子线程
	virtual ~Thread();
	bool isRunning() { return _isRunning;	}
private:
	virtual void run() =0;//线程要执行的任务
	static void * threadFunc(void * arg);//pthread_create函数参数
private:
	pthread_t _pthid;
	bool _isRunning;
};
}//end of namespace yll

















#endif  
