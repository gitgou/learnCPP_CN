 ///
 /// @file    VariadicTemplate.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-18 20:25:22
 ///
 
#include <iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

void display()
{
	cout << endl;
}


template <class T ,class... Args >
void display(T t, Args... args)
{
	cout << t << " ";
	display(args...); //当...在函数参数包右边时，表示展开参数包
	//cout<< sizeof...(args) << endl;
}

void test0()
{
	string s1 = "hello";
	display();
	display(1, 2.2);
	display(1 ,2 , 'a');
	display(1, 2, 'a', s1);
	
}

int main(void)
{
	test0();
	return 0;
}
