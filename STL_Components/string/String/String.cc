#include"String.h"

#include<stdio.h>

#include<vector>
#include<limits>
#include<iostream>
#include<ostream>
#include<istream>
#include<string.h>

using std::cout;
using std::endl;

	//无参构造函数
String::String()
	{
		_str = NULL; 
		//空指针的逻辑地址位于空指针赋值区域，没有和物理地址对应
		//故无法寻址，对其访问会导致程序崩溃。野指针可能会超出寻址范围
		//导致程序崩溃。
		cout << " String() " << endl;
	}
	
	//自定义构造函数
String::String(const char * str)
	:_str(new char[strlen(str) + 1]()) //使得可控
	{ 
		strcpy(_str , str);
		cout << " String(const char * pstr) " << endl;
	}

	//复制构造函数
String::String(const String & rhs)
	:_str(new char[strlen(rhs._str) + 1]())
	{
		strcpy(_str , rhs._str);
		cout << " String(const String & rhs) " << endl;
	}

	//赋值运算符成员函数
String & String::operator=(const String & rhs)
{
	//this指针指向对象
	if (this != &rhs)
	{
		delete [] _str; //清空间
		_str = new char[(strlen(rhs._str) + 1)]();
		strcpy(_str , rhs._str);
	}
	cout << " operator(const String & rhs) " << endl;
	return *this; //返回值，保证连续赋值有效
}
//
String & String::operator=(const char * str)
{ //需返回引用，否则会调用赋值构造函数
	if(this->_str != str)
	{
		delete [] _str;
		_str = new char[strlen(str) + 1]();//使可控
		strcpy(_str , str); //深拷贝
	}
	cout << "String::operator=(const char *)" << endl ;
	return *this; //this指针指向对象。取this指向的内容
}

//
String & String::operator+=(const String & rhs)
{
	size_t lenth = size() + rhs.size() + 1;
	
	//delete [] _str;
	char * tmp = new char[lenth]();//开空间
	strcpy(tmp , _str);//深拷贝
	strcat(tmp, rhs._str);
	cout << "tmp = " << tmp <<endl;
	delete [] _str;
	_str = new char[lenth]();
	strcpy(_str, tmp);
	delete [] tmp;
	cout << "String & String::operator+=(const String & rhs)" << endl;
	return *this;
}
// +=字符串
String & String::operator+=(const char * str)
{
	size_t lenth = size() + strlen(str) + 1;
	char * tmp = new char[lenth]();//开空间
	strcpy(tmp, _str);
	strcat(tmp, str);
	delete [] _str;
	_str = new char[lenth]();
	strcpy(_str , tmp);
	delete [] tmp;
	cout << "String::operator+=(const char *)" << endl;
	return *this;
}
//可修改，写操作
char & String::operator[](size_t index)
{
	if(index < size())
	{
		cout << "char & operator[](size_t index)" <<endl;
		return _str[index];
	}
	else
	{
	static char  charnullptr = '\0';
	cout << "char & operator[](size_t index)" <<endl;
		return  charnullptr;
	}
}
//const ，只读
const char & String::operator[](size_t index) const 
{
	if(index < size())
	{
		cout << "operator[](size_t ) const" << endl;
		return _str[index];
	}
	else
	{
	static char  charnullptr = '\0';  //返回引用需定义为全局变量。
		cout << "operator[](size_t ) const" << endl;
		return  charnullptr;
	}
}
//
size_t String::size() const 
{
//	cout << "size_t size()" << endl;
	return strlen(_str);
}
//
const char* String::c_str() const 
{
	cout<< "char * c_str() " << endl;
	return _str;
}
//以友元函数形式重载, 不能加上String类作用域，因为是外部函数
bool operator==(const String & lhs, const String & rhs)
{
	cout << "bool operator==(lhs , rhs)" <<endl;
	if(strcmp(lhs._str , rhs._str) == 0)
		return true ;
	else
		return false ;
}
bool operator!=(const String & lhs, const String & rhs)
{
	cout << "bool operator!=(lhs , rhs)" <<endl;
	if(strcmp(lhs._str , rhs._str) != 0)
		return true ;
	else
		return false ;
}

bool operator<(const String & lhs, const String & rhs)
{
	cout << "bool operator<(lhs , rhs)" <<endl;
	if(strcmp(lhs._str , rhs._str) < 0)
		return true ;
else
		return false ;

}
bool operator>(const String & lhs, const String & rhs)
{
	cout << "bool operator<(lhs ,rhs)" << endl ;
	if(strcmp(lhs._str , rhs._str) > 0)
		return true ;
	else
		return false ;
}
bool operator<=(const String & lhs, const String & rhs)
{
	cout << "bool operator<=(lhs ,rhs)" << endl ;
	if((strcmp(lhs._str , rhs._str)) < 0 || (strcmp(lhs._str , rhs._str) == 0))
		return true ;
	else
		return false ;

}
bool operator>=(const String & lhs, const String & rhs)
{
	cout << "bool operator>=(lhs ,rhs)" << endl ;
	if((strcmp(lhs._str , rhs._str) > 0) || (strcmp(lhs._str , rhs._str) == 0))
		return true ;
	else
		return false ;

}
//
//
std::ostream & operator<<(std::ostream & os, const String & s)
{
	if(s._str != nullptr)
		os << s._str << endl ;
	else 
		os << std::string() << endl; //返回空串
	return os ;
}
//读输入值 ,字符串输入时有问题？？
void readString(std::istream & is ,String & rhs)
{
	if(rhs._str)
		delete [] rhs._str ;
	char  ch ;
	std::vector<char> buffer;   //缓冲
	while((ch = is.get()) != '\n')//输入字符串的方法
	{
		buffer.push_back(ch);
	}
	
	rhs._str = new char[buffer.size()+ 1]();  //需要开空间，_str就是字符串指针
	strncpy(rhs._str , &buffer[0] , buffer.size());//传入参数都是字符型指针。
	cout << "& buffer " << &buffer << endl;
	cout << "& buffer[0] " << &buffer[0] << endl;
	cout << sizeof(&rhs._str) << endl;
//	while(is >> rhs._str , !is.eof())
//	{
//		if(is.bad())
//			cout << "the istream is broken " << endl ;
//		else if (is.fail())
//		{
//			is.clear();
//			is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//			cout << "pls input valid string" << endl;
//		}
//		break;
//	}
//	cout << rhs._str<<endl;
}
//左操作数为流对象，右操作数为输入内容.所以修改的为rhs,需使用引用。
std::istream  & operator>>(std::istream & is,  String & rhs)
{
	readString(is ,rhs);//cin << 输入到某个变量中，operator>> 重载了我们自定义类型的
	//内置类型的数据，标准库已经实现了重载函数。cin,cout是标准库提供的输入输出对象。
	//is >> rhs._str ;
	return is;
}
//
//析构函数
String::~String()
	{
		delete [] _str;
		cout << " ~String() " << endl;
	}

	//打印函数
void String::print() const
	{	
		printf("_pstr's address = %p\n",_str);
		if(_str)
		cout << " pstr = " << _str <<endl;
	}


//不能返回引用。返回局部变量
String operator+(const String & lhs , const String & rhs)
{
	cout << "operator+(lhs , rhs)" << endl;
	char * tmp = new char[lhs.size() + rhs.size() + 1](); 
	strcpy(tmp , lhs._str);
	strcat(tmp , rhs._str);
	return String(tmp);
}

String operator+(const String & lhs , const char * str)
{
	cout << "operator+(lhs , const char *)" << endl;
	char * tmp = new char[lhs.size() + strlen(str) + 1](); 
	strcpy(tmp , lhs._str);
	strcat(tmp , str);
	return String(tmp);
}
String operator+(const char * str, const String & rhs)
{
	cout << "operator+(const char * , rhs)" << endl;
	//String * tmp = new String();  //在堆区开辟内存 开空间的大小不确定，所以不能用。
	char * tmp = new char[rhs.size() + strlen(str) + 1](); 
	strcpy(tmp , str);
	strcat(tmp , rhs._str);
	return String(tmp);
}
