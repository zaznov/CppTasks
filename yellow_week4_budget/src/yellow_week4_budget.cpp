//============================================================================
// Name        : yellow_week4_budget.cpp
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

void earn(vector<double>& Budget,int Start, int End, double value){
	if (static_cast<int>(Budget.size()) < End){
		Budget.resize(End+1);
	}
	for(int counter = Start; counter <= End; counter++){
		Budget.at(counter) += value/(End - Start + 1);
	}
}

double ComputeIncome (vector<double>& Budget,int Start, int End){
	return accumulate(Budget.begin() + Start, Budget.begin() + End + 1, 0.0);
}


int main() {


	Date d1(2000, 1, 1);
	cout << d1.toDays() << endl;

	Date d2(2000, 1, 11);
		cout << d2.toDays() << endl << endl;

	earn(Budget,d1.toDays(), d2.toDays(), 5353);


	for(auto val : Budget){
		cout << val << endl;
	}

	cout << endl;
	cout << ComputeIncome(Budget,d1.toDays(), d2.toDays()) << endl;

	return 0;
}
