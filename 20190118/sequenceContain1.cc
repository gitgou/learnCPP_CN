 ///
 /// @file    sequenceContain1.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-20 20:51:27
 ///
 
#include <iostream>
#include<vector>
#include<deque>
#include<list>

using std::vector;
using std::deque;
using std::list;
using std::cout;
using std::endl;

template <class Contain>
void display(const Contain & c)
{
	for(auto & elem: c)
		cout << elem << " " ;
	cout << endl;
}

void test0()
{
	vector<int> number(10, 2);

	//迭代器
	vector<int>::iterator cit;

	cout << "vector-->  " << endl;
	cout << "number's size = "  << number.size() << endl;
	cout << "number's capacity = " << number.capacity() << endl;
	for(cit = number.begin(); cit != number.end(); ++cit)
		cout << *cit  << " ";
	cout << endl;
//	printf("&number.begin() = %p, &*number.begin() = % p" , number.begin(), &*number.begin());
	//for (auto & elem :number)
	//	cout << elem << " ";
	display(number);
	cout << endl << endl;
	
}
 
void test1()
{
	deque<int> number(10, 2);

	//迭代器
	deque<int>::iterator cit;
	cout << "deque --> " << endl;
	cout << "number's size = "  << number.size() << endl;
	//cout << "number's capacity = " << number.capacity() << endl;
	for(cit = number.begin(); cit != number.end(); ++cit)
		cout << *cit  << " ";
	cout << endl;
	//for (auto & elem :number)
	//	cout << elem << " ";
	display(number);
	cout << endl << endl;;
	
}
void test2()
{
	list<int> number  {5,2,3,6,7,1,1,3,5,3,4,9,8};

	number.unique();
	display(number);
	//迭代器
	list<int>::iterator cit ;
	cout << "list --> " << endl;
	cout << "number's size = "  << number.size() << endl;
	//cout << "number's capacity = " << number.capacity() << endl;
	for(cit = number.begin(); cit != number.end(); ++cit)
		cout << *cit  << " ";
	cout << endl;
	//for (auto & elem :number)
	//	cout << elem << " ";
	display(number);
	cout << endl << endl;;
	number.sort(std::greater<int>());
	number.unique();
	display(number);
}
int main(void)
{
	test0();
	test1();
	test2();
	return 0;
}
