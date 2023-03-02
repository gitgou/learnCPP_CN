 ///
 /// @file    Complex.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-14 18:57:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex 
{
public:
	Complex(double dreal , double dimag)
	:_dreal(dreal)
	,_dimag(dimag)
	{
		cout << "Complex(double , double)" << endl;
	}
	//运算符重载，必须是类类型或者枚举类型数据   成员函数形式重载
	Complex   operator+(const Complex & rhs)
	{ 
		cout << "Complex operator+(const Complex & rhs)" << endl ;
		return Complex(_dreal + rhs._dreal , _dimag + rhs._dimag);
	}
	//+= 运算符重载   
	Complex &  operator+=(const Complex & rhs)
	{	
		_dreal += rhs._dreal ;
		_dimag += rhs._dimag ;
		cout << "Complex operator+=(const Complex & rhs)" << endl;
		return *this ;
		//return Complex(_dreal+ rhs._dreal , _dimag + rhs._dimag);
	}

	//前置++
	Complex & operator++()
	{
		++_dreal;
		++_dimag;
		cout << "Complex & operator++()" << endl ;
		return *this;
	}

	//后置++
	Complex  operator++(int)
	{
		Complex tmp(*this);
		++_dreal;
		++_dimag;
		cout << "Complex & operator++()" << endl ;
		return tmp;
	}
	void print() const 
	{
		cout << " complex = " << _dreal 
			 << " + " << _dimag << "i" << endl;
	} 
	//普通友元函数
	friend Complex operator+(const Complex & lhs , const Complex & rhs);
private:
	double _dreal;
	double _dimag;
};

Complex operator+(const Complex & lhs , const Complex & rhs)
{
	cout << "Complex operator+(const Complex & lhs ,const Complex & rhs)" << endl;
	return  Complex(lhs._dreal + rhs._dreal ,lhs._dimag + rhs._dimag);
	//返回一个对象
}

//测试
void test()
{
	Complex c1(1,2);
	c1.print();
	Complex c2(3,4);
	c2.print();
	Complex c3 = c1 + c2 ;
	c3.print();
	c3 += c1;
	c3.print();
	++c3;
	c3.print();
	c1 = c3++;
	c3.print();
	c1.print();
}
int main(void)
{
	test();
}
