/*
 * SimpleVector.h
 *
 *  Created on: 24 дек. 2021 г.
 *      Author: NPK1
 */

#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_
#include <cstddef>
#include <cstdint>
#include <iostream>
using namespace std;

template <typename T>
class SimpleVector {
public:
  SimpleVector(){
	  capacity_size = 0;
	  data = nullptr;
	  total_elements = 0;

  }
  explicit SimpleVector(size_t _size){
	  capacity_size = _size;
	  data = new T[capacity_size];
	  total_elements = _size;
	  cout << "->->-> new data pointer in a constructor " << endl;
  }
  ~SimpleVector(){
	  if(data != nullptr){
		  delete[] data;
		  cout << "<-<-<- data is delited in a destructor " << endl;
	  }
  }

  T& operator[](size_t index){
	  return *(data + index);
  }

  T* begin(){
	  return data;
  }
  T* end(){
	  return (data + total_elements);
  }
  const T*  begin() const{
	  return data;
  }
  const T*  end() const{
	  return (data + total_elements);
  }

  size_t Size() const{
	  return total_elements;
  }
  size_t Capacity() const{
	  return capacity_size;
  }
  void PushBack(const T& value){
	  if(capacity_size == 0){
		  capacity_size = 1;
		  data = new T[capacity_size];
		  cout << "->->-> new data pointer in a PushBack " << endl;
	  }
	  if(capacity_size == total_elements){
		  T* data_new = new T[2 * capacity_size];
		  for (size_t i = 0; i < total_elements; ++i) {
			  *(data_new + i) = *(data + i);
		  }
		  delete[] data;
		  data = data_new;
		  capacity_size = 2 * capacity_size;
	  }

	  *(data + total_elements) = value;
	  total_elements++;
  }

private:
  T* data;
  size_t capacity_size;
  size_t total_elements;
};



#endif /* SIMPLEVECTOR_H_ */
