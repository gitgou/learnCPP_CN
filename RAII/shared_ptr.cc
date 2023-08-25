#include<iostream>
using namespace std;

template<class T, class D = std::default_delete<T> >
class shared_ptr
{
public:
  shared_ptr()
  :_ptr(nullptr)
  ,_uCount(nullptr)
  {
    cout << "default constructor " << endl;
  }
  
  shared_ptr(T* ptr)
  :_ptr(ptr)
  ,_uCount(new size_t(1))
  {
    cout << " constructor T*" << endl;
  } 
  
  shared_ptr(T* ptr, D deleter)
  :_ptr(ptr)
  ,_deleter(deleter)
  ,_uCount(new size_t(1))
  {
    cout << " constructor T* DD " << endl;
  }
  
  shared_ptr(const shared_ptr<T, D> & sharedPtr)
  {
    if(sharedPtr._ptr)
    {
      _ptr = sharedPtr._ptr;
      _uCount = sharedPtr._uCount;
      add_count();
    }
  }
  
  shared_ptr& operator=(const shared_ptr<T, D> & sharedPtr)
  {
    if(_ptr == sharedPtr._ptr){ return *this; }
	//用以释放之前管理的资源 
    if(*_uCount == 1){  
      free(); 
    }else{
      reduce_count();
    }
    
	_ptr = sharedPtr._ptr;
    _uCount = sharedPtr._uCount;
    add_count();
    
	return *this;
  }
  
  void swap(shared_ptr<T, D> & sharedPtr)
  {
    std::swap(_ptr, sharedPtr._ptr);
    std::swap(_uCount, sharedPtr._uCount);
  }
  
  void reset(T* ptr)
  {
    if(*_uCount == 1){ 
      free(); 
    }else{
      reduce_count();   
    }
    _ptr = ptr;
    _uCount = new size_t(1);
  }
  
  T* get() const  { return _ptr; }

  size_t use_count()const { return *_uCount; }
  
  void print_use_count()
  {
    cout << *_uCount << endl;
  }
  ~shared_ptr()
  {
    //Call Deleter 
    if(*_uCount == 1){
      free();
    }else{
      reduce_count();
      print_use_count();
    }
  }
private:
  void reduce_count()
  {
    if(*_uCount > 0) -- ( *_uCount);
  }
  
  void add_count()  { ++(*_uCount); }
  
  void free()
  {
    _deleter(_ptr);
    delete _uCount;
  }
private:
  T* _ptr;
  //std::function<void(T*)> _deleter;
  D _deleter;
  size_t* _uCount ; 
};
