/*
 * airline_ticket.h
 *
 *  Created on: 16 но€б. 2021 г.
 *      Author: NPK1
 */

#ifndef AIRLINE_TICKET_H_
#define AIRLINE_TICKET_H_
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Date {
  int year, month, day;
};


bool operator < (const Date& lhs, const Date& rhs){
	if(lhs.year < rhs.year){
		return true;
	}
	else if(lhs.year > rhs.year){
		return false;
	}
	else if(lhs.year == rhs.year){
		if(lhs.month < rhs.month){
			return true;
		}
		else if(lhs.month > rhs.month){
			return false;
		}
		else if(lhs.month == rhs.month){
			if(lhs.day < rhs.day){
				return true;
			}
			else if(lhs.day > rhs.day){
				return false;
			}
			else if(lhs.day == rhs.day){
				return false;
			}
		}
	}
	return false;
};

bool operator == (const Date& lhs, const Date& rhs){
	if(lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day){
		return true;
	}
	return false;
};


ostream& 	operator << (ostream& stream, const Date& date){
	stream << setw(4) << setfill('0') << date.year;
	stream << "-";
	stream << setw(2) << setfill('0') << date.month;
	stream << "-";
	stream << setw(2) << setfill('0') << date.day;
	return stream;
}


struct Time {
  int hours, minutes;
};

bool operator < (const Time& lhs, const Time& rhs){
	if(lhs.hours < rhs.hours){
		return true;
	}
	else if(lhs.hours > rhs.hours){
		return false;
	}
	else if(lhs.hours == rhs.hours){
		if(lhs.minutes < rhs.minutes){
			return true;
		}
		else if(lhs.minutes > rhs.minutes){
			return false;
		}
		else if(lhs.minutes == rhs.minutes){
			return false;
		}
	}
	return false;
};



enum SORT_PARAM{
	from,
	to,
	airline,
	departure_date,
	departure_time,
	arrival_date,
	arrival_time,
	price,
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
