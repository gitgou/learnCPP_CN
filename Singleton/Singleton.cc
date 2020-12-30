 ///
 /// @file    Singleton.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-10 20:28:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point 
{
public:
	
	Point(int ix = 0, int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point() " << endl;
	}

	~Point()
	{
		cout << "~Point() " << endl;
	}
	friend std::ostream &  operator<<(std::ostream & os , const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream &  operator<<(std::ostream & os , const Point & rhs)
{
	os << "("
	   << rhs._ix 
	   << ","
	   << rhs._iy
	   << ")" ;
	return os;
}
//单例模式，只能生成一个对象
//使用static 类型可以不创建对象调用类的成员函数
template <class T>
class Singleton
{
public:
//    Singleton()
//	
//	   cout << "Singleton ()" << endl;
//	
//	Singleton()
//	
//	   cout << "~Singleton ()" << endl;
    //提供可变参数列表	
	template <class ...Args>
    static T *  getInstance(Args... args)
	{
		if(nullptr == _ptr)
		{
			_ptr = new T(args...);
		}
		return _ptr ;
	}

	static void distory()
	{
		if(_ptr)
			delete _ptr ;
	}

	

	static T * _ptr;
    Singleton()
	{
		cout << " Singleton()" << endl;
	}
	~Singleton()
	{
		
		cout << "~Singleton ()" << endl;
	}
};

template <class T>
T * Singleton<T>::_ptr ;

int main(void)
{
	Point * ptr1 = Singleton<Point>::getInstance(1);
	cout << ptr1 << endl;
	Point * ptr2 = Singleton<Point>::getInstance(3,4);
	cout << ptr2 << endl;
	cout << *ptr2 << endl;
    Singleton<Point>::distory() ;
	return 0;
}



