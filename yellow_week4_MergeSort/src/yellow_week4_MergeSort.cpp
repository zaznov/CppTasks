//============================================================================
// Name        : yellow_week4_MergeSort.cpp
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


template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	if(range_end - range_begin < 2) return;
	vector<typename RandomIt::value_type> elements(range_begin, range_end);
	vector<typename RandomIt::value_type> result;
	int length_of_a_half = elements.size() / 2;
	MergeSort(range_begin, range_begin + length_of_a_half);
	MergeSort(range_begin + length_of_a_half, range_end);
	merge(range_begin, range_begin + length_of_a_half, range_begin + length_of_a_half, range_end, back_inserter(result));
	copy(result.begin(), result.end(), range_begin);
}


int main() {
  vector<int> v = {6, 4, 15, 20, 17, 3, 7, 6, 4, 4, 0, 1, 0};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
