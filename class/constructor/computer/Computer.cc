#include"Computer.h"

#include<string.h>

#include<string>
#include<iostream>

using std::cout;

using std::endl;

float Computer::_totalprice = 0.0 ;

//在类外定义成员函数  
//系统提供的构造函数
Computer::Computer(const char *brand , float price)//第一个Computer是是类。第二个是构造函数
:_brand(new char[strlen(brand) + 1]())//使用new分配空间，使得brand指针可控
,_price(price)         // strlen 返回值不包括结束符，使用字符数组，空间可设定
{
	strcpy(_brand,brand); //复制字符串。且若_brand是指针不能对其赋值
	cout << " Computer " << endl;
}                         
////系统提供copy constructors 函数
////关于 const 与 & 两个问题需理解掌握
//Computer::Computer(const Computer  & rhs)
//: _brand(rhs._brand)
//,_price(rhs._price)
//{
//	cout << " Computer(const Computer & rhs)" << endl;
//}

//系统提供copy constructors 函数
//关于 const 与 & 两个问题需理解掌握, 自定义
Computer::Computer(const Computer  & rhs)
: _brand(new char [strlen(rhs._brand)+1]())
,_price(rhs._price)
{	
	strcpy(_brand , rhs._brand);
	cout << " Computer(const Computer & rhs)" << endl;
}

void Computer::setbrand(const char * brand)
{ // 先要判断替换字符串的长度，来开辟空间
	size_t len = strlen(_brand);
	if(len >= strlen(brand))
		strcpy (_brand , brand);
	else
	{	_brand = new char[strlen(brand) + 1]();
        strcpy(_brand , brand);
	}
}

void Computer::setprice(float price)
{
	_price = price ;
}
void Computer::print()
{
	cout << "cm'brand = " << _brand << endl;
	cout << "cm's price = " << _price <<endl;
	_totalprice += _price ;
	cout << "totalprice = "  <<_totalprice << endl;
}

//void Computer::printtotalprice()
//{
//	cout << _totalprice +
//}




