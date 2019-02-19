 ///
 /// @file    Cicle.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-29 09:10:44
 ///
 
#include<math.h>
#include <iostream>
using std::cout;
using std::endl;

#define PI 3.1415926 
class Cicle
{
public:
	Cicle()
	:_radius(0)
	{
		cout << "Cicle()" << endl;
	}

	Cicle(double r)
	:_radius(r)
	{
		cout << "Cicle(double r)" << endl;
	}

	//面积
	double getArea()
	{
		return pow(_radius, 2)*PI ;
	}
	//周长
	double getPerimeter()
	{
		return 2*PI*_radius ;
	}

	void show()
	{
		cout << "Cicle's radius = " << _radius <<endl 
			 << "Cicle's Area = " << getArea() << endl
			 << "Cicle's Perimeter = " << getPerimeter() << endl;
	}
	~Cicle() {	cout << "~Cicle()" << endl; }
private:
	double _radius;
};

class Cylinder
:public Cicle
{
public:
	Cylinder(double r, double h)
	:Cicle(r)
	,_high(h)
	{
		cout << "Cylinder(double double)" << endl;
	}

	double getVolume()
	{
		return getArea()*_high;
	}
	void show()
	{
		cout << "Volume = " << getVolume() << endl;
	}
private:
	double _high;
};
int main(void)
{
	Cicle c1(2);
	c1.show();

	cout << "---圆柱---" << endl;
	Cylinder v1(2,2);
	v1.Cicle::show();
	v1.show(); //隐藏
}

