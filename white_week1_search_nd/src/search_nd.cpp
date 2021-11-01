//============================================================================
// Name        : search_nd.cpp
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

#define MIN(a,b) ((a)<(b)? (a) : (b))

int main() {

	int a=0, b=0, c=0;

	cin >> a >> b;

	/*for (int i=1; i <= MIN(a,b); i++){
		if((a % i == 0) && (b % i == 0)){
			c = i;
		}

	}*/

	while (a > 0 && b > 0){
		if(a>b) a = a % b;
		else 	b = b % a;
	}


	cout << a + b;
	return 0;
}








