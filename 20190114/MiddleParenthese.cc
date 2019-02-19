///
/// @file    MiddleParenthese.cc
/// @author  yll(1711019653@qq.com)
/// @date    2019-01-14 22:22:02
///

#include<string.h>
//#include<string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class CharArray
{
	public:
		CharArray( size_t size)
			:_data(new char[size + 1]())
			 ,_size(size)
	{
		cout << "CharArray(size_t)" <<endl;
	}

		~CharArray()
		{
			delete [] _data;
			cout << "~CharArray() " << endl;
		}

		size_t size()
		{
			return _size;
		}
		//使用引用使得返回值仍为字符串的值
		char & operator[](size_t idx)
		{ 
			if(idx < size())
				return _data[idx];
			else
			{
				static char charnullptr = '\0';
				return charnullptr;
			}
		}



	private:
		char * _data;
		size_t _size;

};

int main(void)
{  
	const char * str = "hello,world";
	printf("&(hello, world)= %p\n ", "hello,world");
	printf("str's address = %p\n", str);
	CharArray ca(strlen(str) + 1);

	for(size_t idx = 0; idx != ca.size(); ++idx) 
	{
		ca[idx] = str[idx];
	}

	for(size_t idx = 0; idx != ca.size(); ++idx) {
		cout << ca[idx] << "\n";	
	}
	return 0; 
}
