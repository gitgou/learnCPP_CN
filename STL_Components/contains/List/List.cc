 ///
 /// @file    List.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-13 19:24:02
 ///
 
#include"List.h"
#include <iostream>
using std::cout;
using std::endl;


	 //在尾部添加数据
void List::push_back(int value)
{
	Node * p = new Node();
	p->data = value ;
	if(_head == nullptr | _tail == nullptr)
	{
		_head = p ;
		_tail = p ;
		p->pre = nullptr;
		p->next = nullptr;
	}
	else 
	{
		p->pre = _tail;
		p->next = nullptr;
		_tail->next = p;
		_tail = p;
	}
	++_size;
}
	 //在头部添加数据
void List::push_front(int value)
{
	Node * p = new Node();
	p->data = value ;
	if(_head == nullptr | _tail == nullptr)
	{
		_head = p ;
		_tail = p ;
		p->pre = nullptr;
		p->next = nullptr;
	}
		else 
		{
			p->pre = nullptr;
			p->next = _head;
			_head->pre = p ;
			_head = p;
		}
		++_size;
	}
	 //在尾部删除一个数据
void List::pop_back()
{
	if(_tail == nullptr)
	{
		cout << "this List is empty" << endl;
		return ;
	}
	Node * p = _tail;
	_tail = _tail->pre;
	_tail->next = nullptr;
	free(p);
	--_size;
}
	 //在头部删除一个数据
void List::pop_front()
{
	if(_tail == nullptr)
	{
		cout << "this List is empty" << endl;
		return ;
	}
	Node * p = _head;
	_head = _head->next;
	_head->pre = nullptr;
	free(p);
	--_size;
}
	 //在某节点之前添加数据
void List::insert(Node * node , int value)
{
	Node * p = new Node();
	p->data = value ;
	p->pre = node->pre;
	p->next = node;
	++_size;
}
	 //删除指定节点
void List::erase(Node *node)
{
	node->next->pre = node->pre;
	node->pre->next = node->next;
	free(node);
	--_size;
}
	 //打印链表
void List::display() const
{
	Node * p = _head;  //p为遍历指针
	while(p != nullptr)
	{
		cout << "value = " << p->data <<endl;
		p = p->next;
	}
	cout << "list_size = " << _size << endl;
}

	

int main(void)
{
	List list;
	cout << "头部插入："<<endl;
	list.push_front(2);
	list.display();
	cout << "头部插入:" << endl;
	list.push_front(3);
	list.display();
	cout << "尾部插入：" << endl;
	list.push_back(4);
	list.display();
	cout << "头部删除：" << endl;
	list.pop_front();
	list.display();
	cout << "尾部删除：" << endl;
	list.pop_back();
	list.display();
	//cout << list._size <<endl;//error
	return 0;
}
