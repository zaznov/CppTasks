//============================================================================
// Name        : map_anagrams.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& word){
	map<char, int> result;
	for(auto i : word){
		result[i] ++;
	}
	return result;
}



int main() {

	int number_of_pairs = 0;
	cin >> number_of_pairs;
	vector <string> words(2*number_of_pairs);

	for(int i = 0; i <2*number_of_pairs; i++ ){
		cin >> words[i];
	}

	for(int i = 0; i <2*number_of_pairs; i++ ){
			cout << words[i] << endl;
		}
	for(int i = 0; i <2*number_of_pairs; i=i+2 ){
			if(BuildCharCounters(words[i]) == BuildCharCounters(words[i+1])){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}

	return 0;
}
