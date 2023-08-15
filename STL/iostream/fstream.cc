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
using std::fstream;
using std::cin;
using std::cout;
using std::endl;

int number = 0 ;
void test0()
{
	
	cin >>  number ;
	cout << "number = " << number << endl;
}

void PrintStreamStatus(fstream & fs )
{
	cout << "fs.bad = " << fs.bad() <<endl;
	cout << "fs.fail = " << fs.fail() <<endl; 
	cout << "fs.eof = " << fs.eof() <<endl; 
	cout << "fs.good = " << fs.good() <<endl; 
}

void test2()
{
	//printstatus();
	test0();
	//printstatus();
    
	cin.clear(); //重置cin的状态
	cin.ignore(1024 , '\n');// 清空缓冲区，第一个参数字节数
	                 //第二个参数清空结尾标志

	string s1;
	cin >> s1 ;
	cout << "s1 = " << s1 << endl ; 
    //	printstatus();


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
		vstr.push_back(std::move(str));//放入容器
	}
		
	int vstr_size = vstr.size();
	for(int index = 0 ; index < vstr_size ; ++index )
	{
		//vstr.pop_back();
	    cout << vstr[index] << endl;
	}

	 ifs.close();  //注意手动关闭文件
}

void TestFstream()
{
	fstream fs("test.txt");
	if(!fs.good()) 
	{
		cout << "open file fail " << endl;
		return ;
	}
	int number = 0;
	size_t pos = 0;
	//输出文件
	for (size_t index = 0 ; index < 5 ; ++index)
	{
		cin >> number ;
		PrintStreamStatus(fs);
	    cout <<endl;
		pos = fs.tellg();
	    cout << "pos = " << pos << endl ;
		fs << number << " " ;
	} //输出到末尾是。游标指向末尾

	cout << "pos = " << pos <<endl;
	//PrintStreamStatus(fs);
	fs.seekg(0);//绝对偏移
	//fs.seekg(std::ios::end);
	//输入文件流
	for(size_t index = 0; index < 5 ; ++index)
	{
		fs >> number ;
		cout << endl;
		//PrintStreamStatus(fs);
		cout << number << endl;
	}
	fs.close();
	//PrintStreamStatus(fs);
}
int main(void)
{
	//	test2();
    //	test3();
	//testIfstream();
	TestFstream();
	return 0; 
}
