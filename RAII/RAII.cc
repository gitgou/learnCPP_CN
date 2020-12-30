 ///
 /// @file    RAII.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-26 14:25:55
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template<class T>
class RAII
{
public:

	RAII(T * data)
	:_data(data)
	{
		cout << "RAII()" << endl;
	}

	T * operator->(){	return _data; }

	T & operator*(){	return *_data;}

	void reset(T *data)
	{
		if(_data)
			delete _data;
		_data = data;
	}
	T * get()
	{
		return _data;
	}

	~RAII()
	{
		if(_data)
			delete _data;
	}
private:
	T * _data;
};

class Point
{
public:
	Point(int x, int y)
	:_ix(x)
	,_iy(y)
	{
		cout << " Point()" << endl;
	}

	void display()
	{
		cout << "("
			 << _ix
			 << ","
			 << _iy
			 << ")" << endl;
	}
	
	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};
int main(void)
{
	RAII<Point> pPoint(new Point(1,2));
	pPoint->display();
	(*pPoint).display();
}
