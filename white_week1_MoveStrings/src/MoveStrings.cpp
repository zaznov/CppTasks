//============================================================================
// Name        : MoveStrings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& source , vector<string>& destination){

	for(auto str_i: source){
		destination.push_back(str_i);
	}
	source.clear();
}

void Reverse(vector<int>& source){

	source.size();
	for(int i = 0; i < (int)source.size()/2; i++){
		int tmp = source[i];
		source[i] = source[source.size() - i - 1];
		source[source.size() - i - 1] = tmp;
	}
}

vector<int> Reversed(const vector<int>& source){

	vector<int> rezult;
	int lens = (int)source.size();
	for(int i = 0; i < lens; i++){
			rezult.push_back(source[lens - i - 1]);
		}
	return rezult;
}



int main() {
	/*vector<string> words1 = {"source_1", "source_2"};
	vector<string> words2 = {"destination_1", "destination_2"};
	MoveStrings(words1, words2);
	cout << words2[0] << " " << words2[1] << " " << words2[2] << " " << words2[3] << endl;



	vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};
	Reverse(numbers);
	for(auto number_i: numbers){
			cout << number_i << " ";
		}*/

	vector<int> numbers_befor = {10, 20, 30, 40, 50, 60, 70};
	vector<int> numbers_after;

	numbers_after = Reversed(numbers_befor);

	for(auto number_i: numbers_after){
			cout << number_i << " ";
		}

	return 0;
}
