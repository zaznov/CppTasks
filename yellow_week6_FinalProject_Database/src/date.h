/*
 * date.h
 *
 *  Created on: 11 но€б. 2021 г.
 *      Author: NPK1
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <memory>
#include <istream>
using namespace std;

class Date {
public:
  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;
  void SetYear(const int& new_year);
  void SetMonth(const int& new_month);
  void SetDay(const int& new_day);
  void SetDate(const int& new_year, const int& new_month, const int& new_day);
private:
  int Year;
  int Month;
  int Day;

};


bool operator < (const Date& lhs, const Date& rhs);

ostream& 	operator << (ostream& stream, const Date& date);


Date ParseDate(istream& is);

#endif /* DATE_H_ */
