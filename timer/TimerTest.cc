 ///
 /// @file    TimerTest.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-20 23:24:37
 ///
#include "Timer.h"
#include "Thread.h"
#include "TimeThread.h"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

class Example
{
public:
	void run() 
	{
		::srand(::clock());
		int number = ::rand()%100;
		cout << "number = " << number << endl;
	}
};
int main(void)
{
	yll::TimerThread timer(std::bind(&Example::run, Example()), 3,  5);
	timer.start();

	sleep(15);
	timer.stop();
	return 0;
}
