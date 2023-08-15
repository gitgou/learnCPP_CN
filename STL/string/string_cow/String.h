#ifndef __STRING_H__
#define __STRING_H__

#include<iostream>
#include<string.h>
#include<string>

using std::string;
using std::ostream;
using std::cout;
using std::endl;
// Cow  写时复制技术
//  
class String
{
public:
	//无参构造函数
	String();
	
	//自定义构造函数
	String(const char * pstr);

	//复制构造函数
	String(const String & rhs);

	//赋值运算符成员函数
	String & operator=(const String & rhs);

	size_t size()
	{
		return strlen(_pstr);
	}

	const char * c_str()
	{
		return _pstr;
	}

private:

	class Charproxy
	{
	public:

		Charproxy(String & self , size_t index)
		:_self(self)
		,_index(index)
		{
			cout << "Charproxy(String & , size_t ) " << endl ;
		}
	     //String .operator[] 返回一个Charproxy对象 ,后面重载的运算符是赋值和输出。
		char & operator=(const char & ch);		
		friend std::ostream &  operator<<( std::ostream & os , const String::Charproxy & cp);
	
	private:
		String & _self;
		size_t _index;
	};

public:
	//下标运算符重载，修改
	Charproxy  operator[](size_t index);
	//下标运算符重载，只读
    //	char & operator[](size_t index) const ;

	int refcount() const
	{
		return *(_pstr -4);  //返回引用值
	}

	friend std::ostream &  operator<<( std::ostream & os , const String::Charproxy & cp);
	friend std::ostream &  operator<<(std::ostream & os , const String & rhs);
	//析构函数
	~String();

	//打印函数
	void print();
private:
	void initRefcount()
	{
		*(int *)(_pstr-4) = 1; //转化为int型地址
	}

	void increaseRefcount()
	{
		++(*(_pstr -4));
	}

	void decreaseRefcount()
	{
		--(*(_pstr - 4));
	}
	
	void release()
	{
		if(refcount() == 0)
			delete [] (_pstr -4);
		cout << "void release ()" << endl;
	}
	
private:	
	char * _pstr;


};


#endif
