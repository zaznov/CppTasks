//============================================================================
// Name        : yellow_week4_FindGreaterElements.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <string>
using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
	vector<T> result;
	for(auto IT = elements.begin(); IT != elements.end(); IT++){
		if(*IT > border){
			result.push_back(*IT);
		}
	}
	return result;

}

int main() {

  for (int x : FindGreaterElements(set<int>{11, 12, 10, 5, 4, -5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;

  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++", "www", "DD"}, to_find).size() << endl;
  return 0;
}
