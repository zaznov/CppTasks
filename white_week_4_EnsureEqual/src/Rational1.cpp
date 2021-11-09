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


Rational::Rational() {
	numerator = 0;
	denominator = 1;
}
Rational::Rational(int new_numerator, int new_denominator) {
    	Refresh(new_numerator, new_denominator);
    }
void Rational::Refresh(int new_numerator, int new_denominator){
		if(new_denominator == 0) throw invalid_argument("Invalid argument!!");
    	if(new_denominator == 0) new_denominator = 1;
		int NOD = gcd(new_numerator, new_denominator);
		numerator 	= new_numerator / NOD;
		denominator = new_denominator / NOD;
		if (denominator<0){
			denominator *= -1;
			numerator *= -1;
		}
    }
int Rational::Numerator() const{
        return numerator;
    }
int Rational::Denominator()  const{
    	return denominator;
    }
void Rational::Set_Numerator(int new_numerator) {
    	Refresh(new_numerator, denominator);
    }
void Rational::Set_Denominator(int new_denominator) {
    	Refresh(numerator, new_denominator);
    }








Rational operator + (const Rational& lhs, const Rational& rhs) {
	int new_denominator = lhs.Denominator() * rhs.Denominator();
	int new_numerator = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
	Rational rezult(new_numerator, new_denominator);
	return rezult;

}

Rational operator - (const Rational& lhs, const Rational& rhs){
	int new_denominator = lhs.Denominator() * rhs.Denominator();
		int new_numerator = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
		Rational rezult(new_numerator, new_denominator);
	return rezult;
}

Rational operator * (const Rational& lhs, const Rational& rhs){
	int new_denominator = lhs.Denominator() * rhs.Denominator();
	int new_numerator = lhs.Numerator() * rhs.Numerator();
	Rational rezult(new_numerator, new_denominator);
	return rezult;
}

Rational operator / (const Rational& lhs, const Rational& rhs){
	if(rhs.Numerator() == 0) throw domain_error("Division by zero!!");
	int new_denominator = lhs.Denominator() * rhs.Numerator();
	int new_numerator = lhs.Numerator() * rhs.Denominator();
	Rational rezult(new_numerator, new_denominator);
	return rezult;
}

bool operator == (const Rational& lhs, const Rational& rhs){
	if(	lhs.Denominator() == rhs.Denominator() &&  lhs.Numerator() == rhs.Numerator()){
		return true;
	}
	return false;
}

ostream& operator << (ostream& stream, const Rational& rational){
	stream << rational.Numerator();
	stream << "/";
	stream << rational.Denominator();
	return stream;
}

istream& operator >> (istream& stream, Rational& rational){
	int new_numerator = 0;
	int new_denominator = 0;
	char sign;
	stream >> new_numerator;
	sign = stream.get();
	stream >> new_denominator;
	rational.Set_Numerator(new_numerator);
	rational.Set_Denominator(new_denominator);


	return stream;
}

bool operator < (const Rational& lhs, const Rational& rhs){
	if(lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator()){
		return true;
	}else{
		return false;
	}
}
