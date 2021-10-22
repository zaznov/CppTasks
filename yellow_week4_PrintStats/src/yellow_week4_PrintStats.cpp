//============================================================================
// Name        : yellow_week4_PrintStats.cpp
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
#include <utility>
#include <string>
using namespace std;

#define IS_FEMALE person.gender == Gender::FEMALE
#define IS_MALE person.gender == Gender::MALE
#define IS_FEMALE_EMPLOYED (person.gender == Gender::FEMALE && person.is_employed)
#define IS_FEMALE_UNEMPLOYED (person.gender == Gender::FEMALE && !person.is_employed)
#define IS_MALE_EMPLOYED (person.gender == Gender::MALE && person.is_employed)
#define IS_MALE_UNEMPLOYED (person.gender == Gender::MALE && !person.is_employed)

enum class Status{
	ALL,
	FEMALE,
	MALE,
	FEMALE_EMPLOYED,
	FEMALE_UNEMPLOYED,
	MALE_EMPLOYED,
	MALE_UNEMPLOYED
}st_ptr;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

bool compare(const Person& person_lhs, const Person& person_rhs){
	return person_lhs.age < person_rhs.age;
}

				// First option

void PrintStats(vector<Person> persons){

//Median age for all
	sort(persons.begin(), persons.end(), compare);
	cout << "Median age = " << persons[persons.size()/2].age << endl;
//Median age for females
	auto IT = partition(persons.begin(), persons.end(), [](const Person& person){return IS_FEMALE;});
	sort(persons.begin(), IT, compare);
	cout << "Median age females = " << persons[distance(persons.begin(), IT) / 2].age << endl;
//Median age for males
	IT = partition(persons.begin(), persons.end(), [](const Person& person){return IS_MALE;});
	sort(persons.begin(), IT, compare);
	cout << "Median age males = " << persons[distance(persons.begin(), IT) / 2].age << endl;
//Median age for employed females
	IT = partition(persons.begin(), persons.end(), [](const Person& person){return IS_FEMALE_EMPLOYED;});
	sort(persons.begin(), IT, compare);
	cout << "Median employed females = " << persons[distance(persons.begin(), IT) / 2].age << endl;
//Median age for unemployed females
	IT = partition(persons.begin(), persons.end(), [](const Person& person){return IS_FEMALE_UNEMPLOYED;});
	sort(persons.begin(), IT, compare);
	cout << "Median unemployed females = " << persons[distance(persons.begin(), IT) / 2].age << endl;
//Median age for employed males
	IT = partition(persons.begin(), persons.end(), [](const Person& person){return IS_MALE_EMPLOYED;});
	sort(persons.begin(), IT, compare);
	cout << "Median employed males = " << persons[distance(persons.begin(), IT) / 2].age << endl;
//Median age for unemployed males
	IT = partition(persons.begin(), persons.end(), [](const Person& person){return IS_MALE_UNEMPLOYED;});
	sort(persons.begin(), IT, compare);
	cout << "Median unemployed males = " << persons[distance(persons.begin(), IT) / 2].age << endl;
}



int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
