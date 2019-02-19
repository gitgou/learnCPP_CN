 ///
 /// @file    bind.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-30 17:02:44
 ///
 
#include <iostream>
#include <functional>

using std::bind;
using std::cout;
using std::endl;

int add(int a, int b)
{
	return a+b;
}
 
void test0()
{
	auto f1 = bind(add, 1, 2);//返回一个无参函数 int()
	cout << "add() = " << f1() << endl;

	typedef int(*Function)(int, int);//()还是表示函数调用
	Function f2 = add;
	cout << "f2(1,2) = " << f2(1,2) << endl;
	
}
void show(int a, int b, int c, int d, int e)
{
	cout << "a = " << a << endl
		 << "b = " << b << endl
		 << "c = " << c << endl
		 << "d = " << d << endl
		 << "e = " << e << endl;
}

void test1()
{
	using namespace std::placeholders;
	int number = 100;
	auto f1 = bind(show, 10, _1, _2, std::cref(number), number);

	number = 1000;
	f1(20, 30);

	//cout << endl << endl;
	//number = 1000;
	//f1(20,30);
}

int main()
{
	//test1();
	using namespace std::placeholders;
	int number = 100;
	auto f1 = bind(show, 10, _1, _2, std::cref(number), number);

	number = 1000;
	f1(20, 30);
	return 0;
}
