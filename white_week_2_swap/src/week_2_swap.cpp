//============================================================================
// Name        : week_2_swap.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/*
void swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}


int main() {
	int a = 10;
	int b = 15;
	swap(a, b);
	cout << "a = " << a <<"; b = " << b;
	return 0;
}
*/




void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


int main() {
	int a = 10;
	int b = 15;
	swap(&a, &b);
	cout << "a = " << a <<"; b = " << b;
	return 0;
}
