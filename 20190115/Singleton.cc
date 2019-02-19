 ///
 /// @file    Singleton.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-15 21:31:05
 ///

#include<stdlib.h> //atexit()方法
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:

	static Singleton * getInstance()
	{
		if(nullptr == _pInstance)
		{
			_pInstance = new Singleton();
			atexit(Singleton::destroy);  //atexit 中参数不用带().
		}
		return _pInstance;
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
//	static	AutoRelease _auto;
};
Singleton * Singleton::_pInstance = nullptr;
//Singleton::AutoRelease  Singleton::_auto ;
//静态数据成员需在外部定义
int main(void)
{
	Singleton * p1 = Singleton::getInstance(); 
}
