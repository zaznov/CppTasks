//============================================================================
// Name        : week_2_busses_2
// Author      : Zaznov Dmirty
// Version     : 1
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdio.h>

using namespace std;

map<vector <string>, int> bus_numbers;
int new_number = 1;
int main() {
	int amount_of_requests;
	cin >> amount_of_requests;

	for(int i = 0; i < amount_of_requests; i++){
		int amount_of_stops;
		cin >> amount_of_stops;
		vector <string> stops(amount_of_stops);
		for(int i = 0; i < amount_of_stops; i++){
			cin >> stops[i];
		}
		if(bus_numbers.count(stops) != 0){
			cout << "Already exists for " << bus_numbers[stops] << endl;
		}
		else{
			bus_numbers[stops] = new_number;
			cout << "New bus " << new_number << endl;
			new_number++;
		}


	}


	return 0;
}
