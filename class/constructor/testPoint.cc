#include"Point.h"

#include<iostream>
#include<string.h>

using std::cout;
using std::endl;


int main()
{
	Point p0; //不带参声明对象
	p0.print();
	Point p1(1,2);
	p1.print();

	Line line(1,2,3,4);
	line.lineprint(); 
	return 0;
}
