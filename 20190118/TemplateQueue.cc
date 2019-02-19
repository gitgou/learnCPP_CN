 ///
 /// @file    TemplateQueue.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-18 20:59:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <class T , size_t ksize = 10>
class Queue
{
public:
	Queue(size_t rear = 0 ,size_t front = 0 )
	:_rear(rear)
	,_front(front)
	,_data(new T[ksize]())
	{
		cout << "Queue()" << endl;
	}

	~Queue()
	{
		delete [] _data;
		cout << "~Queue()" << endl;
	}
	bool empty()
	{
		if(_rear == _front)
			return true;
		else 
			return false;
	}
	bool full()
	{
		if (((_rear+1)%ksize) == _front)
			return true;
		else 
			return false;
	}
	//出队
	void pop()
	{
		if(empty())
		{
			cout << " Queue is empty " << endl;
			return ;
		}
		else 
		{
			_data[_front] = '\0';
			_front = (_front + 1) %ksize;
		}
	}

	void push(T element)
	{
		if(full())
		{
			cout << "Queue is full " << endl;
			return ;
		}
		_data[_rear] = element;
		_rear = (_rear+1)%ksize;
	}

	T pop_front()
	{
		if (!empty())
			return _data[_front];
	}

	T pop_back()
	{
		if(!empty())
			return _data[(_rear + ksize -1)*ksize] ;
	}

private:
	
	size_t  _rear;
	size_t  _front;
	T * _data;
};



int main(void)
{
	Queue<int>  q;
	cout << "q 为空吗？ " <<  q.empty() << endl;
	for (int index = 0 ; index < 11 ; ++index)
		q.push(index);

	cout << endl << "q is full ? " << q.full() << endl;

	for(int index = 0 ; index < 11; ++ index){
		if(!q.empty())
		cout << q.pop_front() << endl;
		q.pop();
	}
	
}

