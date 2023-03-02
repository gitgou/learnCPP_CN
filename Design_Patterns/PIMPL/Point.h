#ifndef __POINT_H__
#define __POINT_H__


#include<iostream>

using std::cout;
using std::endl;

//设计模式：	PIMPL
class Line
{
public:
	Line(int x1 ,int y1 , int x2 , int y2);
	
	void lineprint();
	
	~Line();

	class LineImpl;//前向声明
private:
	LineImpl * _pimpl; //因为只给了前向声明，所以需定义为指针
};



#endif
