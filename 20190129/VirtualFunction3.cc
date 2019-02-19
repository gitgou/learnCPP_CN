 ///
 /// @file    VirtualFunction.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-29 19:44:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Base
{
public:
	Base()
	:_base(0)
	{
		cout << "Base()" << endl;
	}
	virtual
	void display()
	{
		cout << "Base::display()  _base = " << _base << endl;
	}
	void fun1()
	{
		display(); //会发生函数覆盖
	}

	void fun2()
	{
		Base::display();
	}
private:
	double _base;
};

class Derived
:public Base
{
public:
	Derived()
	:_derived(0)
	{
		cout << "Derived()" << endl;
	}
	
	void display() //虚函数，覆盖
	{
		cout << "Derived::display() _derived = " << _derived << endl;
	}
private:
	double _derived;
};

int main(void)
{
	Base b;
	Base *pb = &b;
	pb->fun1();
	pb->fun2();
	Derived d;
	Base *b1;
	b1 = &d;
	b1->fun1();
	b1->fun2();
}
