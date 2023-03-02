 ///
 /// @file    figure.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-29 21:27:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Figure
{
public: 

	virtual void display() = 0;

	virtual double area() = 0;
};

void display(Figure *figure)
{
	figure->display();
	cout << "'s area = " << figure->area() << endl;
}

class Rectangle
:public Figure
{
public:
	Rectangle(double length, double width)
	:_length(length)
	,_width(width)
	{}
	void display() override 
	{
		cout << "Rectangle" ;
	}
	double area() override 
	{
		return _length*_width;
	}

private:
	double _length;
	double _width;
};

class Cicle
:public Figure
{
public:
	Cicle(double r)
	:_radius(r)
	{}
	void display() override 
	{
		cout << "Cicle" ;
	}
	double area() override 
	{
		return _radius*_radius*PI;
	}

private:
	double _radius;
	const static double PI;
};
const double Cicle::PI = 3.1415926;
int main(void)
{
	Rectangle r(2,4);
	Figure * fig = &r;
	display(fig);

	Cicle c(2);
	Figure * fig1 = &c;
	display(fig1);
}
