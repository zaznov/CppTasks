//============================================================================
// Name        : yellow_week2_person_unit_tests.cpp
// Author      : Dmitrii Zaznov
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
#include "Mytests.h"

using namespace std;

class Person {
public:
	Person(){
		first_year = 1900;
		names[first_year] = "Unknown";
		surnames[first_year] = "Unknown";
		years_changes_names.push_back(first_year);
		years_changes_surnames.push_back(first_year);
	}
	void ChangeFirstName(const int year, const string& first_name) {
		names[year] = first_name;
		years_changes_names.push_back(year);


	}
	void ChangeLastName(const int year, const string& last_name) {
		surnames[year] = last_name;
		years_changes_surnames.push_back(year);
	}
	string GetFullName(const int year) {
		if(year <= first_year){
			return names[first_year] + " " + surnames[first_year];
		}
		return GetName(year) + " " + GetSurame(year);
	}

	string GetFullNameWithHistory(int year) {


	}
private:
	string GetName(int year) {
		while(count(begin(years_changes_names), end(years_changes_names), year) == 0){
			year--;
		}
		return names[year];
	}
	string GetSurame(int year) {
		while(count(begin(years_changes_surnames), end(years_changes_surnames), year) == 0){
			year--;
		}
		return surnames[year];

	}
  map <int, string> names;
  map <int, string> surnames;
  vector<int> years_changes_names;
  vector<int> years_changes_surnames;
  int first_year;
};

void TestNames(){
	Person person;
	person.ChangeFirstName(1901, "Nataly");
	Assert_is_Equal(person.GetFullName(1902), 	"Nataly Unknown", "Test1");

	person.ChangeFirstName(1905, "Alex");
	Assert_is_Equal(person.GetFullName(1905), 	"Alex Unknown", "Test2");

	person.ChangeFirstName(1940, "Sam");
	Assert_is_Equal(person.GetFullName(1980), 	"Sam Unknown", "Test3");

	Assert_is_Equal(person.GetFullName(1930), 	"Alex Unknown", "Test4");
	person.ChangeFirstName(1920, "Bill");
	Assert_is_Equal(person.GetFullName(1930), 	"Bill Unknown", "Test4");

	person.ChangeFirstName(1925, "Dima");
	Assert_is_Equal(person.GetFullName(1930), 	"Dima Unknown", "Test5");

	person.ChangeLastName(1950, "Iva_nov");
	Assert_is_Equal(person.GetFullName(1949), 	"Sam Unknown", "Test6");
	Assert_is_Equal(person.GetFullName(1951), 	"Sam Iva_nov", "Test6");

	person.ChangeFirstName(1950, ".");
	Assert_is_Equal(person.GetFullName(1950), 	". Iva_nov", "Test7");



}

void TestSurames(){
	Person person;
	person.ChangeLastName(1901, "Petrov");
	Assert_is_Equal(person.GetFullName(1902), 	"Unknown Petrov", "Test1");

	person.ChangeLastName(9999, "Ivanov");
	Assert_is_Equal(person.GetFullName(2000), 	"Unknown Petrov", "Test2");
	Assert_is_Equal(person.GetFullName(9999), 	"Unknown Ivanov", "Test2");


	person.ChangeFirstName(1920, "Ara");
	person.ChangeLastName(1920, "Zaznov");
	Assert_is_Equal(person.GetFullName(1919), 	"Unknown Petrov", "Test3");
	Assert_is_Equal(person.GetFullName(1920), 	"Ara Zaznov", "Test3");

	person.ChangeLastName(-0, "Draganov");
	Assert_is_Equal(person.GetFullName(19), 	"Unknown Unknown", "Test4");

	Assert_is_Equal(person.GetFullName(1918), 	"Unknown Petrov", "Test5");
	person.ChangeLastName(1915, "Draganov");
	Assert_is_Equal(person.GetFullName(1918), 	"Unknown Draganov", "Test5");



}

void TestAll(){
	TestRunner tr;
	tr.Runtest(TestNames, "TestNames");
	tr.Runtest(TestSurames, "TestSurames");
}

int main() {

	TestAll();

}













