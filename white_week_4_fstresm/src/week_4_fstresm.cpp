//============================================================================
// Name        : week_4_fstresm.cpp
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
#include <algorithm>

#include <fstream>
#include <iomanip>
using namespace std;

int main() {

	string in_source = "input.txt";
	string out_source = "output.txt";
	string line;
	ifstream input(in_source);
	ofstream output(out_source);
	int tmp;
	int lines;
	int rows;
	vector<vector<int>> table;

	if(input){
		input >> lines;
		input >> rows;
		table.resize(lines, vector<int>(rows));
		for(int i = 0; i < lines; i++){
			for(int j = 0; j < rows; j++){
				input >> tmp;
				table[i][j] = tmp;
				input.ignore(1);
			}
		}
	}else{
		cout << "error"<< endl;
	}

	for(int i = 0; i < lines; i++){
		for(int j = 0; j < rows; j++){
			cout <<setw(10) << table[i][j];
			if(j != (rows-1)) cout << " ";
		}
		if(i != (lines-1)) cout << endl;

	}

	return 0;
}
