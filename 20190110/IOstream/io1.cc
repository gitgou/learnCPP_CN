 ///
 /// @file    io1.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-11 20:36:12
 ///
 
#include <iostream>
#include<string.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;
 
void test0()
{
	int number = 0;
	cin >>  number ;
	cout << "number = " << number << endl;
}

void printstatus()
{
	cout << "cin.bad = " << cin.bad() <<endl;
	cout << "cin.fail = " << cin.fail() <<endl; 
	cout << "cin.eof = " << cin.eof() <<endl; 
	cout << "cin.good = " << cin.good() <<endl; 
}

void test2()
{
	printstatus();
	test0();
	printstatus();
    
	cin.clear(); //重置cin的状态
	cin.ignore(1024 , '\n');// 清空缓冲区，第一个参数字节数
	                 //第二个参数清空结尾标志

	string s1;
	cin >> s1 ;
	cout << "s1 = " << s1 << endl ; 
	printstatus();


}

int main(void)
{
	test2();	
	return 0; 
}
