///
 /// @file    unique_ptr.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2021-06-03 14:05:33
 ///
 
#include <iostream>
#include <algorithm>
#include <memory>
using std::cout;
using std::endl;
//数组类的指针使用的unique_ptr模板的特化版
/**
 *
 /// unique_ptr for array objects 
template<typename _Tp, typename _Dp>
class unique_ptr<_Tp[], _Dp>
{
        ...  
}
 */
template<typename T, typename D = std::default_delete<T> >
class unique_ptr
{
public:
  unique_ptr()
  :_ptr(nullptr)
  {
    cout << "construct unique ptr null" << endl;
  }
  
  unique_ptr(T* ptr)
  :_ptr(ptr)
  {
    cout << "construct unique ptr" << endl;
  }
  
  //c++ 11， 利用移动语义，可以将指针使用权进行转移 
  unique_ptr(unique_ptr&& other)
  {
    _ptr = other.release();
  }
  
  unique_ptr& operator=(unique_ptr&& other)
  {
    _ptr = other.release();
    return *this;
  }
  
  T& operator*()
  {
    return *_ptr;
  }
  
  T* operator->()
  {
    return _ptr;
  }
  
  T* release()
  {
    T* ptr = _ptr;
    _ptr = nullptr;
    return ptr;
  }
  
  //对外屏蔽复制构造函数和赋值构造函数
  //方法一 删除 复制构造函数和赋值构造函数
  //unique_ptr(const unique_ptr<T> & ptr) = delete;
  //unique_ptr(const unique_ptr<T, D> & ptr) = delete;
  //unique_ptr& operator=(const unique_ptr<T, D>& ptr) = delete;
  
  ~unique_ptr()
  {
    _deleter(_ptr);
  }
  
  void swap( unique_ptr& other)
  {
    std::swap(_ptr, other._ptr);
  }

protected:
  
  //方法二 注册复制构造函数和赋值构造函数为protected,对外屏蔽
  unique_ptr(const unique_ptr<T, D> & ptr)
  {
  }
  unique_ptr& operator=(const unique_ptr<T, D>& ptr)
  {}

private:
  T * _ptr;
  D _deleter; 
};
