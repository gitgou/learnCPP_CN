 ///
 /// @file    testMylogger.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-19 22:49:18
 ///

#include"Mylogger.h"
#include<string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test()
{
			
	logWarn("this is a warn message%s ","hello");
	logInfo("this is a info message");
	logError("this is a error message");
	logDebug("this is a debug message");
}
int main(void)
{
	test(); 
}
