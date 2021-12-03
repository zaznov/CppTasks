//============================================================================
// Name        : red_week1_UNIQ_ID.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define GLUE_HELPER(x, y) x##y
#define GLUE(x, y) GLUE_HELPER(x, y)

#define UNIQ_ID GLUE(val, __LINE__)

int main() {
	//cout <<  STR(UNIQ_ID) << " is " << UNIQ_ID << endl; // prints !!!Hello World!!!

	  int UNIQ_ID = 0;
	  string UNIQ_ID = "hello";
	  vector<string> UNIQ_ID = {"hello", "world"};
	  vector<int> UNIQ_ID = {1, 2, 3, 4};
	return 0;
}
