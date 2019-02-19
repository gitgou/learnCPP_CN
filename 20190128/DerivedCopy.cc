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
	Derived(const char * ptr)
	:Base(ptr)
	{
		cout << "Derived()" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, const Derived & rhs);
	~Derived()
	{
		cout << "~Derived()" << endl;
	}
private:

};
std::ostream & operator<<(std::ostream & os, const Derived & rhs)
{
	const Base & base = rhs;//向上转型
	os << base;
	return os;
}
int main(void)
{
	Derived d1("hello");

	cout << "d1 = " << d1 << endl;

	//Derived d2(d1);
	//cout << "d2 = " << d2 << endl;
	Derived d2("world");
	d2 = d1;
	cout << "d2 = " << d2 << endl;
	return 0;
}
