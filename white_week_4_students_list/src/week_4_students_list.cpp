//============================================================================
// Name        : week_4_students_list.cpp
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

#include <fstream>
#include <iomanip>
using namespace std;


struct Student{
	string name;
	string surname;
	string day;
	string month;
	string year;

};

vector<Student> Students;


int main() {
	int number_of_students;
	cin >> number_of_students;
	Students.resize(number_of_students+1);
	for(int i = 1; i <= number_of_students; i++){
		cin >> Students[i].name;
		cin >> Students[i].surname;
		cin >> Students[i].day;
		cin >> Students[i].month;
		cin >> Students[i].year;
	}




	int number_of_requests;
	cin >> number_of_requests;
	string command;
	int number;
	for(int i = 0; i < number_of_requests; i++){
		cin >> command;
		cin >> number;
		if (command == "name" && number >= 1 && number <= number_of_students){
			cout << Students[number].name << " " << Students[number].surname << endl;
		}else if(command == "date" && number >= 1 && number <= number_of_students){
			cout << Students[number].day << "." << Students[number].month << "." << Students[number].year << endl;
		}else{
			cout << "bad request" << endl;
		}
	}





	return 0;
}
