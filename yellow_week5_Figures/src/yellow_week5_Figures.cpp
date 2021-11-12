//============================================================================
// Name        : yellow_week5_Figures.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <istream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


class Figure{
public:
	Figure(string type) : Name_(type){

	}
	string 	Name() {
		return this->Name_;
	}
	virtual double 	Perimeter() const = 0;
	virtual double 	Area() const = 0;
protected:
	const string 		Name_;
};

class Rect : public Figure{
public:
	Rect(double width, double height) : 	Figure("RECT"),
									width_(width),
									height_(height){
	}
	double Perimeter  () const override{
		return (width_ + height_)* 2;
	}
	double Area () const override{
		return width_ * height_;
	}
private:
	const double width_;
	const double height_;

};

class Rriang  : public Figure{
public:
	Rriang(double a, double b, double c) : 	Figure("TRIANGLE"),
									a_(a),
									b_(b),
									c_(c){
	}
	double Perimeter  () const override{
		return a_ + b_ + c_;
	}
	double Area () const override{
		double  p = (a_ + b_ + c_)/2;
		double S = sqrt(p * (p - a_) * (p - b_) * (p - c_));
		return S;
	}
private:
	const double a_;
	const double b_;
	const double c_;

};


class Circle : public Figure{
public:
	Circle(double r) : 	Figure("CIRCLE"),
						radius_(r){
	}
	double Perimeter  () const override{
		return 2 * 3.14 * radius_;
	}
	double Area () const override{
		return 3.14 * radius_ * radius_;
	}
private:
	const double radius_;

};



shared_ptr<Figure> CreateFigure(istringstream& ss){
	string type;
	ss >> type;
	if(type == "RECT"){
		double w;
		double h;
		ss >> w;
		ss >> h;
		return make_shared<Rect>(w,h);
	}else if(type == "TRIANGLE"){
		double a;
		double b;
		double c;
		ss >> a >> b >> c;
		return make_shared<Rriang>(a,b,c);
	}else if(type == "CIRCLE"){
		double radius;
		ss >> radius;
		return make_shared<Circle>(radius);
	}
	else{
		throw std::invalid_argument( "no such a figure!" );
	}
}


int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      is >> ws; // https://en.cppreference.com/w/cpp/io/manip/ws
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
