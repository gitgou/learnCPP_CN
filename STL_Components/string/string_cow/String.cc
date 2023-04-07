#include"String.h"

#include<stdio.h>

#include<iostream>
#include<string.h>

using std::cout;
using std::endl;

	//无参构造函数
String::String()
	:_pstr((new char[4+1]())+4)//前4字节存放count
	{
	     //	_pstr = NULL; 
		//空指针的逻辑地址位于空指针赋值区域，没有和物理地址对应
		//故无法寻址，对其访问会导致程序崩溃。野指针可能会超出寻址范围
		//导致程序崩溃。
		initRefcount();
		cout << " String() " << endl;
	}
	
	//自定义构造函数
String::String(const char * pstr)
	:_pstr(new char[strlen(pstr) + 5]()+4) //使得可控
	{ 
		//_pstr =	pstr ;
		strcpy(_pstr , pstr);//自定义构造函数必须深拷贝
		initRefcount();
		cout << " String(const char * pstr) " << endl;
	}

	//复制构造函数
String::String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr) + 5]()+4)
	{
		_pstr = rhs._pstr;
		//strcpy(_pstr , rhs._pstr);
		increaseRefcount();
		cout << " String(const String & rhs) " << endl;
	}

	//赋值运算符成员函数
String & String::operator=(const String & rhs)
{
	//this指针指向对象
	if (this != &rhs)
	{
		decreaseRefcount();//原地址--
		release();
		++(*(rhs._pstr - 4));
		_pstr = rhs._pstr;
	}
	cout << " operator(const String & rhs) " << endl;
	return *this; //返回值，保证连续赋值有效
}

	//析构函数
String::~String()
	{	
		release();//对象销毁时只有count==0才被释放空间
		cout << " ~String() " << endl;
	}

	//下标运算符重载，修改
String::Charproxy String::operator[](size_t index)
{
	return String::Charproxy(*this , index);
}
//写操作，最后一定是返回char字符。防止连等情况出现，故operator[]运算符就是返回一个字符
char & String::Charproxy::operator=(const char & ch)
{
	if(_index < _self.size())
	{
		//大于1才需要深拷贝，否则直接赋值, 写时复制
		if(_self.refcount() > 1)
		{ //不需要考虑销毁，因为count 一定大于1.
			_self.decreaseRefcount();	
			char * temp = new char[_self.size()+5]() + 4;
			strcpy(temp , _self._pstr);
	 	    _self._pstr = temp;
			_self.initRefcount();
		}
		_self._pstr[_index] = ch;
		return _self._pstr[_index];
	}	
	else
	{
		static char charnullptr = '\0';
		return charnullptr;
	}
}
//读操作
std::ostream &  operator<<(std::ostream & os , const String::Charproxy & cp)
{
	os << cp._self._pstr[cp._index] ;
	return os;
}
//打印函数
void String::print()
	{	
		printf("_pstr's address = %p\n",_pstr);
		if(_pstr)
		cout << " pstr = " << _pstr <<endl;
	}	

std::ostream & operator<<(std::ostream & os , const String & rhs)
{
	os << rhs._pstr ;
	return os ;
}
