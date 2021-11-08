//============================================================================
// Name        : week_3_names_surnames.cpp
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


using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  years__names.push_back(year);
	  changes_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  years__surnames.push_back(year);
	  changes_surnames[year] = last_name;
  }
  string GetFullName(int year) {
	  string st = "";
	  sort(begin(years__names), end(years__names));
	  sort(begin(years__surnames), end(years__surnames));
	  if(year < years__names[0]){
		  if(year < years__surnames[0]){
		  		  st = "Incognito";
		  	  }
		  else{
			  while(changes_surnames.count(year) != 1){
				  year--;
			  }
			  st = changes_surnames[year] + " with unknown first name";

		  }
	  }
	  else{
		  if(year < years__surnames[0]){
			  while(changes_names.count(year) != 1){
				  year--;
			  }
			  st = changes_names[year] + " with unknown last name";
		  }
		  else{
			  int year_name_counter = year;
			  int year_surname_counter = year;

			  while(changes_names.count(year_name_counter) != 1){
				  year_name_counter--;
			  }
			  st = changes_names[year_name_counter];
			  while(changes_surnames.count(year_surname_counter) != 1){
				  year_surname_counter--;
			  }
			  st += " " + changes_surnames[year_surname_counter];
		  }
	  }
	  return st;
  }
  string GetFullNameWithHistory(int year) {
	  string st = "";
	  	  sort(begin(years__names), end(years__names));
	  	  sort(begin(years__surnames), end(years__surnames));
	  	  if(year < years__names[0]){
	  		  if(year < years__surnames[0]){
	  		  		  st = "Incognito";
	  		  	  }
	  		  else{
	  			  while(changes_surnames.count(year) != 1){
	  				  year--;
	  			  }
	  			  st = changes_surnames[year];
	  			  for(int i = year-1; i >= years__surnames[0]; i--){
	  				  if(changes_surnames.count(i) == 1){
	  					st += " ("+ changes_surnames[i] +")";
	  				  }
	  			  }
	  			  st += " with unknown first name";

	  		  }
	  	  }
	  	  else{
	  		  if(year < years__surnames[0]){
	  			  while(changes_names.count(year) != 1){
	  				  year--;
	  			  }
	  			  st = changes_names[year];
	  			  for(int i = year-1; i >= years__names[0]; i--){
					  if(changes_names.count(i) == 1){
						st += " ("+ changes_names[i] +")";
					  }
				  }
				  st += " with unknown last name";
	  		  }
	  		  else{
	  			  int year_name_counter = year;
	  			  int year_surname_counter = year;

	  			  while(changes_names.count(year_name_counter) != 1){
	  				  year_name_counter--;
	  			  }
	  			  st = changes_names[year_name_counter];
	  			  for(int i = year_name_counter-1; i >= years__names[0]; i--){
					  if(changes_names.count(i) == 1){
						st += " ("+ changes_names[i] +")";
					  }
				  }

	  			  while(changes_surnames.count(year_surname_counter) != 1){
	  				  year_surname_counter--;
	  			  }
	  			  st += " " + changes_surnames[year_surname_counter];
	  			  for(int i = year_surname_counter-1; i >= years__surnames[0]; i--){
					  if(changes_surnames.count(i) == 1){
						st += " ("+ changes_surnames[i] +")";
					  }
				  }
	  		  }
	  	  }
	  	  return st;

    }
private:
  map <int, string> changes_names;
  map <int, string> changes_surnames;
  vector<int> years__names;
  vector<int> years__surnames;
};



int main() {
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1901, "Sokolov");
  person.ChangeLastName(1910, "Ivanov");
  person.ChangeFirstName(1920, "Dima");
  person.ChangeLastName(1930, "Petrov");
  cout << person.GetFullName(1900) << endl;

  return 0;
}













