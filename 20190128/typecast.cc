 ///
 /// @file    typecast.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-28 20:40:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	Base(double base)
	:_base(base)
	{	cout << "Base(double base)" << endl;}

	void display()
	{
		cout << "_base = " << _base << endl;
	}
private:
		double _base;
};

class Derived
:public Base
{
public:
	Derived(double base, double value)
	:Base(base)
	,_value(value)
	{
		cout << "Derived(double value) " << endl;
	}
private:
	double _value;
};
int main(void)
{
	Derived d(11.11, 22.22);
	d.display();
	Base b = d;
	b.display();
	return 0;
}
