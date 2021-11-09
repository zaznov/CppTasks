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
class Rational_1 {
public:
    Rational_1();
    Rational_1(int new_numerator, int new_denominator);
    void Refresh(int new_numerator, int new_denominator);
    int Numerator()const;
    int Denominator()const;
    void Set_Numerator(int new_numerator);
    void Set_Denominator(int new_denominator);
private:
    int numerator;
    int denominator;
};


Rational_1 	operator + (const Rational_1& lhs, const Rational_1& rhs);
Rational_1 	operator - (const Rational_1& lhs, const Rational_1& rhs);
Rational_1 	operator * (const Rational_1& lhs, const Rational_1& rhs);
Rational_1 	operator / (const Rational_1& lhs, const Rational_1& rhs);
bool 		operator == (const Rational_1& lhs, const Rational_1& rhs);
ostream& 	operator << (ostream& stream, const Rational_1& rational);
istream& 	operator >> (istream& stream, Rational_1& rational);
bool 		operator < (const Rational_1& lhs, const Rational_1& rhs);


#endif /* RATIONAL1_H_ */
