 ///
 /// @file    List.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-13 19:24:02
 ///
#ifndef __LIST_H__ 
#define __LIST_H__ 

#include <iostream>
using std::cout;
using std::endl;
class Node
{
public:
	int data ;
	Node * pre;
	Node * next;
};
class List 
{
public:

	 //构造函数
	 List()
	:_head(nullptr)   //最好初始化堆区内存
	,_tail(nullptr)
	,_size(0)
	{
		cout << "List() " << endl ;
	}
//	 ~List();
	 //在尾部添加数据
	 void push_back(int value);
	 //在头部添加数据
	 void push_front(int value);
	 //在尾部删除一个数据
	 void pop_back();
	 //在头部删除一个数据
	 void pop_front();
	 //在莫节点之前添加数据
	 void insert(Node * node , int value);
	 //删除指定节点
	 void erase(Node *node);
	 //打印链表
	 void display() const ;
private:

	 Node * _head;
	 Node * _tail;
	 int    _size;
};


#endif 
