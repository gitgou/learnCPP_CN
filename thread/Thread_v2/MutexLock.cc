 ///
 /// @file    MutexLock.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-12 19:55:22
 ///

#include "MutexLock.h"

#include <stdio.h>
#include <errno.h>
#include <pthread.h>

#include <iostream>

using std::cout;
using std::endl;
namespace yll
{
	MutexLock::MutexLock()
	{
		if(pthread_mutex_init(&_mutex, NULL))
		{
			perror("pthread_mutex_init()");
		}
		//cout << "MutexLock() " << endl;
	}
	
	void MutexLock::lock()
	{
		if(pthread_mutex_lock(&_mutex))
			perror("pthread_mutex_lock()");
	}

	void MutexLock::unlock()
	{
		if(pthread_mutex_unlock(&_mutex))
			perror("pthread_mutex_unlock()");
	}

	MutexLock::~MutexLock()
	{
		if(pthread_mutex_destroy(&_mutex))
			perror("pthread_mutex_destroy()");
		//cout << "~MutexLock()" << endl;
	}



}//end of yll
