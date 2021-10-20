//============================================================================
// Name        : yellow_week4_Arithmetic_expressions.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <string>
#include <numeric>
#include <iterator>
using namespace std;

vector<char> symbol;
vector<int> numbers;
int mainNumber = 0;
int ammounOfComands = 0;

string makeString(const vector<char>& symbol, const vector<int>& numbers, int &MainNumber){

	stringstream ss;
	string str = to_string(MainNumber);
	str.insert(str.begin(), '(');
	str.insert(str.end(), ')');


	auto ITsymb = symbol.begin();
	for(auto ITNum = numbers.begin(); ITNum != numbers.end(); ITNum++, ITsymb++){

		cout << *ITsymb << " " << *prev(ITsymb) << endl;
		if((*ITsymb == '/' || *ITsymb == '*') && ((*prev(ITsymb) == '+' || *prev(ITsymb) == '-'))){
			str.insert(str.begin(), '(');
		}

		ss << " " << *ITsymb << " ";
		string charInStr = ss.str();
		ss.str("");
		str += charInStr;
		str += to_string(*ITNum);

		if((*ITsymb == '/' || *ITsymb == '*') && ((*prev(ITsymb) == '+' || *prev(ITsymb) == '-'))){
			str.insert(str.end(), ')');
		}

	}

	str.erase(str.begin());
	str.erase(prev(str.end()));

	return str;
}

int main() {

	std::cin >> mainNumber;
	std::cin >> ammounOfComands;


	while(ammounOfComands--){
		char ch;
		std::cin >> ch;
		symbol.push_back(ch);

		int Number = 0;
		cin >> Number;
		numbers.push_back(Number);


	}

	cout << makeString(symbol, numbers, mainNumber);


	return 0;
}
