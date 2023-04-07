#include<iostream>

using namespace std;

class EmptyClass{

	void display(){
		cout << "display " << endl; 
	}
};

class Base{

	virtual void display(){
		cout << "display " << endl; 
	}
};

class Derived 
:public Base{

};

class VirtualDerived1
:virtual public EmptyClass{
	void display(){
		cout << "display virtual derived" << endl;
	}
};

class VirtualDerived2
:virtual public EmptyClass{
	void display(){
		cout << "display virtual derived" << endl;
	}
};

class VirtualDerived3
:public VirtualDerived1, public VirtualDerived2{
};

int main(){
	cout << "empty class " << sizeof(EmptyClass) << endl;	
	cout << "virtual empty class " << sizeof(Base) << endl;	
	cout << "virtual empty class " << sizeof(Derived) << endl;	
	cout << "virtual inherient " << sizeof(VirtualDerived1) << endl;	
	cout << "virtual inherient " << sizeof(VirtualDerived2) << endl;	
	cout << "virtual inherient " << sizeof(VirtualDerived3) << endl;

	//实例化
	cout << "============================" << endl;
	VirtualDerived2 virtualDerived;
	VirtualDerived3 virtualDerived1;
	cout << sizeof(virtualDerived) << endl;
	cout << sizeof(virtualDerived1) << endl;
	return 0;
}
