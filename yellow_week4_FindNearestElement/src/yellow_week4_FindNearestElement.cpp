//============================================================================
// Name        : yellow_week4_FindNearestElement.cpp
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
#include <numeric>
#include <iterator>
using namespace std;


set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border){

	if(numbers.empty()) return numbers.end();
	if (border >= *prev(numbers.end())){
		return prev(numbers.end());
	}
	else if (border <= *numbers.begin()){
		return numbers.begin();
	}
	else{
		auto IT1 = lower_bound(numbers.begin(), numbers.end(), border);
		if (*IT1 == border) return IT1;
		auto IT2 = prev(lower_bound(numbers.begin(), numbers.end(), border));
		return (border - *IT2) <= (*IT1 - border) ? IT2 : IT1;
	}



};


int main() {
  set<int> numbers = {1, 10, 20, 30};
  cout <<
		*FindNearestElement(numbers, -5) << " " <<
		*FindNearestElement(numbers, 1) << " " <<
		*FindNearestElement(numbers, 3) << " " <<
		*FindNearestElement(numbers, 7) << " " <<
		*FindNearestElement(numbers, 10) << " " <<
		*FindNearestElement(numbers, 12) << " " <<
		*FindNearestElement(numbers, 18) << " " <<
		*FindNearestElement(numbers, 20) << " " <<
		*FindNearestElement(numbers, 22) << " " <<
		*FindNearestElement(numbers, 28) << " " <<
		*FindNearestElement(numbers, 30) << " " <<
		*FindNearestElement(numbers, 35) << " " <<
		*FindNearestElement(numbers, 1000) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}


















