#include<iostream>

using namespace std;

class Base1{
	void display(){
		cout << "Base1 display " << endl;
	}
};

class Base2{
	virtual void display(){
		cout << "Base2 display " << endl;
	}
};

class Derived1
:public Base1
{
	void display(){
		cout << "Derived1 display " << endl;
	}
};

class Derived2
:public Base2
{
	virtual void display(){
		cout << "Derived1 display " << endl;
	}
};

int main(){
	//向上转换 
	cout << "========== dynamic_cast UP ==========" << endl;
	Derived1 derived1;
	Derived2 derived2;
	Base1* base1 = dynamic_cast<Base1*> (&derived1);
	Base2* base2 = dynamic_cast<Base2*> (&derived2);
	if(base1){
		cout << "base1 successful " <<endl;
	}else{
		cout << "base1 Fail" <<endl;
	}

	if(base2){
		cout << "base2 successful " <<endl;
	}else{
		cout << "base2 Fail" <<endl;
	}

	cout << "========== dynamic_cast DOWN ==========" << endl;
	//Base1 base3;
	Base2 base4;
	//Derived1 & Base 没有虚函数，不支持动态多态，编译不通过
	//Derived1* derived3 = dynamic_cast<Derived1*> (&base3);
	Derived2* derived4 = dynamic_cast<Derived2*> (&base4);
	/*
	if(derived3){
		cout << "derived3 successful " <<endl;
	}else{
		cout << "derived3 Fail" <<endl;
	}
	*/
	//dynamic_cast 会有类型检查
	//dynamic_cast运算符能够将基类的指针或引用安全的转换为派生类的指针或者引用
	//dynamic_cast会根据基类指针是否真正指向继承类指针来做相应处理
	//如果 downcast 不安全，这个运算符会传回空指针（也就是说，基类指针或者引用没有指向一个派生类对象)
	if(derived4){
		cout << "derived4 successful " <<endl;
	}else{
		cout << "derived4 Fail" <<endl;
	}
	return 0;
}
