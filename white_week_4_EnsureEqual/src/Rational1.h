/*
 * Rational1.h
 *
 *  Created on: 19 апр. 2021 г.
 *      Author: HFE-RM
 */

#ifndef RATIONAL1_H_
#define RATIONAL1_H_


#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;
class Rational {
public:
    Rational();
    Rational(int new_numerator, int new_denominator);
    void Refresh(int new_numerator, int new_denominator);
    int Numerator()const;
    int Denominator()const;
    void Set_Numerator(int new_numerator);
    void Set_Denominator(int new_denominator);
private:
    int numerator;
    int denominator;
};


Rational 	operator + (const Rational& lhs, const Rational& rhs);
Rational 	operator - (const Rational& lhs, const Rational& rhs);
Rational 	operator * (const Rational& lhs, const Rational& rhs);
Rational 	operator / (const Rational& lhs, const Rational& rhs);
bool 		operator == (const Rational& lhs, const Rational& rhs);
ostream& 	operator << (ostream& stream, const Rational& rational);
istream& 	operator >> (istream& stream, Rational& rational);
bool 		operator < (const Rational& lhs, const Rational& rhs);


#endif /* RATIONAL1_H_ */
