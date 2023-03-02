 ///
 /// @file    pureVirtualFunction.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-29 21:10:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Base
{
public:
	virtual 
	void display() = 0;

};

class Derived
:public Base
{
public:
	void display()
	{
		cout << "Derive::display()" << endl;
	}
};
int main(void)
{
	//Base b;//error//抽象类不能声明对象
	Derived d;
	Base *pb = &d;
	pb->display();
	return 0;
}
