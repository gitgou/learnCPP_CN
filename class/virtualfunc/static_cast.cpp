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
	cout << "========== static_cast UP ==========" << endl;
	Derived1 derived1;
	Derived2 derived2;
	Base1* base1 = static_cast<Base1*> (&derived1);
	Base2* base2 = static_cast<Base2*> (&derived2);
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
	//static_cast 只能用于良性转换, 以下转换并不安全,static_cast是在编译期间做的转换
	cout << "========== static_cast DOWN ==========" << endl;
	Base1 base3;
	Base2 base4;
	Derived1* derived3 = static_cast<Derived1*> (&base3);
	Derived2* derived4 = static_cast<Derived2*> (&base4);
	if(derived3){
		cout << "derived3 successful " <<endl;
	}else{
		cout << "derived3 Fail" <<endl;
	}
	if(derived4){
		cout << "derived4 successful " <<endl;
	}else{
		cout << "derived4 Fail" <<endl;
	}
	return 0;
}
