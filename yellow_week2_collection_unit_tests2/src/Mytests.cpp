/*
 * Mytests.cpp
 *
 *  Created on: 24 рту. 2021 у.
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
