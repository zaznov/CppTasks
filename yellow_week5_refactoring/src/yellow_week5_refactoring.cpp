//============================================================================
// Name        : yellow_week5_refactoring.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;


class Human {
public:
	Human(const string& Name, const string& Profession) : Profession_(Profession), Name_(Name){}
    void Walk(const string&  destination) const {
        cout << Profession_ << ": " << Name_ << " walks to: " << destination << endl;
    }
    const string getName() const{
    	return Name_;
    }
    const string getProfession() const{
		return Profession_;
	}
protected:
    const string Profession_;
    const string Name_;
    void doAction (const string&  action, const string&  object) const {
            cout << Profession_ << ": " << Name_ << " " << action << " " << object << endl;
        }
};



class Student : public Human {
public:
    Student(const string& Name, const string& FavouriteSong) : Human(Name, "Student"), FavouriteSong_(FavouriteSong) {}
    void Learn() const {
        doAction("learns", "");
    }
    void SingSong() const {
		doAction("sings a song:", FavouriteSong_);
	}
private:
    const string FavouriteSong_;
};


class Teacher : public Human {
public:
    Teacher(const string& Name, const string& Subject) : Human(Name, "Teacher"), Subject_(Subject) {}
    void Teach() const {
        doAction("teaches:", Subject_);
    }
private:
    const string Subject_;
};


class Policeman : public Human {
public:
    Policeman(const string& Name) : Human(Name, "Policeman") {}
    void Check(const Human& person) const {
    	doAction("checks " + person.getProfession() + ". " + person.getProfession() + "'s name is:", person.getName());
    }
};

void VisitPlaces(Human person, vector<string> places) {
    for (auto p : places) {
    	person.Walk(p);
    }
};

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
