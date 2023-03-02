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
//只能生成堆对象
class Student
{
public:
	Student(int id , const char * name )
	:_id(id)
	,_name(new char[strlen(name) + 1]()) 
	{
		strcpy(_name , name);
		cout << " Student() " << endl ;
	}

//	~Student()
//	{
//		delete [] _name;
//		cout << " ~Student() " << endl; 
//	}
//	//自定义new函数
//	void * operator new (size_t size)
//	{
//		cout << " void * operator new(size_t) " << endl;
//	   void  * pstr = malloc( size );
//		return pstr;
//	}
	
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

	void destroy()
	{
		delete this;
	}

	void print()
	{
		cout << "Student's name " << _name <<endl;
	}
private:
	int _id ;
	char * _name;

	~Student()
	{
		delete [] _name;
		cout << " ~Student() " << endl; 
	}
	//自定义new函数
//	void * operator new (size_t size)
//	{
//		cout << " void * operator new(size_t) " << endl;
//	   void  * pstr = malloc( size );
//		return pstr;
//	}
};

int main(void)
{
	//Student s2(101,"xiaohong");
	Student * s1 = new Student(100,"xiaoming");
	s1->print();
//i	delete s1;
	s1->destroy();
	return 0 ; 
}





