#include"Point.h"

#include<iostream>

using std::cout;
using std::endl; 

class Line::LineImpl
{
public:
	LineImpl(int x1 , int y1 , int x2 , int y2 )
	:_pot1(x1,y1)
	,_pot2(x2,y2)
	{
		cout << "LineImpl(int ,int ,int ,int)" << endl;
	}

	~LineImpl()
	{
		cout << "~LineImpl() " << endl ;
	}
	void PrintLineImpl()
	{
		_pot1.print();
		cout << " ---> ";
		_pot2.print();
	}
private:

class Point
{
public:
Point(int ix ,int iy)
:_ix(ix)  //真正的初始化，
,_iy(iy) //初始化中数据的顺序只与声明的顺序有关。
{	
	_ix = ix ;
	_iy = iy ;
	cout << " Point " << endl;
}

void print()
{
	cout << "(" 
	     << _ix 
		 << ","
		 << _iy
		 << ")";
}

private:
	int _ix ;
	int _iy;
};
	Point _pot1;
	Point _pot2;

};

Line::Line(int x1 , int y1 , int x2 ,  int  y2 )
:_pimpl(new LineImpl(x1, y1, x2, y2)) 
{	//new一个带参构造函数的内存空间
	cout << "Line(int x1 ,int y1 , int x2 , int y2)" << endl;
}

void Line::lineprint()
{	
	_pimpl->LineImpl::PrintLineImpl();
}

Line::~Line()
{
	delete _pimpl;
	cout << "~Line()" << endl;
}




