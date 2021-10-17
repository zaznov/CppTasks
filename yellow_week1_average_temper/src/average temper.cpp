//============================================================================
// Name        : average.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;


void Print_v(vector<int> v){
	cout << "Vector is: ";
	for(auto i : v){
		cout << i << " ";
	}
	cout << endl;
}

int average_v(vector<int> v){
	int avr_temp = 0;
	for(auto i : v){
		avr_temp += i;
	}
	avr_temp /= v.size();
	return avr_temp;
}


int main() {
	cout << "start" << endl;
	vector<int> temper;
	uint32_t ammount_days = 0;
	cin >> ammount_days;
	int tmp = 0;
	for(uint32_t i = 0; i < ammount_days; i++){
		cin >> tmp;
		temper.push_back(tmp);
	}
	Print_v(temper);

	int average = average_v(temper);
	uint32_t ammount_of_days_above_aver = 0;
	cout << "average temper is: " << average << endl;

	cout << "------------------------------" << endl;
	cout << "Days numbers are:" << endl;
	for(uint32_t i = 0; i < temper.size(); i++){
		if(temper[i] > average){
			cout << i << " ";
			ammount_of_days_above_aver++;
		}
	}
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;

	cout << "ammount_of_days_above_aver is: " << ammount_of_days_above_aver << endl;
	return 0;
}







