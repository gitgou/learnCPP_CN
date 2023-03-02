 ///
 /// @file    Student.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-10 22:58:18
 ///
#include<string.h> 

#include<string>
#include <iostream>
using std::cout;
using std::endl;

//只能生成栈对象
//
class Student
{
public:
	//只有自定义类型才有构造函数和析构函数
	Student(int id , const char * name )
	:_id(id)
	,_name(new char[strlen(name) + 1]()) 
	{
		strcpy(_name , name);
		cout << " Student() " << endl ;
	}

	~Student()
	{
		delete [] _name;
		cout << " ~Student() " << endl; 
	}
private:
	//自定义new函数,开辟内存空间
	//new和delete运算符执行顺序相反
	void * operator new (size_t size)
	{
		cout << " void * operator new(size_t) " << endl;
	   void  * pstr = malloc( size );
		return pstr;
	}
	
	//自定义delete函数
	void operator delete(void * pstr)
	{
		free(pstr);
		cout << "void operator delete(void * pstr) " << endl ;
	}

private:
	int _id ;
	char * _name;

};

int main(void)
{
 // Student * s1 = new Student(100,"xiaoming"); //error
	Student s2(101,"xiaohong");
//	delete s1;//error
	return 0; 
}





