 ///
 /// @file    Noncopyable.h
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-11 21:07:44
 ///
#ifndef __YLL_NONCOPYABLE_H__
#define __YLL_NONCOPYABLE_H__
namespace yll{
class Noncopyable
{
protected:

	Noncopyable(){}
	~Noncopyable(){}
	Noncopyable(const Noncopyable & rhs) = delete;
	Noncopyable & operator=(const Noncopyable & rhs) = delete;
};


}// end of yll





#endif 

