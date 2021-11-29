//============================================================================
// Name        : yellow_week6_finalProject_database.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "database.h"
#include "date.h"
#include "condition_parser.h"
#include "node.h"
#include "Mytests.h"


#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <memory>
#include <istream>

using namespace std;

string ParseEvent(istream& is) {
	string line;
	getline(is >> ws, line);
	istringstream stream(line);
	return stream.str();
}

void TestAll();

int main() {
  TestAll();

  cout << "Everything is correct, let's start" << endl;
  Database db;

  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "Add") {
      const auto date = ParseDate(is);
      is.ignore(1);
      const auto event = ParseEvent(is);
      db.Add(date, event);
    } else if (command == "Print") {
      db.Print();
    } else if (command == "Del") {
      auto condition = ParseCondition(is);
      auto predicate = [condition](const Date& date, const string& event) {
        return condition->Evaluate(date, event);
      };
      int count = db.RemoveIf(predicate);
      cout << "Removed " << count << " entries" << endl;
    }
    else if (command == "Find") {
      auto condition = ParseCondition(is);
      auto predicate = [condition](const Date& date, const string& event) {
        return condition->Evaluate(date, event);
      };

      const auto entries = db.FindIf(predicate);
      for (const auto& entry : entries) {
        cout << entry.first << " " << entry.second  << endl;
      }
      cout << "Found " << entries.size() << " entries" << endl;
    } else if (command == "Last") {
      try {
          cout << db.Last(ParseDate(is)) << endl;
      } catch (invalid_argument&) {
          cout << "No entries" << endl;
      }
    } else if (command.empty()) {
      continue;
    } else {
      throw logic_error("Unknown command: " + command);
    }
  }

  return 0;
}

void TestParseEvent() {
  {
    istringstream is("event");
    Assert_is_Equal(ParseEvent(is), "event", "Parse event without leading spaces");
  }
  {
    istringstream is("   sport event ");
    Assert_is_Equal(ParseEvent(is), "sport event ", "Parse event with leading spaces");
  }
  {
    istringstream is("  first event  \n  second event");
    vector<string> events;
    events.push_back(ParseEvent(is));
    events.push_back(ParseEvent(is));
    Assert_is_Equal(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
  }
}


void TestAll() {
  TestRunner tr;
  tr.Runtest(TestParseEvent, "TestParseEvent");
  //tr.Runtest(TestParseCondition, "TestParseCondition");
}
