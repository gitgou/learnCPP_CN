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

void display(Base * base)
{
	base->display(); //同一指令对不同对象，产生不同的响应
}
int main(void)
{
	Base b;
	display(&b);

	Derived d;
	display(&d);
}
