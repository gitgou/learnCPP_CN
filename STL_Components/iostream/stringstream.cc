 ///
 /// @file    StringStream.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-12 22:46:09
 ///
 
#include <iostream>
#include<sstream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::istringstream;
using std::ostringstream;

/*
	stringstream 继承于 istreamstream 和 ostringstream
	所以 stringstream 可以同时作为input/output stream; iostream 同理
i	cppreference : https://en.cppreference.com/w/cpp/io/basic_stringstream/basic_stringstream
*/
void test()
{
	stringstream ss ;
	int number1 = 10 ;
	int number2 = 20 ;
	ss << "number1= " << number1 << " number2= " << number2 <<endl;
	string str = ss.str();
	cout << str << endl;

	string key ;
	int value ;
	while(ss >> key >> value , !ss.eof())
	{    //输入流都是以空格作为分割
		cout << "key = " << key << "value = " << value << endl;
	}
}

int main(void)
{
	test();
	return 0; 
}
