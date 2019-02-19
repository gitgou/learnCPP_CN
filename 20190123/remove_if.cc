 ///
 /// @file    remove_if.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-30 15:42:35
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::ostream_iterator;
using std::vector;
using std::remove_if;
using std::cout;
using std::endl;
 
int main(void)
{
	vector<int> numbers{3, 1, 5, 6, 9, 8, 7,2,0};

	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(cout, " "));

	cout << endl;
	//auto it = remove_if(numbers.begin(), numbers.end(), [](int number){
	//		return number > 4; });
	std::less<int> lt;//比较器对象
	auto it = remove_if(numbers.begin(), numbers.end(), std::bind1st(lt, 4));
	numbers.erase(it, numbers.end());
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;
}
