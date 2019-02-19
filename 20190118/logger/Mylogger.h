 ///
 /// @file    log.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-19 19:50:12
 ///
 
#ifndef __MYLOGGER_H__
#define __MYLOGGER_H__

#include<log4cpp/Category.hh>
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;
namespace yll
{

class Mylogger
{
public:
	enum Priority{
		WARN,
		ERROR,
		INFO,
		DEBUG 
	};
	static Mylogger * getMylogger();
 
	static void destroy();
	
	
	void setPriority(Priority p);
//	
//	void warn(const char * msg);
//
//	void error (const char * msg);
//	
//	void debug(const char * msg);
//	
//	void info(const char * msg);
//
	template <class T, class... Args >
	void warn(T  msg, Args... args);

	template <class T, class... Args >
	void error(T msg, Args... args);

	template <class T, class... Args >
	void debug(T msg, Args... args);

	template <class T, class... Args >
	void info(T msg, Args... args);
private:
	Mylogger();
	~Mylogger(); 
	log4cpp::Category & _myCat;
	static Mylogger * _mylogger;
};

template < class T ,class... Args >
void Mylogger::warn(T msg, Args... args)
{
	_myCat.warn(msg,args...);
}	

template <class T, class... Args >
void Mylogger::error(T msg, Args... args)
{
	_myCat.error(msg, args...); 
}

template <class T, class... Args >
void Mylogger::debug(T msg, Args... args)
{
	_myCat.debug(msg, args...); 
}

template <class T, class... Args >
void Mylogger::info(T msg, Args... args)
{
	_myCat.info(msg, args...); 
}
}//end of yll


//宏定义做简单的字符替换
#define  prefix(msg) string("[")\
		.append(__FILE__).append(":")\
		.append(__FUNCTION__).append(":")\
		.append(std::to_string(__LINE__)).append("]")\
		.append(msg).c_str()

//## 链接两个参数
#define logWarn(msg, args...) yll::Mylogger::getMylogger()->warn(prefix(msg), ##args);
#define logError(msg,args...) yll::Mylogger::getMylogger()->error(prefix(msg),##args);
#define logInfo(msg,args...) yll::Mylogger::getMylogger()->info(prefix(msg),##args);
#define logDebug(msg,args...) yll::Mylogger::getMylogger()->debug(prefix(msg),##args);

//template <class T , class... Args>
//void logWarn(T msg, 


#endif
