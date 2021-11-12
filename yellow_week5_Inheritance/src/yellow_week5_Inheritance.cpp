//============================================================================
// Name        : yellow_week5_Inheritance.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Animal {
public:
	Animal(const string newNameAnimal)
	: Name(newNameAnimal){

	};
    const string Name;
};

class Alive {
public:
	Alive(const int Health)
	: Health_(Health){

	};
    const int Health_;
};

class Dog : public Animal, public Alive {
public:
	Dog(const string new_Name, int Health)
	: Animal(new_Name), Alive(Health){

	};
    void Bark() {
        cout << Name << " with Health " << Health_ << " barks: woof!" << endl;
    }
};

int main() {

	Dog mDog("Alex", 100);
	mDog.Bark();

	return 0;
}
