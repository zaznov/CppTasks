//============================================================================
// Name        : yellow_week4_iterators_PrintVector.cpp
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

void PrintVectorPart(const vector<int>& numbers){
	auto IT_first_negative = find_if(numbers.begin(), numbers.end(), [](const int& num){return (num < 0); });
	for(auto IT = IT_first_negative; IT != numbers.begin(); ){
			cout << *--IT << " ";
		}
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
