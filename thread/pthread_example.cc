 ///
 /// @file    pthreadTest.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-10 17:21:21
 ///
#include <stdio.h> 
#include <pthread.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;


int number = 1000;
pthread_mutex_t mutex ;
void * Function(void *)
{
	int cnt = 10;
	pthread_mutex_lock(&mutex);
	while(cnt--){
		--number;
		printf("sub thread %ld, number = %d!\n", pthread_self(), number);
		//sleep(1);
	}
	pthread_mutex_unlock(&mutex);
	return nullptr;
}
void * Function2(void *)
{
	pthread_mutex_lock(&mutex);
	int cnt = 10;
	while(cnt--){
		--number;
		printf("sub thread %ld, number = %d!\n", pthread_self(), number);
		//sleep(1);
	}
	pthread_mutex_unlock(&mutex);
	return nullptr;
}
int main(void)
{
	pthread_mutex_init(&mutex, NULL);
	printf("main thread is start running!\n");
	pthread_t pthid1, pthid2;
	pthread_create(&pthid1, NULL, Function, NULL);//开启一个线程
	pthread_create(&pthid2, NULL, Function2, NULL);//开启一个线程
	printf("main thread: %ld, 子线程1 = %ld, 子线程2 = %ld\n",pthread_self(), pthid1, pthid2);
	//sleep(3);
	pthread_join(pthid1, nullptr);
	pthread_join(pthid2, nullptr);
	printf("main thread is exit\n");
}
