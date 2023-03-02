 ///
 /// @file    io1.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-11 20:36:12
 ///
 
#include <iostream>
#include<string.h>
#include<limits>
#include<fstream>
#include<vector>

using std::vector;
using std::ifstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int number = 0 ;
void test0()
{
	
	cin >>  number ;
	cout << "number = " << number << endl;
}

void printstatus()
{
	cout << "cin.bad = " << cin.bad() <<endl;
	cout << "cin.fail = " << cin.fail() <<endl; 
	cout << "cin.eof = " << cin.eof() <<endl; 
	cout << "cin.good = " << cin.good() <<endl; 
}

void test2()
{
	printstatus();
	test0();
	printstatus();
    
	cin.clear(); //重置cin的状态
	cin.ignore(1024 , '\n');// 清空缓冲区，第一个参数字节数

	string s1;
	cin >> s1 ;
	cout << "s1 = " << s1 << endl ; 
	printstatus();


}

void test3()
{   //逗号表达式。最后一个数有效
	while(cin >> number , !cin.eof())
	{
		cout << " number = " << number << endl;
		cin.clear(); //重置cin的状态
		cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n');// 清空缓冲区，第一个参数字节数
	}
}
void testIfstream()
{
	 ifstream ifs; //声明对象
	 ifs.open("io2.cc"); //打开文件
	 //判断输入流状态是否正确
	 if(!ifs.good())
	{
		cout << "cannot open this file !" << endl;
		return ;  //直接返回
	}
	 string str;
	 vector<string> vstr;
	// while(ifs >> str , !ifs.eof())//输入文件流
	while(getline(ifs , str))
	{
		vstr.push_back(std::move(str));//放入容器 std::move -- 移动语义，后续会学
	}
		
	int vstr_size = vstr.size();
	for(int index = 0 ; index < vstr_size ; ++index )
	{
		//vstr.pop_back();
	    cout << vstr[index] << endl;
	}

	 ifs.close();  //注意手动关闭文件
}

int main(void)
{
	//	test2();
    //	test3();
	testIfstream();
	return 0; 
}
