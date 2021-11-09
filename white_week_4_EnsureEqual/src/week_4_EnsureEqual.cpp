//============================================================================
// Name        : week_4_EnsureEqual.cpp
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

#include <fstream>
#include <iomanip>
#include "Rational1.h"
using namespace std;


int main() {
	Rational R1, R2;
	char simbol;
	while(true){
		try {
			cin >> R1;
			cin >> simbol;
			cin >> R2;
			switch(simbol){
			case '+':
				cout << (R1 + R2) << endl;
				break;
			case '-':
				cout << (R1 - R2) << endl;
				break;
			case '*':
				cout << (R1 * R2) << endl;
				break;
			case '/':
				cout << (R1 / R2) << endl;
				break;
			default:
				cout << "invalid_argument" << endl;
			}
		} catch (invalid_argument& a) {
			cout << a.what() << endl;
		} catch (domain_error& b) {
			cout << b.what() << endl;
		}
	}
    return 0;
}
