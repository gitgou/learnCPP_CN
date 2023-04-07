#include<iostream>
#include<vector>

using namespace std;

class A{


private:
//public:
	static int a;

public:
	//静态私有成员变量，需要通过静态成员函数(public)来访问
	static int getValue(){
		return a;
	}
};

int A::a = 1;
int main(){

	cout << A::getValue() << endl;
}
