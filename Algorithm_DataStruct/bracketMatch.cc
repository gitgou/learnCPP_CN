 ///
 /// @file    Stack.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-13 14:24:51
 ///
 
#include <iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
class Bracket_Matching 
{
public:
//	Bracket_Matching(int size)
//	:_stack(Stack(size))
//	{
//		 
//	}
	static bool Bracket_matching(vector<char> bracket, size_t size)
	{
		_stack = new Stack<char>(size);
		size_t idx = 0;
		for(idx = 0 ; idx < size; ++idx)
		{
			if(bracket[idx] == '{' || bracket[idx] == '[' || bracket[idx] == '(')
			{
				_stack->push(bracket[idx]);
			}
			else if(_stack->empty())
			{
				return false;
			}
			else 
			{
				if(_stack->top() == '(' && bracket[idx] == ')')
				{
					_stack->pop();
					continue;
				}
				else if(_stack->top() == '[' && bracket[idx] == ']')
				{
					_stack->pop();
					continue;
				}
				else if(_stack->top() == '{' && bracket[idx] == '}')
				{
					_stack->pop();
					continue;
				}
			}
		}
		if(idx == (idx-1))
			return true;
		else 
			return false;
	}
private:
template<class T>
class Stack
{
public:
	Stack(int size , int top = -1)
	:_stack(new T[size]())
	,_size(size) 
	,_top(top)
	{
		cout << "Stack(int , int)" << endl;
	}
	//元素入栈
	void push(T element )
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
	T  top() const 
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
	T *_stack; //栈区
	int _size;
	int  _top ;//栈指针
	
};
private:
	static Stack<char>*  _stack;
};
Bracket_Matching::Stack<char> * Bracket_Matching::_stack = nullptr;
int main(void)
{
	vector<char> bracket{'(','{','[','{','}',']',')'};
	cout << Bracket_Matching::Bracket_matching(bracket, 7) << endl;
	return 0;
}



