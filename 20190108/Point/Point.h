#ifndef __POINT_H__
#define __POINT_H__


#include<iostream>
#include<string.h>

using std::cout;
using std::endl;

class Point
{
public:
	//还得显示实现，若仅声明会报错
    Point()
	:_ix(0)
	,_iy(0)
	{
	cout << " Point " << endl;
	}

	Point(int ix , int iy);
	
	void print();
	
	//析构函数	
	~Point()
	{
		cout<< " ~Point " << endl;
	}
private:
	int _ix;
	int _iy;

};

class Line
{
public:
	Line(int x1 ,int y1 , int x2 , int y2);
	
	void lineprint();
private:
	Point _pot1 ;
	Point _pot2 ;

};



#endif
