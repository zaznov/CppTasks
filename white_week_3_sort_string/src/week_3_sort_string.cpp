//============================================================================
// Name        : week_3_sort_string.cpp
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
#include <stdio.h>

using namespace std;


bool myfunction (string str1,string str2) {


	for(auto& i : str1){
		i = tolower(i);
		cout << i << endl;
	}
	for(auto& i : str2){
		i = tolower(i);
		cout << i << endl;
	}
	cout << "1 меньше 2?" << endl;
	if(str1 < str2){
		return true;
	}
	else return false;
}


int main() {
	int ammount;
	cin >> ammount;
	vector<string> array;
	for (int i = 0; i < ammount; i++){
		string x;
		cin >> x;
		array.push_back(x);
	}

	sort(begin(array), end(array), myfunction);

	for(auto i : array){
		cout << i <<" ";
	}



	return 0;
}
