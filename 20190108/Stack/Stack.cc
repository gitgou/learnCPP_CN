 ///
 /// @file    Stack.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-13 14:24:51
 ///
 
#include <iostream>

using std::cout;
using std::endl;
 
class Stack
{
public:
	Stack(int size , int top )
	:_stack(new int[size]())
	,_size(size) 
	,_top(top)
	{
		cout << "Stack(int , int)" << endl;
	}
	//元素入栈
	void push(int element )
	{
		if(full())
		{
			cout << "Stack is full" << endl;
			return ;
		}
		_stack[++_top] = element;
		cout << "void push(element)" << endl ;
	}
	//元素出栈
	void pop()
	{
		if(empty())
		{
			cout << "Stack is empty " << endl ;
			return  ;
		}
		 _stack[_top--] = '\0';
	}
	//读出栈顶元素
	int  top() const 
	{
		if(!this->empty())
			return _stack[_top];
	}
	//判空
	bool empty() const 
	{
		if(_top == -1)
			return true;
		else 
			return false;
	}
	//判满
	bool full() const 
	{
		if((_top + 1) == _size)
			return true;
		else 
			return false;
	}

	//析构函数
	~Stack()
	{
		delete [] _stack;
		cout << "~Stack()" << endl;
	}

private:
	int *_stack; //栈区
	int _size;
	int  _top ;//栈指针
	
};

int main(void)
{
	Stack stack(10,-1);
	int number = 0;
	int number1 = 1;
	//stack.push(number);
    //number1 = stack.top();
	for(int index = 0 ; index < 10 ;++index)
		stack.push(index);
	for(int index = 0 ; index < 10 ; ++index)
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "是否为空 ？" << endl
		 << stack.empty() << endl;
	return 0;
}
