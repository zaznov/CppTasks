//============================================================================
// Name        : week_2_print_vector.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_vector(vector<string>& source){

	for(auto i: source){
		cout << i << "  ";
	}

}
void print_vector(vector<int>& source){

	for(auto i: source){
		cout << i << "  ";
	}

}
void print_vector_over_middle(vector<int>& source){
	int summ =0;

	for(auto i: source){
			summ += i;
		}
	int middle = summ / source.size();
	cout << middle << endl;
	int position = 0;
	for(auto i: source){
		if(i > middle) cout << position << "  ";
		position++;
	}

}


int main() {



	vector<int> temperatur = {0, 1, 8, 3, 9, 2, 35};

	cout << endl;
	print_vector_over_middle(temperatur);

	return 0;
}
