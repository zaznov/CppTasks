//============================================================================
// Name        : yellow_week4_budget_2.cpp
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
#include <numeric>
#include <iterator>
using namespace std;

class Date{
public:
	Date(int y, int m, int d){
		Year = y;
		Month = m;
		Day = d;
	}
	int Year;
	int Month;
	int Day;
	int toDays(){
		int resultDays = 0;
		resultDays += Day;
		resultDays += monthToDays(Month);
		resultDays += yearToDays(Year);
		return resultDays;
	}
private:
	int monthToDays(int m){
		int resultDays = 0;
		resultDays = accumulate(DaysinMonth.begin(), DaysinMonth.begin() + m, 0);
		if((((Year-2000) % 4) == 0) && m > 2) resultDays += 1;									//if leap year
		return resultDays;
	}
	int yearToDays(int year){
		int resultDays = 0;
		year -= 2000;
		while(year > 0){
			if (--year % 4) resultDays +=365;
			else resultDays +=366;
		}

		return resultDays;
	}
	vector <int> DaysinMonth = {0,31,28,31,30,31,30,31,31,30,31,30,31};
};


vector <double> Budget;


void earn(vector<double>& Budget,int day, double value){
	if (static_cast<int>(Budget.size()) < day){
		Budget.resize(day+1);
	}
	Budget.at(day) += value;
}

int ComputeIncome (vector<double>& Budget,int Start, int End){
	if (static_cast<int>(Budget.size()) < End){
			Budget.resize(End+1, 0);
		}

	vector<int> current_income;
	partial_sum(Budget.begin() + Start, Budget.begin() + End + 1, back_inserter(current_income));

	return current_income.at(current_income.size() - 1);
}


int main() {

	earn(Budget, 4, 5);
	earn(Budget, 8, 11);
	earn(Budget, 12, 17);
	earn(Budget, 20, 1);


	cout << ComputeIncome(Budget, 0, 15) - ComputeIncome(Budget, 0, 3) << endl;
	cout << ComputeIncome(Budget, 0, 25) - ComputeIncome(Budget, 0, 3) << endl;
	cout << ComputeIncome(Budget, 0, 25) - ComputeIncome(Budget, 0, 18) << endl;
	cout << ComputeIncome(Budget, 0, 25) - ComputeIncome(Budget, 0, 10) << endl;
	cout << ComputeIncome(Budget, 0, 20) - ComputeIncome(Budget, 0, 12) << endl;

	cout << ComputeIncome(Budget, 3, 15) << endl;
	cout << ComputeIncome(Budget, 3, 25) << endl;
	cout << ComputeIncome(Budget, 18, 25) << endl;
	cout << ComputeIncome(Budget, 10, 25) << endl;





	return 0;
}
