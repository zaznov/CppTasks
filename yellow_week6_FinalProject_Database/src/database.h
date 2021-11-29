/*
 * database.h
 *
 *  Created on: 11 нояб. 2021 г.
 *      Author: NPK1
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
using namespace std;

#include "date.h"



class Database {
public:
  void Add(const Date& date, const string& event);
  //bool DeleteEvent(const Date& date, const string& event);
  //int  DeleteDate(const Date& date);

  /*template<typename _Predicate>
  map<Date, vector<string>> FindIf(_Predicate isSuitable) {
	  map<Date, vector<string>> map_to_return;

  	for(auto dayEvents : List_of_events){
  		//cout << "-----Current event is " << *prev(item.second.end()) << endl;
  		for(auto event : dayEvents.second){
  			cout << dayEvents.first << " " << event << endl;
			if (isSuitable(dayEvents.first, event)){
				map_to_return[dayEvents.first].push_back(event);
				cout << "------this event is suitable"<< endl;
			}
  		}
  	}

    return map_to_return;
  };*/
  template<typename _Predicate>
  vector<pair<Date, string>> FindIf(_Predicate isSuitable) {
	  vector<pair<Date, string>> vector_to_return;
    	for(auto dayEvents : List_of_events){
    		//cout << "-----Current event is " << *prev(item.second.end()) << endl;
    		for(auto event : dayEvents.second){
    			//cout << dayEvents.first << " " << event << endl;
				if (isSuitable(dayEvents.first, event)){
					vector_to_return.push_back(make_pair(dayEvents.first, event));
					//cout << "------this event is suitable"<< endl;
				}
    		}
    	}

      return vector_to_return;
    };
  template<typename _Predicate>
    int RemoveIf(_Predicate isSuitable) {
	int counter = 0;
      	for(auto &dayEvents : List_of_events){
      		for(auto event : dayEvents.second){
  				if (isSuitable(dayEvents.first, event)){
  					auto ITtoDel = find(dayEvents.second.begin(), dayEvents.second.end(), event);
  					//cout << event << " == " << *ITtoDel << " is delliting" << endl;
  					dayEvents.second.erase(ITtoDel);
  					//cout <<"Теперь  *ITtoDel = " << *ITtoDel << endl;
  					counter++;
  				}
      		}
      	}
        return counter;
      };
  string Last(const Date& date);
  void Print() const;
private:
  map<Date, vector<string>> List_of_events;
};


#endif /* DATABASE_H_ */
