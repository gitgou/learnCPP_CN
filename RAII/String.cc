 ///
 /// @file    String.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-25 22:18:41
 ///

#include<string.h>
#include <iostream>
#include<string>
#include<vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class String
{
public:
	String(const String & rhs)
	:_ptr(new char[strlen(rhs._ptr)+1]())
	{
		strcpy(_ptr, rhs._ptr);
		cout << "String(const String & ptr) " << endl;
	}
	String(const char * ptr)
	:_ptr(new char[strlen(ptr) + 1]())
	{
		strcpy(_ptr, ptr);
		cout << "String(const char *) " << endl;
	}

	String & operator=(const String & rhs)
	{
		if(this != &rhs)
		{
			delete [] _ptr;
			_ptr = new char[strlen(rhs._ptr) + 1]();
			strcpy(_ptr, rhs._ptr);
			cout << " String operator=(const String)" << endl;
		}
		return *this;
	}
    //移动复制构造函数
	String(String && rhs)
	:_ptr(rhs._ptr) //直接指向此堆空间
	{
		rhs._ptr = nullptr; //指为空区
		cout << "String(String && rhs)" << endl;
	}
	String  & operator=(String && rhs)
	{
		delete [] _ptr;
		_ptr = rhs._ptr;
		rhs._ptr = nullptr;
		cout << "String operator=(String && rhs)" << endl;
		return *this;
	}
	~String()
	{
		if(_ptr)
			delete [] _ptr;
		cout << "~String() " << endl;
	}
private:
		char * _ptr;
};
 
int main(void)
{
	//vector<String> numbers;
	//numbers.push_back("hello"); //先生成String对象，后移动复制构造函数

	String s1("hello");
	s1 = "world";//先隐式转换为String

}
