 ///
 /// @file    pthreadTest.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-10 17:21:21
 ///
#include "MutexLock.h"
#include "Condition.h"
#include "Thread.h"
#include <stdio.h> 
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <memory>

using std::unique_ptr;
using std::cout;
using std::endl;


class Example
{
public:
	Example()
	:_mutex()
	,_cond(_mutex)
	{}

	void  Function1();
	void  Function2(void);

	~Example()
	{}
private:	
	int number = 1000;
	yll::MutexLock _mutex;
	yll::Condition _cond;
	//pthread_mutex_t mutex;
	//pthread_cond_t cond1;
	bool flag = true;
};
void  Example::Function1()
{
	int cnt = 10;
	//pthread_mutex_lock(_mutex.getPthreadMutex());
	_mutex.lock();
	while(cnt--){
		if(flag == false)
			//pthread_cond_wait(&cond1, &mutex);//当flag= false,自我阻塞；
		//并解锁
			_cond.wait();
		--number;
		printf("sub thread %ld, number = %d!\n", pthread_self(), number);
		//sleep(1);
		if(flag == true)
			flag = false;
		_cond.notify();
		_mutex.unlock();
		//pthread_cond_signal(&cond1);//唤醒阻塞线程
		//pthread_mutex_unlock(&mutex);
	}
	//return nullptr;
}
void  Example::Function2()
{
	//pthread_mutex_lock(&mutex);
	_mutex.lock();
	int cnt = 10;
	while(cnt--){
		if(flag == true)
			_cond.wait();
			//pthread_cond_wait(&cond1, &mutex);
		//当受到signal 信号会被唤醒
		--number;
		printf("sub thread %ld, number = %d!\n", pthread_self(), number);
		//sleep(1);
		if(flag == false)
			flag = true;
		_cond.notify();
		_mutex.unlock();
		//pthread_cond_signal(&cond1);
		//pthread_mutex_unlock(&mutex);
	}
	//return nullptr;
}
int main(void)
{
	//yll::MutexLock mutexLock;
	Example example;
	unique_ptr<yll::Thread> thread1(new yll::Thread(
				std::bind(&Example::Function1, &example)));
	unique_ptr<yll::Thread> thread2(new yll::Thread(
				std::bind(&Example::Function2, &example)));
	thread1->start();
	thread2->start();
	
	thread1->join();
	thread2->join();
	return 0;
}




