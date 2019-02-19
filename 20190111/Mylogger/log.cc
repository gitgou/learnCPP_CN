 ///
 /// @file    log.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-19 19:50:12
 ///
#include<log4cpp/Category.hh>
#include <iostream>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
using std::cout;
using std::endl;
using namespace log4cpp;
void test()
{
	//日至记录器
	Category & myCat = Category::getRoot().getInstance("myCat");
	
	//控制日志输出格式,开辟堆空间存放PatternLayout对象
	PatternLayout * patternLayout1 = new PatternLayout();
	patternLayout1->setConversionPattern("%d %c [%p] %m%n");
	
	PatternLayout * patternLayout2 = new PatternLayout();
	patternLayout2->setConversionPattern("%d %c [%p] %m%n");
	//%d time %c Category %p Priority  %m message %n 换行
	
	// 指定日志输出的目的地，标准输出或者文件
	OstreamAppender * ostreamAppender = new OstreamAppender("console" , &cout);
    ostreamAppender->setLayout(patternLayout1);//每个Appender对应一个Layout 
	
	//输出到文件 
	FileAppender * fileAppender = new FileAppender("fileAppender" , "yll.log");
	fileAppender->setLayout(patternLayout2);
	//日志记录器设置
	myCat.setPriority(Priority::WARN);
	myCat.addAppender(ostreamAppender);
	myCat.addAppender(fileAppender);

	//执行记录日志的操作
	myCat.emerg("this is an emerg message");
	myCat.fatal("this is an fatal message");
	myCat.alert("this is an alert message");
	myCat.error("this is an error message");
	myCat.info("this is an info message");
	myCat.debug("this is an debug message");
	myCat.notice("this is an notice message");
	myCat.warn("this is an warn message");
}
int main(void)
{
	test(); 
}
