//============================================================================
// Name        : map_test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {

	map<int, string> m = {{1, "eins"}, {1, "zwei"}, {3, "drei"}, {4, "fier"}, {5, "funf"}, {6, "sechs"}, };



	for(const auto& item : m){
		cout << item.first << " : " << item.second << endl;
	}
	cout << "Size is :" << m.size() << endl;

	cout << endl;
	cout << endl;

	m.erase(1);

	for(const auto& item : m){
			cout << item.first << " : " << item.second << endl;
		}
	cout << "New size is :" << m.size() << endl;;
	return 0;
}
