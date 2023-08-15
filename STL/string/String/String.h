#ifndef __STRING_H__
#define __STRING_H__

#include<iostream>
#include<string.h>

using std::cout;
using std::endl;

class String
{
public:
	//无参构造函数
	String();

	//自定义构造函数
	String(const char * str);

	//复制构造函数
	String(const String & rhs);

	//赋值运算符成员函数
	String & operator=(const String & rhs);

	String & operator=(const char *str);

	// += 重载
	String & operator+=(const String & rhs);
	String & operator+=(const char * str);


	//
	char & operator[](size_t index);

	//
	const char & operator[](size_t index) const ;
	//
	size_t size() const ;
	//
	const char* c_str() const;

	friend bool operator==(const String & lhs, const String & rhs);
	friend bool operator!=(const String & lhs, const String & rhs);


	friend bool operator<(const String & lhs, const String & rhs);
	friend bool operator>(const String & lhs, const String & rhs);
	friend bool operator<=(const String & lhs, const String & rhs);
	friend bool operator>=(const String & lhs, const String & rhs);

	friend void readString(std::istream & is , String & rhs);
	friend std::ostream & operator<<(std::ostream & os, const String & s);
	friend std::istream & operator>>(std::istream & is,  String & s);

	friend String operator+(const String & lhs, const String & rhs);
	friend String operator+(const String & lhs, const char * str);
	friend String operator+(const char * str, const String & rhs);
	//析构函数
	~String();

	//打印函数
	void print() const ;

private:	
	char * _str;

};




#endif
