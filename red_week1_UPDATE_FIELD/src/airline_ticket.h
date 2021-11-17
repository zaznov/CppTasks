/*
 * airline_ticket.h
 *
 *  Created on: 16 но€б. 2021 г.
 *      Author: NPK1
 */

#ifndef AIRLINE_TICKET_H_
#define AIRLINE_TICKET_H_

#include <string>
#include <sstream>

using namespace std;

class Date {
public:
  int year, month, day;
  Date operator=(const string& string);
};



Date Date::operator = (const string& str){
	Date date;
	stringstream ss(str);
	ss >> date.year;
	ss.get();
	ss >> date.month;
	ss.get();
	ss >> date.day;



	return date;
};


struct Time {
  int hours, minutes;
};

struct AirlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  int price;
};



#endif /* AIRLINE_TICKET_H_ */
