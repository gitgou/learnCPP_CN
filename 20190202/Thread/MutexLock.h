 ///
 /// @file    MutexLock.h
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-12 19:46:28
 ///
 
#ifndef __YLL_MUTEXLOCK_H__
#define __YLL_MUTEXLOCK_H__


#include "Noncopyable.h"

#include <pthread.h>
namespace yll
{
class MutexLock
:Noncopyable
{
public:

	MutexLock();
	void lock();
	void unlock();
	pthread_mutex_t * getPthreadMutex() {	return &_mutex;  }
	~MutexLock();
private:
	pthread_mutex_t _mutex;
};

}// end of yll




#endif 
