/*
 * database.h
 *
 *  Created on: 11 но€б. 2021 г.
 *      Author: NPK1
 */

#ifndef DATABASE_H_
#define DATABASE_H_

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
  bool DeleteEvent(const Date& date, const string& event);
  int  DeleteDate(const Date& date);
  set<string> Find(const Date& date);

  string Last(const Date& date);

  void Print() const;
private:
  map<Date, vector<string>> List_of_events;
};


#endif /* DATABASE_H_ */
