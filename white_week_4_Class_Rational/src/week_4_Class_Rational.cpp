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
using namespace std;

/*class Rational {
public:
    Rational() {
    	numerator = 0;
    	denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
    	Refresh(new_numerator, new_denominator);
    	//cout << "for " << new_numerator << " and " << new_denominator << " NOD is " << NOD << endl;
    }
    void Refresh(int new_numerator, int new_denominator){
    	//numerator = new_numerator;
		//denominator = new_denominator;
    	if(new_denominator == 0) new_denominator = 1;
		int NOD = gcd(new_numerator, new_denominator);
		numerator 	= new_numerator / NOD;
		denominator = new_denominator / NOD;
		if (denominator<0){
			denominator *= -1;
			numerator *= -1;
		}
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
    	return denominator;
    }
    void Set_Numerator(int new_numerator) {
    	//numerator = new_numerator;
    	Refresh(new_numerator, denominator);
    }

    void Set_Denominator(int new_denominator) {
    	//denominator = new_denominator;
    	Refresh(numerator, new_denominator);
    }

private:
    int numerator;
    int denominator;
};


Rational operator + (const Rational& lhs, const Rational& rhs){
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
	if((new_denominator == 0) ||(sign != '/')) {

	}else{
		rational.Set_Numerator(new_numerator);
		rational.Set_Denominator(new_denominator);
	}


	return stream;
}

bool operator < (const Rational& lhs, const Rational& rhs){
	if(lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator()){
		return true;
	}else{
		return false;
	}
}
*/
int main() {
	Rational_1 r1;
	cout << r1 << endl;
    cout << "OK" << endl;
    return 0;
}
