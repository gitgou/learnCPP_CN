#include"Point.h"

#include<iostream>
#include<string.h>	

using std::cout;
using std::endl; 
//构造函数的实现和重载

Point::Point(int ix ,int iy)
:_ix(ix)  //真正的初始化，
,_iy(iy) //初始化中数据的顺序只与声明的顺序有关。
{	
	_ix = ix ;
	_iy = iy ;
	cout << " Point " << endl;
}

void Point::print()
{
	cout << "(" 
	     << _ix 
		 << ","
		 << _iy
		 << ")";
}

Line::Line(int x1 , int y1 , int x2 ,  int  y2 )
:_pot1(x1 , y1)
,_pot2(x2 , y2)
{
	cout << "Line(int x1 ,int y1 , int x2 , int y2)" << endl;
}

void Line::lineprint()
{	
	_pot1.print() ;
	cout << "--->"; 
	_pot2.print() ;
		cout << endl;
}




