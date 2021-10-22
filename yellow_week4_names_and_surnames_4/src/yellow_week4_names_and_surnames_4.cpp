//============================================================================
// Name        : yellow_week4_names_and_surnames_4.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <string>
#include <numeric>
#include <iterator>
using namespace std;


class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
	  years__names.insert(lower_bound(years__names.begin(), years__names.end(), year), year);
	  changes_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		years__surnames.insert(lower_bound(years__surnames.begin(), years__surnames.end(), year), year);
		changes_surnames[year] = last_name;
	}
  string GetFullName(int year) {
	  stringstream ss;
	  string str;
	  if(years__names.empty() || years__surnames.empty()){
		  ss << "Not a fool person" << endl;
		  str = ss.str();
		  return str;
	  }
	  if(year < *years__names.begin() || year < *years__surnames.begin()){
		  ss << "Not a fool person" << endl;
		  str = ss.str();
		  return str;
	  }



	   if(binary_search(years__names.begin(), years__names.end(), year)){
		   ss << changes_names.at(*(lower_bound(years__names.begin(), years__names.end(), year))) << " ";

	  }
	   else ss << changes_names.at(*prev(lower_bound(years__names.begin(), years__names.end(), year))) << " ";


	  if(binary_search(years__surnames.begin(), years__surnames.end(), year)){
		  ss << changes_surnames.at(*(lower_bound(years__surnames.begin(), years__surnames.end(), year))) << " ";

	  	  }
	  else ss << changes_surnames.at(*prev(lower_bound(years__surnames.begin(), years__surnames.end(), year))) << endl;

	  str = ss.str();;
	  return str;

  }
private:
	map <int, string> changes_names;
	map <int, string> changes_surnames;
	vector<int> years__names;
	vector<int> years__surnames;
};


int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
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




















