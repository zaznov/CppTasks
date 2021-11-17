//============================================================================
// Name        : red_week1_UPDATE_FIELD.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "airline_ticket.h"
#include "test_runner.h"
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
#define TO_LINE(x) #x


#define UPDATE_FIELD(ticket, field, values)  {ticket.field = values.at(TO_LINE(departure_date)); }

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;
  const map<string, string> updates1 = {
      {"departure_date", "2018-2-28"},
      {"departure_date", "2018-2-28"},
    };
    UPDATE_FIELD(t, from, updates1);
    cout << t.departure_date.year << endl<< t.departure_date.month << endl<< t.departure_date.day << endl;

/*
  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);*/

  /*ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);*/
/*
  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);


  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));*/
}

int main() {
  TestRunner tr;
  //RUN_TEST(tr, TestUpdate);
  TestUpdate();


}
