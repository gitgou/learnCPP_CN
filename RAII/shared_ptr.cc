 ///
 /// @file    shared_ptr.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-27 10:52:52
 ///
 
#include <iostream>
#include<memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Point
{
public:

	Point(int x, int y)
	:_ix(x)
	,_iy(y)
	{
		cout << "Point(int x, int y)" << endl;
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
	shared_ptr<int> up(new int(10));//管理堆空间的指针
	cout << "*up " << *up << endl;
	cout << up.get() << endl; //返回对象地址
	cout << up.use_count() << endl;

	shared_ptr<int> up2(up) ;
	cout << up.use_count() << endl;
	cout << up2.use_count() << endl;

	shared_ptr<Point> pPoint(new Point(1,2));
	pPoint.get()->display();
	(*pPoint).display();
}
