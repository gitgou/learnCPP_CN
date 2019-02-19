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
void * Function(void *)
{
	int cnt = 10;
	while(cnt--){
		printf("sub thread %u!\n", pthread_self());
		//sleep(1);
	}
	return nullptr;
}
int main(void)
{
	printf("main thread is start running!\n");
	pthread_t pthid;
	pthread_create(&pthid, NULL, Function, NULL);//开启一个线程
	printf("main thread: %u, 子线程id = %u\n",pthread_self(), pthid);
	//sleep(3);
	pthread_join(pthid, nullptr);
	printf("main thread is exit\n");
}
