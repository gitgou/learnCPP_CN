#include"String.h"


#include<iostream>
#include<string.h>

using std::cout;
using std::endl;


int main()
{
//	String s1("123");
//	cout << "s1 : " <<endl ;
//	s1.print();
//	String s3 = s1;
//	cout << "s3 : " << endl ;
//	s3.print();
//	cout << "s3.refcount() = " << s3.refcount() << endl ;
//	cout << "s3 :" << endl ;
//	String s4("456");
//	cout <<  "s4.refcount() = "<<s4.refcount() << endl ;
//	cout << "s4 " << endl ;
//	s4.print();
//	s4 = s1;
//	cout << "s4 " << endl ;
//	s4.print();
//	cout << "s3.refcount() = " << s3.refcount() << endl ;
//	cout << "s4.refcount() = " << s4.refcount() << endl ;

//	printf("s1's address = %p\n",s1._pstr);
//	printf("s3's address = %p\n",s3._pstr);
	//s1.~String();
    //String s2;
	//s2.print();
	//s2.~String();
	String s1("hello");
	String s2 = s1;
	cout << "s2 = " << s2 <<endl;
	String s3;
	s3 = s1;
	cout << "s3 = " << s3 << endl ;
	cout << "s3.refcount() = " << s3.refcount() << endl;
	String s4 ;
	s4 = s3;
	cout << "s4 = " << s4 << endl ;
	cout << "s4.refcount() = " << s4.refcount() << endl;
	s4[0] = 'H';
	cout << "s4 = " << s4 << endl ;
	cout << "s4.refcount() = " << s4.refcount() << endl;
	cout << "s3 = " << s3 << endl ;
	cout << "s3.refcount() = " << s3.refcount() << endl;
	cout << "s3[0] = " << s3[0] << endl;
	cout << "s3 = " << s3 << endl ;
	cout << "s3.refcount() = " << s3.refcount() << endl;
	return 0;
}
