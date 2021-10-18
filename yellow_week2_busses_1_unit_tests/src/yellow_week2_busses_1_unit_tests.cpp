//============================================================================
// Name        : yellow_week2_busses_1_unit_tests.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};


QueryType string_to_QueryType( const string& command){

	if(command == "NEW_BUS"){
		return QueryType::NewBus;
	}
	else if(command == "BUSES_FOR_STOP"){
		return QueryType::BusesForStop;
	}
	else if(command == "STOPS_FOR_BUS"){
		return QueryType::StopsForBus;
	}
	else if(command == "ALL_BUSES"){
		return QueryType::AllBuses;
	}
	else{
		cout << "no such command" << endl;
	}
}

istream& operator >> (istream& is, Query& q) {
	string operation_code;
	is >> operation_code;
	q.type = string_to_QueryType(operation_code);

	if(q.type == QueryType::NewBus){
		is >> q.bus;

		int stop_count;
		is >> stop_count;

		q.stops.resize(stop_count);
		for(int i = 0; i < stop_count; i++){
			is >> q.stops[i];
		}
	}
	else if(q.type == QueryType::BusesForStop){
			is >> q.stop;
	}
	else if(q.type == QueryType::StopsForBus){
			is >> q.bus;
	}
	else if(q.type == QueryType::AllBuses){

		}

  return is;
}

struct BusesForStopResponse {
	vector<string> list_of_busses;
	bool correct;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if(r.correct == true){
		for(auto i : r.list_of_busses){
			os << i << endl;
		}
	}else{
		os << "No such stop" << endl;
	}

  return os;
}


struct StopsForBusResponse {
	vector<string> list_of_stops;
	bool correct;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {

	if(r.correct == true){
		for(auto i : r.list_of_stops){
			os << i << endl;
		}
	}else{
		os << "No such bus" << endl;
	}

  return os;
}


struct AllBusesResponse {
	map<string, vector<string>> map_of_busses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	for(auto this_rout : r.map_of_busses){
		os << this_rout.first <<" : ";
		for(auto stop :this_rout.second){
			os << stop <<", ";
		}
		os << endl;
	}
	os << endl;
	return os;
}







class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
	  buses_to_stops[bus] = stops;
	  for(const string& stop : stops){
		  stops_to_buses[stop].push_back(bus);
	  }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
	  	  BusesForStopResponse l;
	  	  if(stops_to_buses.count(stop)){
			  l.list_of_busses = stops_to_buses.at(stop);
			  l.correct = true;
	  	  }else{
	  		l.correct = false;
	  	  }
	  	return l;

  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
	  StopsForBusResponse l;
	  if(stops_to_buses.count(bus)){
		  l.list_of_stops = buses_to_stops.at(bus);
		  l.correct = true;
	  }else{
	  	  		l.correct = false;
	  	  	  }
	  return l;
  }

  AllBusesResponse GetAllBuses() const {
	  AllBusesResponse l;
		for(const auto& rout : buses_to_stops){
			l.map_of_busses[rout.first] = rout.second;
		}

		return l;
  }
private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;

};








int main() {
	cout << "start" << endl;
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
