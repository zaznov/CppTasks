//============================================================================
// Name        : BUSES_STOPS_1.cpp
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

int main() {


	int amount_of_reqwests = 0;
	string command;
	map<string, string> map_of_busses;					//[bus_name][....stops...]
	map<string, string> map_of_stops;					//[stop][....bus_names...]
	cin >> amount_of_reqwests;
	for(int i = 0; i < amount_of_reqwests; i++){
		cin >> command;
		if (command == "NEW_BUS"){
			string new_bus_name;
			string new_stop;
			int number_of_stops;
			//vector<string> stops;

			cin >> new_bus_name;
			cin >> number_of_stops;
			for(int i = 0; i < number_of_stops; i++){
				cin >> new_stop;
				map_of_busses[new_bus_name] += new_stop + " ";
				map_of_stops[new_stop] += new_bus_name + " ";
			}
			//cout << map_of_busses[new_bus_name];

		}
		else if(command == "BUSES_FOR_STOP"){
			string stop;
			cin >> stop;
			cout << endl;
			if(map_of_stops[stop] == ""){
				cout << "STOP "<< stop << " : " << "No bus"<< endl;;
			}
			else{
				cout << "STOP "<< stop << " : " << map_of_stops[stop] << endl;
			}

		}
		else if(command == "STOPS_FOR_BUS"){
			string bus;
			cin >> bus;
			cout << endl;
			if(map_of_busses[bus] == ""){
				cout << "BUS "<< bus << " : " << "No stops"<< endl;;
			}
			else{
				cout << "BUS "<< bus << " : " << map_of_busses[bus] << endl;
			}

		}
		else if(command == "ALL_BUSES"){

			for(auto line : map_of_stops){
				cout << "For bus "<< line.first << " : " << line.second << endl;
			}
		}




	}
	return 0;
}
