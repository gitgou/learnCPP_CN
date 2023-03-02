#include"Computer.h"

#include<iostream>
#include<string.h>

using std::cout;
using std::endl;

void test()
{
	Computer cm1("Lenovo thinkpad ",6666) ;
    Computer  cm2 = cm1;
    cout << "修改前的：" << endl;
	cm1.print();
	cm2.print();
	cm1.setbrand(" xiaomi ");
    cm1.setprice(8888);
	cout << " 修改后的：" << endl;
	cm1.print();
    cm2.print();
}

int main()
{
    //	test();
	Computer cm3("lenovo",8888) ;
	Computer cm4 ("huawei", 6666);
	cm3.print();
	cm4.print();
	return 0;

}
