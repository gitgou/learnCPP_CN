 ///
 /// @file    multiset.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-21 18:54:11
 ///
#include<math.h>
#include<set>
#include <iostream>
using std::cout;
using std::endl;
using std::multiset;
using std::multiset;


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
	int array[19]= {1,2,3,3,1,6,7,4,8,1,4,2,3,6,5,7,1,5,8};
	multiset<int,std::greater<int>> numbers (array, array+19);//数组相当于迭代器
	display(numbers);

	//find()
	multiset<int>::iterator it = numbers.find(8);
	
	cout << *it << endl;
	//insert

	cout << endl << endl << "测试范围查找元素" << endl;
	auto it1 = numbers.lower_bound(3);
	auto it2 = numbers.upper_bound(3);
	while(it1 != it2)
	{
		cout << *it1 << " " ;
		++it1;
	}
	cout << endl << "equal_range :" << endl;
	std::pair<multiset<int>::iterator, multiset<int>::iterator> it3 = numbers.equal_range(6);
	while(it3.first != it3.second)
	{
		cout << *it3.first << " ";
		++it3.first;
	}
	cout << endl << endl <<endl;
}

void test1()
{
	multiset<Point,std::greater<Point>> numbers {
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
	test0();
	test1();
	return 0;
}
