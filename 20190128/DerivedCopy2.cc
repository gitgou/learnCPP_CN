 ///
 /// @file    DerivedCopy.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-28 21:30:17
 ///

#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base()
	:_data(nullptr)
	{
		cout << "Base()" << endl;
	}

	Base(const char * ptr)
	:_data(new char[strlen(ptr) + 1]())
	{
		strcpy(_data, ptr);
		cout << "Base(const char * ptr)" << endl;
	}

	Base(const Base & rhs)
	:_data(new char[strlen(rhs._data)+1]())
	{
		strcpy(_data, rhs._data);
		cout << "Base(const Base & rhs)" << endl;
	}
	Base & operator=(const Base & base)
	{
		cout << "Base & operator=(const Base & base)" << endl;
		if(this != &base)
		{
			delete [] _data;
			_data = new char [strlen(base._data)+1]();
			strcpy(_data, base._data);
		}
		return *this;
	}
	friend std::ostream & operator<<(std::ostream & os, const Base & rhs);

	~Base()
	{
		if(_data)
			delete [] _data;
		cout << "~Base()" << endl;
	}
private:
	char * _data;
};

std::ostream & operator<<(std::ostream & os, const Base & rhs)
{
	os << rhs._data;
	return os;
}
class Derived
:public Base
{
public:
	Derived()
	:_data2(nullptr)
	{
		cout << "Derived()" << endl;
	}
	Derived(const char * ptr, const char * ptr2)
	:Base(ptr)
	,_data2(new char[strlen(ptr2)+1]())
	{
		strcpy(_data2, ptr2);
		cout << "Derived()" << endl;
	}
	//派生类显示复制控制函数，则必须显示调用基类复制构造函数
	Derived(const Derived & rhs)
	:Base(rhs) //rhs向上转型
	,_data2(new char[strlen(rhs._data2)+1]())
	{
		strcpy(_data2, rhs._data2);
		cout << "Derived(const Derived & rhs)" << endl;
	}
	Derived & operator=(const Derived & rhs)
	{
		cout << "Base & operator=(const Base & base)" << endl;
		if(this != &rhs)
		{
			Base::operator=(rhs);//显示调用
			delete [] _data2;
			_data2 = new char [strlen(rhs._data2)+1]();
			strcpy(_data2, rhs._data2);
		}
		return *this;
	}
	friend std::ostream & operator<<(std::ostream & os, const Derived & rhs);
	~Derived()
	{
		cout << "~Derived()" << endl;
	}
private:
	char * _data2;
};
std::ostream & operator<<(std::ostream & os, const Derived & rhs)
{
	const Base & base = rhs;//向上转型
	os << base
	   << rhs._data2;
	return os;
}
int main(void)
{
	Derived d1("hello", "world");

	cout << "d1 = " << d1 << endl;

	//Derived d2(d1);
	//cout << "d2 = " << d2 << endl;
	Derived d2;
	d2 = d1;
	cout << "d2 = " << d2 << endl;
	return 0;
}
