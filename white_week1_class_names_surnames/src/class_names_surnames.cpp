//============================================================================
// Name        : class_names_surnames.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdio.h>

using namespace std;


class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  name[year] = first_name;
	  update_info();
  }
  void ChangeLastName(int year, const string& last_name) {
	  surname[year] = last_name;
	  update_info();
  }
  string GetFullName(int year) {
	  string result = name[year] + " " + surname[year];
	  return result;
  }
  /*vector<int> exsisting_years;
  map <int, string> name;
  map <int, string> surname;*/
private:
  map <int, string> name;
  map <int, string> surname;
  vector<int> exsisting_years;

  void update_info(){


  }


};


int main() {

	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1967, 1990}) {
	cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
	cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
	cout << person.GetFullName(year) << endl;
	}

	return 0;
}
