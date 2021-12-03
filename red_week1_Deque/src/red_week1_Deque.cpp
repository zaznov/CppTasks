//============================================================================
// Name        : red_week1_Deque.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<typename T>
class Deque{
public:
	Deque(){

	}
	const size_t Size() const {
		return v_front.size() + v_back.size();
	}
	const bool Empty(){
		if(v_front.empty() and v_back.empty()){
				return true;
		}
		return false;
	}


	T& operator[](size_t index){
		if (index < v_back.size()){
			int newInd = v_back.size() - index - 1;
			return v_back[v_back.size() - index - 1];
		} else {
			return v_front[index - v_back.size()];
		}
	}
	const T& operator[](size_t index) const{
		if (index < v_back.size()){
			return v_back[v_back.size() - index - 1];
		} else {
			return v_front[index - v_back.size()];
		}

	}
	T& At(size_t index){
		if(index >= this->Size()){
			stringstream ss;
			ss << "index = " << index << " > " << "size = " << this->Size();
			throw runtime_error(ss.str());
		}
		else{
			return (*this)[index];
		}
	}
	const T& At(size_t index) const {
		if(index >= this->Size()){
			stringstream ss;
			ss << "index = " << index << " > " << "size = " << this->Size();
			throw runtime_error(ss.str());
		}
		else{
			return (*this)[index];
		}
	}
	T& Front(){
		return v_front.back();
	}
	const T& Front() const {
		return v_front.back();
	}
	T& Back(){
		return v_back.back();
	}
	const T& Back() const {
		return v_back.back();
	}
	void PushFront (const T& val){
		v_front.push_back(val);
	}
	void PushBack(const T& val){
		v_back.push_back(val);
	}


private:
	vector<T> v_front;
	vector<T> v_back;
};


int main() {


	Deque<int> dq;

	cout << dq.Size() << endl;
	cout << dq.Empty() << endl;
	dq.PushFront(0);
	dq.PushFront(10);
	dq.PushFront(20);
	dq.PushFront(30);
	dq.PushFront(40);
	dq.PushFront(50);

	dq.PushBack(0);
	dq.PushBack(1);
	dq.PushBack(2);
	dq.PushBack(3);
	dq.PushBack(4);
	dq.PushBack(5);

	cout << dq.Size() << endl;
	cout << dq.Front() << endl;
	cout << dq.Back() << endl;

	cout << dq.At(7) << endl;



	return 0;
}





















