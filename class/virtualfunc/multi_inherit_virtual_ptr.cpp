#include <iostream>
using std::cout;
using std::endl;
class Base1
{
public:
	Base1()
	{
		cout << "Base1()" << endl;
	}
	virtual
	void display()
	{
		cout << "Base1::display()  _base = " << endl;
	}
private:
};

class Base2
{
public:
	Base2()
	{
		cout << "Base2()" << endl;
	}
	virtual
	void display2()
	{
		cout << "Base2::display()  _base = " << endl;
	}
private:
};
class Derived
:public Base1
,public Base2
{
public:
	Derived()
	{
		cout << "Derived()" << endl;
	}
	
	void display() //虚函数，覆盖
	{
		cout << "Derived::display() _derived = " << endl;
	}
	
	void display2() //虚函数，覆盖
	{
		cout << "Derived::display2() _derived = " << endl;
	}
private:
};

void display1(Base1 & base)
{
	base.display(); //同一指令对不同对象，产生不同的响应
}

void display2(Base2 & base)
{
	base.display2(); //同一指令对不同对象，产生不同的响应
}
int main(void)
{
	Base1 b;
	display1(b);

	Derived d;
	display1(d);
	display2(d);
	//Derived 中有两个虚指针，继承自Base1 & Base2
	std::cout << "sizeof(Derived): " << sizeof(Derived) << std::endl;
}
