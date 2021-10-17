//============================================================================
// Name        : yellow_week1_reference.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
#include <stdexcept>
using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k){
	if (m.count(k)){
		return m.at(k);
	}else{
		string str = "there are no such value: " + to_string(k);
		throw runtime_error(str);

	}



}



int main() {


	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 2);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue
	return 0;
}
