 ///
 /// @file    LRU.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-01-27 17:58:19
 ///
 
#include <iostream>
#include<list>
#include<unordered_map>
using std::cout;
using std::endl;
using std::list;
using std::unordered_map;

class LRU
{
public:
	LRU(int capacity)
	:_capacity(capacity)
	{
		cout << "LRU(int) " << endl;
	}
	int get(int key)
	{
		unordered_map<int, list<CacheNode>::iterator>::iterator it = _cache.find(key);
		if(it == _cache.end())
		{
			return -1;
		}
		else
		{
			_cacheNode.splice(_cacheNode.begin(), _cacheNode, it->second);
			return it->second->_value;
		}
	}
	void put(int key, int value)
	{
		//节点之前就存在
		unordered_map<int,list<CacheNode>::iterator>::iterator it  = _cache.find(key);
		if(it != _cache.end())
		{
			it->second->_value = value ;
			_cacheNode.splice(_cacheNode.begin(), _cacheNode, it->second);
		}
		//空间已满
		else
		{
			if(_cacheNode.size() == _capacity)
			{	
				//得到最后元素节点.必须加引用
				auto & deletenode = _cacheNode.back();
				_cache.erase(deletenode._key);//使用key来删除节点
				_cacheNode.pop_back();
			}
			_cacheNode.emplace_front(key, value);
			_cache.insert(std::make_pair(key,_cacheNode.begin()));//队列直接插入节点，不破坏之前节点的地址
		}

	}

private:
	struct CacheNode
	{
		int _key;
		int _value;
		CacheNode(int key, int value)
		:_key(key)
		,_value(value)
		{
			cout << " CacheNode(int , int )" << endl;
		}
	};
	int _capacity;
	list<CacheNode> _cacheNode;
	unordered_map<int, list<CacheNode>::iterator> _cache;
};
 
int main(void)
{
	LRU cache(2);
	cache.put(1,1);
	cout << "cache.get(1) = " << cache.get(1) << endl;
	cache.put(2,2);
	cout << "cache.get(2) = " << cache.get(2) << endl;
	cache.put(3,3);
	cout << "cache.get(2) = " << cache.get(2) << endl;
	cache.put(4,4);
	cout << "cache.get(1) = " << cache.get(1) << endl;

}
