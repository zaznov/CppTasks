//============================================================================
// Name        : yellow_week1_regions.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;


enum class Lang {
	  DE, FR, IT
	};

	struct Region_t {
	  string std_name;
	  string parent_std_name;
	  map<Lang, string> names;
	  int64_t population;
	};

	tuple<string, string, map<Lang, string>,int64_t> get_rank(Region_t Region){
		return tie(Region.std_name, Region.parent_std_name, Region.names, Region.population);
	};


	bool operator == (const Region_t& lhs, const Region_t& rhs){
		return get_rank(lhs) == get_rank(rhs);
	}


int FindMaxRepetitionCount(const vector<Region_t>& regions){

	int max = 0;
	int counter = 0;
	for(auto i :regions){
		counter = count(begin(regions), end(regions), i);
		if(counter > max) {
			max = counter;
		}
		counter = 0;
	}

	return max;
};


int main() {

	cout << FindMaxRepetitionCount({
	      {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Russia",
	          "Eurasia",
	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Russia",
	          "Eurasia",
	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	          89
	      },
	  }) << endl;


	cout << FindMaxRepetitionCount({
	      {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Russia",
	          "Eurasia",
	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Toulouse",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          31
	      },
	  }) << endl;


	  cout << FindMaxRepetitionCount({}) << endl;

	return 0;
}
