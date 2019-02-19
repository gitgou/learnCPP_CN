 ///
 /// @file    Condition.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-12 21:00:42
 ///
#include "Condition.h"

#include <stdio.h>
#include <errno.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;

namespace yll
{
	Condition::Condition(MutexLock & mutex)
	:_mutex(mutex)
	{
		if(pthread_cond_init(&_cond, NULL))
			perror("pthread_cond_init()");
	}

	void Condition::wait()
	{
		
		if(pthread_cond_wait(&_cond,_mutex.getPthreadMutex()))
			perror("pthread_cond_wait()");
	}

	void Condition::notify()
	{
		if(pthread_cond_signal(&_cond))
			perror("pthread_cond_signal()");
	}

	void Condition::notifyall()
	{
		if(pthread_cond_broadcast(&_cond))
			perror("pthread_cond_broadcast()");
	}

	Condition::~Condition()
	{
		if(pthread_cond_destroy(&_cond))
			perror("pthread_cond_destroy()");
	}

}//end of yll










