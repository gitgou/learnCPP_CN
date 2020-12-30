 ///
 /// @file    deleter.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-27 12:27:39
 ///
 
#include <iostream>
#include<memory>
using std::cout;
using std::endl;
using std::unique_ptr;
struct FilePointCloser
{
	void operator()(FILE * fp)
	{
		if(fp)
		{
			fclose(fp);
			cout << "fp.close()" << endl;
		}
	}
};
void test0()
{
	//std::deleter 默认删除器，struct型。可以自己构造deleter
	unique_ptr<FILE , FilePointCloser> up(fopen("test.txt", "w"));
	
	fwrite("helloworld!", 1,11,up.get());
}
 
int main(void)
{
	test0();
	return 0;
}
