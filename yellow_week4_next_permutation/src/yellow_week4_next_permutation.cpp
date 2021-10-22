//============================================================================
// Name        : yellow_week4_next_permutation.cpp
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


			/*First option*/
/*
string StringFrom_one_to_number(int& number){
	string str = "";
	while(number){
		char *intStr;
		itoa(number, intStr, 10);
		number--;
		str += string(intStr);
	}
	return str;

}*/


			/*Second option*/
/*
string StringFrom_one_to_number(int& number){
	string str = "";
	while(number){
			str += to_string(number);
			number--;
		}
	return str;

}
*/

			/*Third option*/

string StringFrom_one_to_number(int& number){
	string str = "";
	stringstream ss;
	while(number){
			ss << number;
			number--;
		}
	str = ss.str();
	return str;

}



int main() {

	int number = 3;
	string str = StringFrom_one_to_number(number);

	    sort(str.rbegin(), str.rend());
	    do {
	        cout << str << '\n';
	    } while(prev_permutation(str.begin(), str.end()));
	return 0;
}
