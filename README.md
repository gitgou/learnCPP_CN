# CPP 学习路线规划及样例代码：

## 介绍：

​	本项目主要总结了 C++ 学习路线, 并且推荐学习参考代码、相关知识网址、博客。项目中代码有详细知识点注解，推荐大家把样例代码动手敲一遍，时间安排仅为建议时间、可根据自己进度自由调整～～ 

## Start

### **Day 1** 

**类（class):**

- **构造/析构函数**

  掌握默认构造函数、构造函数重载、默认析构函数、析构函数重载、复制构造函数重载、赋值构造函数重载

  [example_point]((https://github.com/gitgou/learnCPP_CN/tree/master/class/constructor/computer))

  [point_example](https://github.com/gitgou/learnCPP_CN/tree/master/class/constructor/point)

-  **运算符重载**

    掌握主要运算符+、-、*、/、前后置++、+= 等重载

    [operator_example](https://github.com/gitgou/learnCPP_CN/blob/master/class/operator/complex.cc)

    [运算符重载，以string为例](https://github.com/gitgou/learnCPP_CN/tree/master/STL_Components/string/String)

- **new/delete 函数**

  学会 new/delete 函数重载，对比以下两种实现区别：当 new/delete被声明为私有函数时，类只能被实例化为栈对象，而不能实例化在堆内存。

  https://github.com/gitgou/learnCPP_CN/blob/master/class/operator/stackStudent.cc

  https://github.com/gitgou/learnCPP_CN/blob/master/class/operator/stackStudent.cc



### Day 2

**类 (class):**

- **继承**

  掌握私有、公有、保护继承的区别：

  ​	[代码导航](https://github.com/gitgou/learnCPP_CN/blob/master/class/inherit/Cicle.cc)

  掌握派生类向上转型，对比以下例子区别：

  ​	https://github.com/gitgou/learnCPP_CN/blob/master/class/inherit/DerivedCopy.cc

  ​	https://github.com/gitgou/learnCPP_CN/blob/master/class/inherit/DerivedCopy2.cc

  了解	[多重继承](	https://github.com/gitgou/learnCPP_CN/blob/master/class/inherit/multiDerived1.cc
)、	[菱形继承的二义性](https://github.com/gitgou/learnCPP_CN/blob/master/class/inherit/multiDerived2.cc)
  
  ​	

- **多态**

  **静态多态：**

  - **函数重载：**如以上的构造函数重载，重载指允许在相同作用域中存在多个同名的函数，但要求**参数列表不同**

    

  - **函数隐藏**：覆盖是存在类中，子类重写从基类继承过来的函数，函数名、返回值、参数列表都必须和基类相同。当子类的对象调用成员函数的时候，如果成员函数有被覆盖则调用子类中覆盖的版本，否则调用从基类继承过来的函数。

    

  - **函数覆盖** ：虚函数允许子类重新定义成员函数，而子类重新定义父类的做法称为覆盖(override)，或者称为重写。最常见的用法就是声明基类的指针，利用该指针指向任意一个子类对象，调用相应的虚函数。重点掌握虚函数机制 -- **虚函数表**、**声明纯虚函数的抽象类**、**菱形继承**。

    [虚函数样例代码导航](https://github.com/gitgou/learnCPP_CN/tree/master/class/virtualfunc)

### Day 3

​	STL 六大组件：容器（container）、算法(Algorithm)、迭代器(Iterator)、函数对象(Functional Object)、内存分配器(Allocator)、适配器(Adapter)

- ​	**STL -- string library**

  掌握 string 常见的成员函数，并且动手实现 string类；掌握 string 写时复制技术（cow）

  [String 样例代码导航](https://github.com/gitgou/learnCPP_CN/tree/master/STL_Components/string/String)

  [String(cow)样例代码导航](https://github.com/gitgou/learnCPP_CN/tree/master/STL_Components/string/string_cow)

- **STL -- Input/Output library**

  [iostream 样例代码导航](https://github.com/gitgou/learnCPP_CN/tree/master/STL_Components/iostream)

  [cppreference 导航](https://en.cppreference.com/w/cpp/io)

### Day 4

- **STL组件 -- 容器：**

  **序列容器： vector、list、deque**等；

  **关联容器：map、unordered_map、multimap、set、unordered_set、multiset** 等的使用及原理

  [容器样例代码导航](https://github.com/gitgou/learnCPP_CN/tree/master/STL_Components/contains)

  [博客分享](https://blog.csdn.net/yllblog/article/details/123496154)

  [cppreference 导航](https://en.cppreference.com/w/cpp/container)

  

### Day 5

​	[小训练](https://github.com/gitgou/learnCPP_CN/tree/master/STL_Components/contains/practice)

### Day 6

- **RAII**

  ​		RAII全称是“Resource Acquisition is Initialization”，即 “资源请求即初始化”， 为解决资源管理时异常安全性所使用的资源管理方法。 

  ​		掌握 **auto_ptr**（C++17 已经被正式从C++标准里删除了）、**unique_ptr**、**shared_ptr**、**weak_ptr** 原理及用法; 样例代码中用法都有介绍。

  ​		<u>**重点掌握 unique_ptr 原理，shared_ptr 原理（引用计数管理方法），weak_ptr 与 shared_ptr的区别**</u>：weak_ptr是为了配合shared_ptr而引入的一种智能指针，它指向一个由shared_ptr管理的对象而不影响所指对象的生命周期，也就是将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数。不论是否有weak_ptr指向，一旦最后一个指向对象的shared_ptr被销毁，对象就会被释放。从这个角度看，weak_ptr更像是shared_ptr的一个助手而不是智能指针。

  [博客分享](https://blog.csdn.net/yllblog/article/details/123412319)

  [RAII样例代码](https://github.com/gitgou/learnCPP_CN/tree/master/RAII)

- **数据结构**

  [LRU Algorithm](https://github.com/gitgou/learnCPP_CN/blob/master/Algorithm_DataStruct/LRU.cc)

### Day 7

- **排序算法**

  实现以下排序算法，熟悉排序算法原理、平均（最坏）时间复杂度、稳定性等指标，熟悉各排序算法应用场景。

  [快排](https://github.com/gitgou/learnCPP_CN/blob/master/Algorithm_DataStruct/quickSort.cc)

  [大小顶堆排序](https://github.com/gitgou/learnCPP_CN/blob/master/Algorithm_DataStruct/heapSort.cc)

  [归并排序](https://github.com/gitgou/learnCPP_CN/blob/master/Algorithm_DataStruct/mergeSort.cc)

- LeetCode 算法

  https://github.com/gitgou/LeetCode

  Tips: 后续会将 LeetCode 刷题记录整理出来。

### Day 8

- **STL string cow,写时复制(0 copy):**

  了解深拷贝和浅拷贝的区别，详情请参考两篇博客[博客分享](https://xie.infoq.cn/article/11999d52e913603f49ca00ed3)  [维基百科](https://zh.wikipedia.org/wiki/%E5%AF%AB%E5%85%A5%E6%99%82%E8%A4%87%E8%A3%BD)

  [stl_string_cow_code](https://github.com/gitgou/learnCPP_CN/tree/master/STL_Components/string/string_cow)

- **STL 函数对象：**

  重载函数调用操作符的类，其对象称为函数对象(function object)

  [STL bind 函数](https://github.com/gitgou/learnCPP_CN/tree/master/STL_Components/functional)

### Day 9

- **设计模式：**

  这里只举例了三种设计模式：[单例、观察者、PIMPL模式](https://github.com/gitgou/learnCPP_CN/tree/master/Design_Pattern)

​		总共有二十几种设计模式，重点掌握单例模式、观察者模式、工厂模式、代理模式、外观模式、适配器模式；推荐学习网站：[设计模式](https://refactoringguru.cn/design-patterns/catalog) 、 [图解设计模式](https://design-patterns.readthedocs.io/zh_CN/latest/)；后续再补充其它设计模式代码。

### Day 10 - 11

- **thread 多线程**

  熟悉 pthread库的使用，掌握互斥变量 pthread_mutex_t、条件变量 pthread_cond_t 、信号量semaphore（[博客推荐](https://zhuanlan.zhihu.com/p/512969481)）。

  实现了两个版本的线程库供参考：[thread](https://github.com/gitgou/learnCPP_CN/tree/master/thread)

### Day 12 - 15 

- **socket 网络编程**

  掌握 socket 编程相关接口的使用，熟悉**同步/异步、阻塞/非阻塞（**[博客推荐](https://openrad.ink/2021/03/08/%E5%90%8C%E6%AD%A5%E5%BC%82%E6%AD%A5%E9%98%BB%E5%A1%9E%E9%9D%9E%E9%98%BB%E5%A1%9E%E8%AF%A6%E8%A7%A3/)）；熟悉 **select/poll/epoll** 的优缺点；TCP 三次握手/四次挥手不同阶段状态。

  [socket编程代码（包括阻塞式、非阻塞式：select/epoll模式）](https://github.com/gitgou/learnCPP_CN/tree/master/socket)

  

**未完待续...**

因时间紧促，资料补充不够充分，后续会陆续补充；有误之处，还望多多指正，也欢迎一起参与项目建设，联系方式见 github 主页，感谢。
