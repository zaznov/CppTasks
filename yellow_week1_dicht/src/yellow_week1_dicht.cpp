//============================================================================
// Name        : yellow_week1_dicht.cpp
// Author      : hh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
using namespace std;



int main() {
	cout << "sdf" << endl;
	uint32_t ammount = 0;
	uint64_t dicht = 0;
	cin >> ammount;
	cin >> dicht;

	uint64_t mass = 0;
	uint64_t W = 0;
	uint64_t H = 0;
	uint64_t D = 0;

	for(uint32_t i = 0; i < ammount; i++){
		cin >> W;
		cin >> H;
		cin >> D;

		mass += W*H*D*dicht;
	}
	cout << endl;
	cout << mass;
	cout << endl;
	return 0;
}
