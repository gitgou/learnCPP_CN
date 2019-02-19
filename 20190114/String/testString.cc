#include"String.h"


#include<iostream>
#include<string.h>
using std::cin;
using std::cout;
using std::endl;

void test()
{
	String s1("hello");
	s1.print();

	String s2("world");
	s2.print();

	String s3 = s1;
	cout << "s3 = s1 " << endl ;
	s3.print();

	// s3+= s2;
	s3 += "world";
	cout << "s3 += s2 :" << endl;
	s3.print();
	
	String s4("hello"); //const对象只能调用const成员函数
	 // s4[]
	//cout << "s4[0] = " << s4[10] <<  endl;
	for (size_t idx = 0 ; idx < s4.size() ; ++idx)
		cout << s4[idx] << endl;
	s4[0] = 'H';
	cout << "s4[0] = " << s4[0] <<endl;
}
void testBool()
{
	String s1("hello");
	String s2("world");
	String s3("hello");
	//operator ==
	cout <<"s1 是否等于 s3 ?  " << ( s1 == s3) << endl;
	//operator !=
	cout <<"s1 不等于 s2 ?  " << ( s1 != s2) << endl;
	//operator <
	cout <<"s1 > s2 ?  " << ( s1 > s2) << endl;
	//operator >
	cout <<"s1 <  s2 ?  " << ( s1 < s2) << endl;
	//operator <=
	cout <<"s1 <= s2 ?  " << ( s1 <= s2) << endl;
	cout << "s1 <= s3 ?  " << (s1 >= s3) << endl;
	//operator >=
	cout << "s1 >= s2 ?  " << (s1 >= s2) << endl;
	cout << "s1 >= s3 ?  " << (s1 >= s3) << endl;
}

void testadd()
{
	String s1("hello");
	String s2("world");
	String s3;
	//cout << "s1+s2 = "<< (s1 + s2) << endl;
	//s3 = s1 + s2;
	//s3.print();
	s3 = "world!" + s1;
	s3.print();

}

void testIOstream()
{
	String s1("123");//需要分配内存，栈内存会被收回。
	cin >> s1;
	cout << s1 << endl;
	//cout << sizeof(s1._str) << endl;
}

void testchar()
{
	const char * s1 = "I LOVE CHINA!";
	char s2[10] = "I LOVE";
	//sizeof(s1);
	cout << "s1 a = " << sizeof(s1 + 1) << endl;
	printf("s1 's address = %p  , %p\n",s1,s1+1);
	cout << "s2 a = " << sizeof(s2) << endl;
	printf("s1 's address = %p  , %p\n",s2,s2+1);
}
int main()
{
	//test();	
	//	testBool();
    //testadd();
	//testIOstream();
	testchar();
	return 0;
}
