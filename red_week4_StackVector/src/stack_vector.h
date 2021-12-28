/*
 * stack_vector.h
 *
 *  Created on: 28 дек. 2021 г.
 *      Author: NPK1
 */

#ifndef STACK_VECTOR_H_
#define STACK_VECTOR_H_


#include <stdexcept>
#include <array>
using namespace std;
#include <iostream>

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0){
	  if(a_size > N){
		  throw invalid_argument("a_size is too big");
	  }
	  totalElements = a_size;
  }


  T& operator[](size_t index){
	  return massiv[totalElements];
  }
  const T& operator[](size_t index) const{
	  return massiv[totalElements];
  }

  T* begin(){
	  return massiv.begin();
  }
  T* end(){
	  return massiv.end();
  }
  T* begin() const{
	  return massiv.begin();
  }
  T* end() const{
	  return massiv.end();
  }

  size_t Size() const{
	  return totalElements;
  }
  size_t Capacity() const{
	  return N;
  }

  void PushBack(const T& value){
	  if(totalElements == N){
		  throw overflow_error("totalElements already = N");
	  }
	  massiv[totalElements++] = value;

  }
  T PopBack(){
	  if(totalElements == 0){

		  throw underflow_error("Vector is empty");
	  }
	  return massiv[--totalElements];
  }

private:
  array<T,N> massiv;
  size_t totalElements;
};


#endif /* STACK_VECTOR_H_ */
