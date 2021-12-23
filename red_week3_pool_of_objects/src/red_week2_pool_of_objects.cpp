//============================================================================
// Name        : red_week2_pool_of_objects.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
	ObjectPool(){

	}
  T* Allocate(){
	  if(!freed.empty()){
		  T* object = freed.front();
		  allocated.insert(object);
		  freed.pop();
		  cout << "New object is reallocated! " << endl;
		  return object;

	  }else{
		  T* object = new T;
		  allocated.insert(object);
		  cout << "New object is allocated! " << endl;
		  return object;

	  }
  }
  T* TryAllocate(){
	  if(!freed.empty()){
		  T* object = freed.front();
		  allocated.insert(object);
		  freed.pop();
		  return object;

	  }else{
		  return nullptr;

	  }
  }

  void Deallocate(T* object){
	  if(allocated.count(object)){
		  cout << *object << " is dealocated" << endl;
		  freed.push(object);
		  allocated.erase(object);
	  }
	  else{
		  cout << "!!! " << *object << endl;
		  throw invalid_argument("there is no such object in the q!");
	  }

  }

  ~ObjectPool(){
	  int counter_allocated = 0;
	  int counter_freed = 0;
	  for(auto element : allocated){
			delete element;
			counter_allocated++;
	  }
	  while(!freed.empty()){
		  delete freed.front();
		  freed.pop();
		  counter_freed++;
	  }
	  cout << "Were deleted "<< counter_allocated << " allocated elements and " << counter_freed << " freed elements" << endl;
  }

private:

  set<T*> allocated;
  queue<T*> freed;		//должа быть очередь

};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
