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

	~Student()
	{
		delete [] _name;
		cout << " ~Student() " << endl; 
	}
	//自定义new函数
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
	Student * s1 = new Student(100,"xiaoming");
	delete s1;
	return 0; 
}





