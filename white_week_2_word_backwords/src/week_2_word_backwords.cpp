//============================================================================
// Name        : week_2_word_backwords.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool IsPalindrom(string st) {
	int length = st.length();
	for(int i = 0; i < length/2; i++){
		if(st[i] == st[length - 1 - i]){

		}
		else{
			return false;
		}
	}
	return true;
}



int main() {
	cout << IsPalindrom("madam");
	return 0;
}
