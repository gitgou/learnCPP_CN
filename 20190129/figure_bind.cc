 ///
 /// @file    figure.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-29 21:27:18
 ///
 
#include <iostream>
#include <functional>
using std::bind;
using std::function;
using std::cout;
using std::endl;
class Figure
{
public: 
	using DisplayCallback = function<void()>; //函数类型(对象)
	using AreaCallback = function<double()>;
	
	//function类的复制控制函数定义了右值引用形式
	void setDisplayCallback(DisplayCallback && cb)
	{
		_displayCallback = cb;
	}

	void setAreaCallback(AreaCallback && cb)
	{
		_areaCallback = cb;
	}
	void handleDisplay()
	{
		if(_displayCallback)
			_displayCallback();
	}

	double handleAreaCallback()
	{
		if(_areaCallback)
			return _areaCallback();  //使用bind绑定参数后，可以直接回调无参类型
		else 
			return 0;
	}
	
	
	DisplayCallback _displayCallback;
	AreaCallback _areaCallback;
	//virtual double area() = 0;
};


class Rectangle 
{
public:
	Rectangle(double length, double width)
	:_length(length)
	,_width(width)
	{}
	void display() 
	{
		cout << "Rectangle" ;
	}
	double area()  
	{
		return _length*_width;
	}

private:
	double _length;
	double _width;
};

class Cicle 
{
public:
	Cicle(double r)
	:_radius(r)
	{}
	void display()
	{
		cout << "Cicle" ;
	}
	double area()
	{
		return _radius*_radius*PI;
	}

private:
	double _radius;
	const static double PI;
};
const double Cicle::PI = 3.1415926;
void display(Figure &figure)
{
	figure.handleDisplay();
	cout << "'s area = " << figure.handleAreaCallback() << endl;
}
int main(void)
{
	Rectangle r(2,4);
	Cicle c(2);
	Figure figure;
	figure.setDisplayCallback(std::bind(&Rectangle::display, &r)); //成员函数传入一个对象指针
	figure.setAreaCallback(std::bind(&Rectangle::area, &r)); //成员函数传入一个对象指针
	display(figure);
	return 0;
}
