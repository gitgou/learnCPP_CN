#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include<iostream>
#include<string.h>

using std::cout;
using std::endl;

class Computer
{
public:
	//无参析构函数
	Computer(){};
	//构造函数
	Computer(const char * brand , float price);

	Computer(const Computer & rhs);

	void setbrand(const char * brand);

	void setprice(float price);

	void print();
	~Computer()
	{
		cout << "~Computer" << endl;
	}
private://封装
	
	char   *_brand;
	float  _price =8888;
	static float _totalprice ;
};

#endif
