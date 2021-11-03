//============================================================================
// Name        : week_2_busses_3.cpp
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


	map<set<string>,int> bus_routs;
	int new_bus_number = 1;

	int commands_number;
	cin >>  commands_number;

	for(int i = 0; i < commands_number; i++){
		int stops_number;
		cin >> stops_number;
		set<string> stops;

		for(int i = 0; i < stops_number; i++){
			string new_stop;
			cin >> new_stop;
			stops.insert(new_stop);
		}

		if(bus_routs.count(stops) != 0){
			cout << "Already exists for " << bus_routs[stops] << endl;
		}
		else{
			bus_routs[stops] = new_bus_number;
			cout << "New bus " << new_bus_number << endl;
			new_bus_number++;
		}


	}


	return 0;
}
