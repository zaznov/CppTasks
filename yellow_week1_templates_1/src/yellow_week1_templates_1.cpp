//============================================================================
// Name        : yellow_week1_templates_1.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
using namespace std;


template <typename T>
ostream& operator << (ostream& out, const vector<T>& vect){
	for(auto i : vect){
		out << ' ' << i;
	}
	return out;
}

template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m){

	for(auto i : m){
		out << " [" << i.first << ',' << i.second << "]";
	}
	return out;
}

template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p){

		out << " {" << p.first << ',' << p.second << "}";
	return out;
}

template <typename T>
vector<T> operator * (const vector<T>& lhs,const vector<T>& rhs){
	vector<T> result = lhs;
	for(size_t i = 0; i < result.size(); i++){
		result[i] = result[i] * result[i];
		}

	return result;
}

template <typename Key, typename Value>
map<Key, Value> operator * (const map<Key, Value>& lhs,const map<Key, Value>& rhs){
	map<Key, Value> result;
	for(auto i : lhs){
		result[i.first] = i.second * i.second;
	}
	return result;
}

template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& lhs,const pair<First, Second>& rhs){
	pair<First, Second> result;
	result.first = lhs.first * lhs.first;
	result.second = lhs.second * lhs.second;
	return result;
}

template <typename sqr_type>
sqr_type Sqr(sqr_type X){
	return X * X;
}


int main() {

	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}






	/*vector<int> v = {1, 2, 3, 5, 12};
		cout << "vector:";
		cout << v;
		cout << endl;

	map<int, int> m = {{1, 5},{2, 8}, {3, 7}};
		cout << "map:";
		cout << m;
		cout << endl;

	pair<int, int> p = make_pair(5, 11);
		cout << "pair:";
		cout << p;
		cout << endl;


		cout << "Sqr vector:";
		cout << Sqr(v);
		cout << endl;

		cout << "Sqr map:";
		cout << Sqr(m);
		cout << endl;

		cout << "Sqr pair:";
		cout << Sqr(p);
		cout << endl;*/



	return 0;
}











