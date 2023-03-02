 ///
 /// @file    ostream_itreator.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-22 19:46:40
 ///
#include<vector>
#include<iterator>
#include <iostream>
#include<algorithm>

using std::copy;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ostream_iterator;
using std::istream_iterator;
void test()
{
	vector<int> vc{1, 2, 3, 4, 6, 5};
	
	ostream_iterator<int> osi(cout, " ");
	copy(vc.begin(), vc.end(),  osi);
	
}
void test1()
{
	vector<int> numbers;
	istream_iterator<int> iis(cin);
	ostream_iterator<int> osi(cout, " ");
	//输入到numbers中
	copy(iis, istream_iterator<int>(), std::back_inserter(numbers));

	//输出
	copy(numbers.begin(), numbers.end(), osi);
	
}
int main(void)
{
	//test();
	test1();
	return 0;
}
