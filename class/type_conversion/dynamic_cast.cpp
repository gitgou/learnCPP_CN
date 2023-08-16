#include<iostream>

class Base
{
public:
  virtual void test(){};
};

class Driver1
{

};

class Driver2
:public Base
{
  virtual void test(){
    std::cout << "Driver2" << std::endl;
  }
};
int main(){

  // 1.没有继承关系,编译直接报错，需要含有多态
  Base base;
  //Driver1 * driver1 = dynamic_cast<Driver1*> (&base);

  // 2.继承关系 但没有虚函数,（非多态） 同上编译报错

  // 3.无继承关系，但有虚函数
  Driver1 * driver1 = dynamic_cast<Driver1*> (&base);
  if(!driver1){
    std::cout << "no inherit relation, result is null. " << std::endl;
  }
  // 4.有继承关系，向下转型失败情况
  Driver2 *driver2 = dynamic_cast<Driver2*>(&base);
  if(!driver2){
    std::cout << "inherit relation, but non-safe conversion, result is null. " << std::endl;
  } 
  // 5. 安全向下转型 
  Driver2 driver3; 
  Base * pb = &driver3;
  Driver2* driver4 = dynamic_cast<Driver2*>(pb);
  if(driver4){
    std::cout << "safe conversion." << std::endl;
  }
}