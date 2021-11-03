//============================================================================
// Name        : week_2_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int factorial(int number) {
	if (number <= 1){
		return 1;
	}
	return number * factorial(number - 1);
}



int main() {
	cout << factorial(3);
	return 0;
}
