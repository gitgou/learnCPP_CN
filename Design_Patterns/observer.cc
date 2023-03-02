 ///
 /// @file    observer.cc
 /// @author  yll(1711019653@qq.com)
 /// @date    2019-02-10 14:42:29
 ///
#include <stdlib.h>
#include <memory> 
#include <string> 
#include <iostream>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::list;
using std::find;
using std::string;
using std::unique_ptr;

class Observer;

class Subject
{
public:
	virtual void attach(Observer * ob) =0;
	virtual void detach(Observer * ob) =0;
	virtual void notify() =0;
	virtual void setStatus(bool on) =0;
	virtual ~Subject(){cout << "~Subject()" << endl; }
private:
};

class Observer
{
public:
	virtual
	void update() =0;
};
class Ring
:public Subject
{
public:
	void attach(Observer * ob)
	{
		auto iter = find(_oblist.begin(), _oblist.end(), ob);
		if(iter == _oblist.end())
		{
			_oblist.push_back(std::move(ob));
		}
	}
	
	void detach(Observer * ob)
	{
		auto iter = find(_oblist.begin(), _oblist.end(), ob);
		if(iter != _oblist.end())
		{
			_oblist.erase(iter);
		}
	}

	void notify() 
	{
		for(auto & ob: _oblist)
		{
			ob->update();
		}
	}

	void setStatus(bool on)
	{
		_isKnocking = on;
		notify();
	}
		
	
private:
	list<Observer *> _oblist;
	bool _isKnocking;
};
class Baby
:public Observer 
{
public:
	Baby(const string & name)
	:_name(name)
	,_random(-1)
	{}
	void update()
	{
		::srand(::clock());
		_random = ::rand()%100;
		if(_random < 30)
			cout << ">>  Baby " << _name << " start crying!" << endl;
		else
			cout << ">> Baby is " << _name << "sleeping sweetly" << endl;
	}

	~Baby() { cout << "~Baby() " << _name << endl; }
private:
	string _name;
	int _random;
};
class Nurse
:public Observer 
{
public:
	Nurse(const string & name)
	:_name(name)
	,_random(-1)
	{}
	void update()
	{
		::srand(::clock());
		_random = ::rand()%100;
		if(_random < 70)
			cout << ">>  Baby " << _name << " is awake, start toopen the door" << endl;
		else
			cout << ">> Baby is " << _name << "sleeping sweetly" << endl;
	}

	~Nurse() { cout << "~Baby() " << _name << endl; }
private:
	string _name;
	int _random;
};

class Guest
{
public:
	Guest(const string & name)
	:_name(name)
	{}
	void knock(Subject & subject) //依赖关系
	{
		cout << _name << " is knocking the door " << endl;
		subject.setStatus(true);
	}

private:
	string _name;
};
int main(void)
{
	unique_ptr<Subject> ring(new Ring());
	unique_ptr<Observer> baby1(new Baby("大宝"));
	unique_ptr<Observer> baby2(new Baby("二宝"));
	unique_ptr<Observer> nurse1(new Nurse("小美"));
	unique_ptr<Observer> nurse2(new Nurse("小丽"));
	
	ring->attach(baby1.get());
	ring->attach(baby2.get());
	ring->attach(nurse1.get());
	ring->attach(nurse2.get());

	Guest guest("大鹏");
	guest.knock(*ring);

	ring->detach(baby1.get());
	guest.knock(*ring);


	return 0;
}
