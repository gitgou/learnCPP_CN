 ///
 /// @file    mutilDerived1.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-28 19:52:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//二义性
class A
{
public:
	A():_ia(0)	{cout << "A::A()" << endl; }

	void display()
	{
		cout << "A::display() " << endl;
	}
private:
	int _ia;
};

class B
:public A
{

};

class C
:public A
{

};
class D
:public B
,public C
{
	
};
int main(void)
{
	D d;
	d.B::display();
}
