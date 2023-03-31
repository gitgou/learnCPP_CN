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
	cout << "========== reinterpret_cast UP ==========" << endl;
	Derived1 derived1;
	Derived2 derived2;
	Base1* base1 = reinterpret_cast<Base1*> (&derived1);
	Base2* base2 = reinterpret_cast<Base2*> (&derived2);
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
	//reinterpret_cast reinterpret_cast 这种转换仅仅是对二进制位的重新解释，不会借助已有的转换规则对数据进行调整，非常简单粗暴，所以风险很高。
	//reinterpret_cast 可以认为是 static_cast 的一种补充，一些 static_cast 不能完成的转换，就可以用 reinterpret_cast 来完成，例如两个具体类型指针之间的转换、int 和指针之间的转换（有些编译器只允许 int 转指针，不允许反过来）。
	cout << "========== reinterpret_cast DOWN ==========" << endl;
	Base1 base3;
	Base2 base4;
	Derived1* derived3 = reinterpret_cast<Derived1*> (&base3);
	Derived2* derived4 = reinterpret_cast<Derived2*> (&base4);
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
