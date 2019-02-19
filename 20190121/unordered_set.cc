 ///
 /// @file    multiset.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-21 18:54:11
 ///
#include<math.h>
#include<unordered_set>
#include <iostream>
using std::cout;
using std::endl;
using std::unordered_set;


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

	int getX() const 
	{
		return _ix;
	}
	int getY() const
	{
		return _iy;
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
bool operator==(const Point & rhs, const Point & lhs) 
{
	if((rhs.getX() == lhs.getX()) && (lhs.getY() == rhs.getY()))
		return true ;
	else
		return false;
}
namespace std
{
template<> struct hash<Point>
{
	size_t operator()(const Point & pt) const
	{
		return (pt.getX()<< 1) ^ (pt.getY() << 1) ; 
		//此时计算会复制给临时变量，x,y右移一位再异或
	}
};
}//end of std
//自定义类类型  
struct Pointhash
{
	size_t operator()(const Point & pt) const
	{
		return (pt.getX()<< 1) ^ (pt.getY() << 1) ; 
		//此时计算会复制给临时变量，x,y右移一位再异或
	}
};
void test()
{
	unordered_set<Point,Pointhash> points{
		Point(1,2),
		Point(-1,2),
		Point(2,5),
		Point(4,3),
		Point(1,2),
		Point(-3,5)
	};
	display(points);
}
int main(void)
{
	test();
	return 0;
}
