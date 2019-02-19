 ///
 /// @file    set.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-21 18:54:11
 ///
#include<math.h>
#include<set>
#include <iostream>
using std::cout;
using std::endl;
using std::set;


template<class Contain>
void display(Contain & c)
{
	for(auto & elem: c)
		cout << elem << " ";
	cout << endl ;
}
class Point
{
public:
	Point(int ix , int iy)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int , int)" << endl;
	}
	double getInstance() const
	{
		return sqrt(_ix*_ix + _iy*_iy);
	}
	friend std::ostream & operator<<(std::ostream & os , const Point & rhs);
	friend bool operator<(const Point & lhs,const Point & rhs);
	friend bool operator>(const Point & lhs,const Point & rhs);//const对象只能调用const函数

private: 
	int _ix;
	int _iy;
};
bool operator<(const Point & lhs, const Point & rhs)
{
	if(lhs.getInstance() < rhs.getInstance())
		return true;
	else if(lhs.getInstance() == rhs.getInstance() &&  lhs._ix < rhs._ix)
		return true;
	else 
		return false;
}

bool operator>(const Point & lhs, const Point & rhs)
{
	if(lhs.getInstance() > rhs.getInstance())
		return true;
	else if(lhs.getInstance() == rhs.getInstance() &&  lhs._ix > rhs._ix)
		return true;
	else 
		return false;
}
std::ostream & operator<<(std::ostream & os , const Point & rhs)
{
	os << "("
	   << rhs._ix
	   << ","
	   << rhs._iy
	   << ")";
	   return os;
}

void test0()
{
	int array[10]= {1,4,2,3,6,5,7,1,5,8};
	set<int,std::greater<int>> numbers (array, array+10);//数组相当于迭代器
	display(numbers);

	//find()
	set<int>::iterator it = numbers.find(8);
	cout << *it << endl;

	//insert
	
}

void test1()
{
	set<Point,std::greater<Point>> numbers {
				Point(1,2),
				Point(1,-2),
				Point(2,3),
				Point(-2,5),
				Point(7,8)
	};
	display(numbers);
}
int main(void)
{
//	test0();
	test1();
	return 0;
}
