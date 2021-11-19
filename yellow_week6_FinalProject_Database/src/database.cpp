/*
 * database.cpp
 *
 *  Created on: 11 но€б. 2021 г.
 *      Author: NPK1
 */


#include "database.h"
#include <iomanip>
#include <iterator>
#include <algorithm>


void Database::Add(const Date& date, const string& event){
	if((find(List_of_events[date].begin(), List_of_events[date].end(), event))
			== List_of_events[date].end()){
		List_of_events[date].push_back(event);
	}

};
/*bool Database::DeleteEvent(const Date& date, const string& event){
  if(List_of_events[date].find(event)){
	  List_of_events[date].erase(event);
	  return true;
  }
  else{
	  List_of_events.erase(date);
	  return false;
  }
};*/
/*int  Database::DeleteDate(const Date& date){
  int size_of_set = List_of_events[date].size();
  List_of_events.erase(date);
  return size_of_set;
};*/

/*template<typename _Predicate>
map<Date, vector<string>> Database::FindIf(_Predicate isSuitable) {
	map<string> map_to_return;

	for(auto item : List_of_events){
		if (isSuitable(item.first, item.second)){
			map_to_return[item.first] = item.second;
		}
	}

  return map_to_return;
};*/


string Database::Last(const Date& date){
		auto IT = List_of_events.upper_bound(date);
		if(IT == List_of_events.begin()){
			throw invalid_argument("No entries");
		}
		auto lastDayEvents = (*prev(IT)).second;
		auto lastEventInLastDay = lastDayEvents.end();
		stringstream ss;
		ss << (*prev(IT)).first;
		ss << ' ' << *(prev(lastEventInLastDay));
		string LastString = ss.str();
		return LastString;
}



void Database::Print() const{
  for(auto data : List_of_events){
	  //cout << data.first << ":" << endl;
	  for(auto singl_event : data.second){
		  cout << data.first << ' ' << singl_event << endl;
	  }
	  //cout << endl;
  }
};










