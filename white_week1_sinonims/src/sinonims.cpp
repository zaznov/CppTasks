//============================================================================
// Name        : sinonims.cpp
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
using namespace std;

int main() {


	map<string,set<string>> slovar;
	string command;
	int commands_number = 0;


	cin >>  commands_number;
	for(int i = 0; i < commands_number; i++){
		cin >>  command;

		if(command == "ADD"){
			string word1;
			string word2;
			cin >> word1;
			cin >> word2;

			slovar[word1].insert(word2);
			slovar[word2].insert(word1);

		}
		else if(command == "COUNT"){
			string word1;
			cin >> word1;

			if(slovar.count(word1)){
				cout << slovar[word1].size() << endl;
			}
			else{
				cout << "0" << endl;
			}
		}
		else if(command == "CHECK"){
			string word1;
			string word2;
			cin >> word1;
			cin >> word2;

			bool are_sininims = false;
			for(auto slovo : slovar[word1]){
				if(slovo == word2){
					are_sininims = true;
				}
			}
			if(are_sininims){
				cout << "YES" << endl;
				are_sininims = false;
			}
			else{
				cout << "NO" << endl;
			}
		}

	}













	return 0;
}
