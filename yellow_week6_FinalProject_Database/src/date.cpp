/*
 * date.cpp
 *
 *  Created on: 11 но€б. 2021 г.
 *      Author: NPK1
 */

#include "date.h"
#include <stdexcept>


int Date::GetYear() const{
	  return Year;
};
int Date::GetMonth() const{
  return Month;
};
int Date::GetDay() const{
  return Day;
};

void Date::SetYear(const int& new_year){
  Year = new_year;
};
void Date::SetMonth(const int& new_month){
  Month = new_month;
};
void Date::SetDay(const int& new_day){
  Day = new_day;
};
void Date::SetDate(const int& new_year, const int& new_month, const int& new_day){
	Year = new_year;
	Month = new_month;
	Day = new_day;
};


bool operator < (const Date& lhs, const Date& rhs){
	if(lhs.GetYear() < rhs.GetYear()){
		return true;
	}
	else if(lhs.GetYear() > rhs.GetYear()){
		return false;
	}
	else if(lhs.GetYear() == rhs.GetYear()){
		if(lhs.GetMonth() < rhs.GetMonth()){
			return true;
		}
		else if(lhs.GetMonth() > rhs.GetMonth()){
			return false;
		}
		else if(lhs.GetMonth() == rhs.GetMonth()){
			if(lhs.GetDay() < rhs.GetDay()){
				return true;
			}
			else if(lhs.GetDay() > rhs.GetDay()){
				return false;
			}
			else if(lhs.GetDay() == rhs.GetDay()){
				return false;
			}
		}
	}
	return false;
};

static inline void EnsureDelimiterAndSkip(istream& is){
	if(is.peek() != '-'){
		stringstream ss;
		ss << "ecpected '-', but is has:" << char(is.peek()) << " as a delimiter";
		throw runtime_error(ss.str());
	}
	is.ignore(1);
}

Date ParseDate(istream& is) {
	Date date;
	int Year;
	int Month;
	int Day;
	try {
		is >> Year;
		EnsureDelimiterAndSkip(is);
		is >> Month;
		EnsureDelimiterAndSkip(is);
		is >> Day;
	} catch (exception& e) {
		cout << "!!! Wrong date format: " << e.what() << endl;
	}
	date.SetDate(Year, Month, Day);
	return date;
}


ostream& 	operator << (ostream& stream, const Date& date){
	stream << setw(4) << setfill('0') << date.GetYear();
	stream << "-";
	stream << setw(2) << setfill('0') << date.GetMonth();
	stream << "-";
	stream << setw(2) << setfill('0') << date.GetDay();
	return stream;
}











