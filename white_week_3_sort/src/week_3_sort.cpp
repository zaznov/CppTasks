//============================================================================
// Name        : week_3_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


bool myfunction (int i,int j) {if(abs(i)<abs(j)){return true;} else return false;}


int main() {
	int ammount;
	cin >> ammount;
	vector<int> array;
	for (int i = 0; i < ammount; i++){
		int x;
		cin >> x;
		array.push_back(x);
	}

	sort(begin(array), end(array), myfunction);

	for(auto i : array){
		cout << i <<" ";
	}



	return 0;
}
