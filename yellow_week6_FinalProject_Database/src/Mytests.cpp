/*
 * Mytests.cpp
 *
 *  Created on: 11 но€б. 2021 г.
 *      Author: NPK1
 */




#include "Mytests.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


TestRunner::~TestRunner(){
	if(fail_counter != 0){
		cerr << fail_counter << " unit test(s) failed. Terminate." << endl;
		exit(1);
	}
}
TestRunner::TestRunner() {
	fail_counter = 0;
}
