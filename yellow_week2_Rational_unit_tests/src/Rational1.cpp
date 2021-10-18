/*
 * Rational1.cpp
 *
 *  Created on: 19 апр. 2021 г.
 *      Author: HFE-RM
 */

#include "Rational1.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;


Rational_1::Rational_1() {
	numerator = 0;
	denominator = 1;
}
Rational_1::Rational_1(int new_numerator, int new_denominator) {
    	Refresh(new_numerator, new_denominator);
    }
void Rational_1::Refresh(int new_numerator, int new_denominator){
    	if(new_denominator == 0) new_denominator = 1;
		int NOD = gcd(new_numerator, new_denominator);
		numerator 	= new_numerator / NOD;
		denominator = new_denominator / NOD;
		if (denominator<0){
			denominator *= -1;
			numerator *= -1;
		}
    }
int Rational_1::Numerator() const{
        return numerator;
    }
int Rational_1::Denominator()  const{
    	return denominator;
    }
void Rational_1::Set_Numerator(int new_numerator) {
    	Refresh(new_numerator, denominator);
    }
void Rational_1::Set_Denominator(int new_denominator) {
    	Refresh(numerator, new_denominator);
    }








Rational_1 operator + (const Rational_1& lhs, const Rational_1& rhs) {
	int new_denominator = lhs.Denominator() * rhs.Denominator();
	int new_numerator = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
	Rational_1 rezult(new_numerator, new_denominator);
	return rezult;

}

Rational_1 operator - (const Rational_1& lhs, const Rational_1& rhs){
	int new_denominator = lhs.Denominator() * rhs.Denominator();
		int new_numerator = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
		Rational_1 rezult(new_numerator, new_denominator);
	return rezult;
}

Rational_1 operator * (const Rational_1& lhs, const Rational_1& rhs){
	int new_denominator = lhs.Denominator() * rhs.Denominator();
	int new_numerator = lhs.Numerator() * rhs.Numerator();
	Rational_1 rezult(new_numerator, new_denominator);
	return rezult;
}

Rational_1 operator / (const Rational_1& lhs, const Rational_1& rhs){
	int new_denominator = lhs.Denominator() * rhs.Numerator();
	int new_numerator = lhs.Numerator() * rhs.Denominator();
	Rational_1 rezult(new_numerator, new_denominator);
	return rezult;
}

bool operator == (const Rational_1& lhs, const Rational_1& rhs){
	if(	lhs.Denominator() == rhs.Denominator() &&  lhs.Numerator() == rhs.Numerator()){
		return true;
	}
	return false;
}

ostream& operator << (ostream& stream, const Rational_1& rational){
	stream << rational.Numerator();
	stream << "/";
	stream << rational.Denominator();
	return stream;
}

istream& operator >> (istream& stream, Rational_1& rational){
	int new_numerator = 0;
	int new_denominator = 0;
	char sign;
	stream >> new_numerator;
	sign = stream.get();
	stream >> new_denominator;
	if((new_denominator == 0) ||(sign != '/')) {

	}else{
		rational.Set_Numerator(new_numerator);
		rational.Set_Denominator(new_denominator);
	}


	return stream;
}

bool operator < (const Rational_1& lhs, const Rational_1& rhs){
	if(lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator()){
		return true;
	}else{
		return false;
	}
}
