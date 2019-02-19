 ///
 /// @file    Singleton.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-15 21:31:05
 ///
#include<pthread.h>//pthread_once 方法 +atexit()
#include<stdlib.h> //atexit()方法+饱汉模式
#include <iostream>


using std::cout;
using std::endl;

class Singleton
{
public:

	static Singleton * getInstance()
	{
		pthread_once(&_once , init);  //init只会执行一次
		return _pInstance;
	}

	static void init()
	{
		_pInstance = new Singleton();
		::atexit(destroy);
	}
	
	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
		cout << "void destroy()" << endl;
	}
private:
//	class AutoRelease
//	{
//	public:
//		AutoRelease()
//		{
//			cout << "AutoRelease()" << endl ;
//		}
//		~AutoRelease()
//		{
//			if(_pInstance )
//				delete _pInstance;
//			cout << "~AutoRelease()" << endl;
//		}
//	};
//

private:
	Singleton()
	{  cout << "Singleton()" <<endl ;}
	
	~Singleton()
	{
	   cout << "~Singleton()" << endl ;}

private:
	static Singleton * _pInstance;
	static pthread_once_t  _once;
//	static	AutoRelease _auto;
};
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;//默认
Singleton * Singleton::_pInstance = nullptr;
//Singleton::AutoRelease  Singleton::_auto ;
//静态数据成员需在外部定义
int main(void)
{
	Singleton * p1 = Singleton::getInstance(); 
}
