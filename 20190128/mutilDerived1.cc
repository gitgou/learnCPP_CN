 ///
 /// @file    mutilDerived1.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-28 19:52:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A(){	cout << "A::A()" << endl; }

	void display()
	{
		cout << "A::display() " << endl;
	}
};

class B
{
public:
	B() {	cout << "B::B()" << endl; }
	
	void print()
	{
		cout << "B::print()" << endl;
	}
};

class C
{
public:
	void show()
	{
		cout << "C::show() " << endl;
	}
};

class D
:public A
,public B
,public C
{
	
};
int main(void)
{
	D d;
	d.display();
	d.B::print();
}
