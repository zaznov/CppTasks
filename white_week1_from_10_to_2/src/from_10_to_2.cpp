//============================================================================
// Name        : from_10_to_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int number = 0;
	while(1){

		cin >> number;
		vector<int> number_in_dw;

		while(number){
			number_in_dw.push_back(number%2);
			number /=2;
		}

		reverse(begin(number_in_dw),end(number_in_dw));

		for (auto i : number_in_dw)
		{
			cout << i << " ";
		}

	}
	return 0;
}
