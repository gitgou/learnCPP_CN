 ///
 /// @file    testThread.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-11 19:34:35
 ///
#include "Thread.h" 
#include <iostream>
#include <memory>
using std::unique_ptr;
using std::cout;
using std::endl;

class MyThread
:public yll::Thread
{
	void run() override
	{
		int cnt = 10;
		while(cnt--)
		{
			//printf("sub thread = %ld\n",_pthid);
			printf("sub thread = %ld, cnt = %d \n",pthread_self(), cnt);
		}
	}
};
 
int main(void)
{
	//虚函数激活机制基类指针指向派生类对象
	printf("main thread is start\n");
	unique_ptr<yll::Thread> myThread(new MyThread);

	myThread->start();

	myThread->join();

	cout << "main thread is exit" << endl;
	return 0;
}
