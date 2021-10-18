//============================================================================
// Name        : yellow_week2_collection_unit_tests2.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Mytests.h"


int SolveLineal(double b, double c){
	if(b != 0){
		return 1;
	}else{
		return 0;
	}

}
int SolveQuadradic(double a, double b, double c){

	double D = ((b) * (b)) - (4 * a * c);
	if (D > 0){
		return 2;
	}
	else if (D == 0){
		return 1;
	}
	else if (D < 0){
		return 0;
	}
	cerr <<  "Mistake in func SolveQuadradic!!" << endl;
	exit(1);
}



int GetDistinctRealRootCount(double a, double b, double c){

	if(a == 0){
		return SolveLineal(b, c);
	}
	else {
		return SolveQuadradic(a, b, c);
	}
	cerr <<  "Mistake in func GetDistinctRealRootCount!!" << endl;
		exit(1);
}


void TestZero(){
	Assert_is_Equal(GetDistinctRealRootCount(1, 0, 1), 		0, "Test1");
	Assert_is_Equal(GetDistinctRealRootCount(1, 3, 4), 		0, "Test2");

}

void TestOne(){

	Assert_is_Equal(GetDistinctRealRootCount(9,  -6,  1), 		1, "Test1");
	Assert_is_Equal(GetDistinctRealRootCount(0,  17,  0), 		1, "Test2");
	Assert_is_Equal(GetDistinctRealRootCount(5.9,  0.0,  0.0), 	1, "Test3");
	Assert_is_Equal(GetDistinctRealRootCount(-5.5,  0,  0.0), 	1, "Test4");
	Assert_is_Equal(GetDistinctRealRootCount(0.0,  17,  0.0), 	1, "Test5");


}

void TestTwo(){
	Assert_is_Equal(GetDistinctRealRootCount(-3,  0,  75), 		2, "Test1");
	Assert_is_Equal(GetDistinctRealRootCount(2,  4,  0), 		2, "Test2");
	Assert_is_Equal(GetDistinctRealRootCount(1,  -9,  3), 		2, "Test3");
}

void TestConstant() {
	Assert_is_Equal(GetDistinctRealRootCount(0, 0, 1), 0,
		"c = 0, where c = 1 has 0 real roots.");
	Assert_is_Equal(GetDistinctRealRootCount(0, 0, -10), 0,
		"c = 0, where c = -10 has 0 real roots.");
	Assert_is_Equal(GetDistinctRealRootCount(0, 0, 189238910), 0,
		"c = 0, where c = 189238910 has 0 real roots.");
}

void TestAll(){
	TestRunner tr;
	tr.Runtest(TestZero, "TestZero");
	tr.Runtest(TestOne, "TestOne");
	tr.Runtest(TestTwo, "TestTwo");
	tr.Runtest(TestConstant, "TestConstant");
}


int main() {

	TestAll();


	return 0;
}











