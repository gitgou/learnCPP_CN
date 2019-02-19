 ///
 /// @file    Condition.h
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-12 20:38:10
 ///
#ifndef __YLL_CONDITION_H__
#define __YLL_CONDITION_H__


#include "Noncopyable.h"
#include "MutexLock.h"
#include <pthread.h>

namespace yll
{

class MutexLock;

class Condition
:Noncopyable 
{
public:
	Condition(MutexLock & mutex);
	void wait();
	void notify();
	void notifyall();
	~Condition();
private:
	MutexLock & _mutex;
	pthread_cond_t _cond;
};
}// end of yll


#endif 
