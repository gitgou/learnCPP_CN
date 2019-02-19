 ///
 /// @file    Vector.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-24 14:25:56
 ///
#include<memory> 
#include <iostream>
#include<iterator>
using std::cout;
using std::endl;
using std::iterator;

template<class T>
class Vector 
{
public:
	typedef T value_type;
	typedef T* iterator;
	Vector()
	:_start(nullptr)
	,_finish(nullptr)
	,_end_of_storage(nullptr)
	{
		cout << "Vector() " << endl;
	}

	int size() const {	return _finish - _start; }

	int capacity() const {	return _end_of_storage - _start; }
	
	iterator  begin() {	return _start; }
	
	iterator  end() {	return --_finish; }
	
	void reallocate();
	
	void push_back(const T & rhs);
	
	void pop_back();
	
	~Vector()
	{
		if(size() > 0)
		{
			while(_start != _finish)
				_alloc.destroy(--_finish);

			_alloc.deallocate(_start, capacity());
		}
	}
	

private: 
	static std::allocator<T> _alloc;  //内存分配类
private:
	T* _start;
	T* _finish;
	T* _end_of_storage;
};
template<class T>
void Vector<T>::push_back(const T & rhs)
{
	if(size() == capacity())
		reallocate();

	if(_finish) //finish 指向最后一个指针下一个位置，若为空则表示空间已满
	{
		_alloc.construct(_finish++,rhs);//直接调用，底层实现存放在vector中 
	}
}

template<class T>
void Vector<T>::pop_back()
{
	if(size() > 0)
	{
		_alloc.destroy(--_finish);
	}
}
template<class T>
void Vector<T>::reallocate()
{
	int oldSize = capacity();
	int newSize = oldSize*2 >0 ? oldSize*2 : 1;
	
	T* ptmp = _alloc.allocate(newSize); //仅仅分配了此空间，并未生成对象
										//使用new才会直接生成对象
	//std::copy(_start, _finish , ptmp);//copy算法必须是outIt对象已经存在
	std::uninitialized_copy(_start, _finish, ptmp);
	while(_start != _finish)
	{
		_alloc.destroy(--_finish);//每次销毁一个对象
	}
	_start = ptmp;
	_finish = ptmp + oldSize;
	_end_of_storage = _start + newSize;
	//if(size() == capacity())
}	
int main(void)
{
 
}
