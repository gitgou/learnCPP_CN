 ///
 /// @file    Heap.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-13 17:20:53
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Heap
{
public:
	Heap(int size , int front = 0 ,int rear = 0)
	:_Heap(new int[size]())
	,_size(size)
	,_front(front)
	,_rear(rear)
	{
		cout << "Heap()" << endl;
	}
	void push(int element)
	{
		if(full())
		{
			cout << "Heap is full!" << endl;
			return ;
		}
		_Heap[_rear] = element;
		(++_rear) %= _size ;
	}
	void pop()
	{
		if (empty())
		{
			cout << " Heap is empty!" << endl;
		}
		_Heap[_front] = '\0';
		_front = (_front + 1) % _size;
		
	}
	int front() const 
	{
		if(!empty())
		{
			return _Heap[_front] ;
		}

	}
	int back() const 
	{
		if(!empty())
			return _Heap[((_rear + _size - 1)%_size )];

	}
	bool empty() const
	{
		if (_rear == _front)
			return true;
		else 
			return false;
	}
	bool full() const 
	{
		if (((_rear+1)%_size) == _front)
			return true;
		else
			return false;
	}
	~Heap()
	{
		delete [] _Heap;
		cout << "~Heap()" << endl;
	}
private:
	int *_Heap;
	int _size ;
	int _rear ;
	int _front;
};
int main(void)
{
	Heap heap(10);
	for(int index = 0 ; index < 9 ; ++index)
	{
		heap.push(index);
	}
	cout << "It's full ? " << endl 
		 << heap.full() << endl ;
	for (int index = 0 ;index < 9 ; ++index)
	{
		cout << heap.front() << endl ;
		heap.pop();
	}
	cout << "It's empty?" << endl 
		 << heap.empty() << endl ;
	return 0; 
}
