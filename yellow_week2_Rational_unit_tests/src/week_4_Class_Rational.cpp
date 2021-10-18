//============================================================================
// Name        : week_4_Class_Rational.cpp
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
#include <numeric>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Rational1.h"
#include "Mytests.h"
using namespace std;


void TestNumerator(){
	Rational_1 number;
	stringstream  String_number;
	stringstream  String_test;

	number.Set_Numerator(10);
	number.Set_Denominator(5);
	String_number << number;
	String_test << "2/1";
	Assert_is_Equal(String_number.str(), 	String_test.str(), "Test1");
	String_number.str("");
	String_test.str("");
//--------------------------------------------------------------------------------------
	number.Set_Numerator(-10);
	number.Set_Denominator(5);
	String_number << number;
	String_test << "-2/1";
	Assert_is_Equal(String_number.str(), 	String_test.str(), "Test2");
	String_number.str("");
	String_test.str("");
//--------------------------------------------------------------------------------------
	number.Set_Numerator(0);
	number.Set_Denominator(50);
	String_number << number;
	//cout << String_number.str();
	String_test << "0/1";
	Assert_is_Equal(String_number.str(), 	String_test.str(), "Test3");
	String_number.str("");
	String_test.str("");
//--------------------------------------------------------------------------------------
	number.Set_Numerator(0);
	number.Set_Denominator(-50);
	String_number << number;
	String_test << "0/1";
	Assert_is_Equal(String_number.str(), 	String_test.str(), "Test4");
	String_number.str("");
	String_test.str("");
//--------------------------------------------------------------------------------------
}
void TestDenominator(){
	Rational_1 number;
	stringstream  String_number;
	stringstream  String_test;

	number.Set_Numerator(1);
	number.Set_Denominator(5);
	String_number << number;
	String_test << "1/5";
	Assert_is_Equal(String_number.str(), 	String_test.str(), "Test1");
	String_number.str("");
	String_test.str("");
//--------------------------------------------------------------------------------------
	number.Set_Numerator(1);
	number.Set_Denominator(-5);
	String_number << number;
	String_test << "-1/5";
	Assert_is_Equal(String_number.str(), 	String_test.str(), "Test2");
	String_number.str("");
	String_test.str("");
//--------------------------------------------------------------------------------------
	number.Set_Numerator(0);
	number.Set_Denominator(50);
	String_number << number;
	//cout << String_number.str();
	String_test << "0/1";
	Assert_is_Equal(String_number.str(), 	String_test.str(), "Test3");
	String_number.str("");
	String_test.str("");
//--------------------------------------------------------------------------------------
	number.Set_Numerator(50);
	number.Set_Denominator(-50);
	String_number << number;
	String_test << "-1/1";
	Assert_is_Equal(String_number.str(), 	String_test.str(), "Test4");
	String_number.str("");
	String_test.str("");
//--------------------------------------------------------------------------------------

}


void TestAll(){
	TestRunner tr;
	tr.Runtest(TestNumerator, "TestNumerator");
	tr.Runtest(TestDenominator, "TestDenominator");

}




int main() {

	TestAll();


    return 0;
}
