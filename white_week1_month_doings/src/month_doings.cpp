//============================================================================
// Name        : month_doings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <vector <string>> calendar = {
			vector <string> (32, ""),
			vector <string> (29, ""),
			vector <string> (32, ""),
			vector <string> (31, ""),
			vector <string> (32, ""),
			vector <string> (31, ""),
			vector <string> (32, ""),
			vector <string> (32, ""),
			vector <string> (31, ""),
			vector <string> (32, ""),
			vector <string> (31, ""),
			vector <string> (32, ""),
	};


int main() {

	int number_commands = 0;
	string command = "";
	int arg1 = 0;
	string arg2 = "";
	int current_month = 0;

	cin >> number_commands;
		for(int i = 0; i < number_commands; i++){

			cin >> command;
			if(command == "ADD"){
				cout << command << endl;
				cin >> arg1;
				cin >> arg2;
				calendar[current_month][arg1] += arg2 + " ";
			}
			else if (command == "DUMP"){
				cout << command << endl;
				cin >> arg1;
				cout << calendar[current_month][arg1] << endl;
			}
			else if (command == "NEXT"){
				cout << command << "1" << endl;
				cout << "2";
				int difference = calendar[current_month+1].size() - calendar[current_month].size();
				cout << "3";
				if(difference < 0 ){
					for(int i = 0; calendar[current_month+1].size(); i++){

						calendar[current_month+1][i] = calendar[current_month][i];
					}
					cout << difference;
					difference *= (-1);
					for(int i = 0; i < difference; i++){
						calendar[current_month+1][calendar[current_month+1].size() -1] += calendar[current_month][calendar[current_month+1].size()+i] + " ";
					}
				}
				else{
					for(int i = 0; calendar[current_month].size(); i++){

						calendar[current_month+1][i] = calendar[current_month][i];
					}

				}
				current_month++;
				cout << "next over" << endl;
			}
		}


	return 0;
}
