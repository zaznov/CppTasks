/*
 * Mytests.h
 *
 *  Created on: 24 рту. 2021 у.
 *      Author: NPK1
 */

#ifndef MYTESTS_H_
#define MYTESTS_H_

#include <exception>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <string>
using namespace std;


template <typename T_of_set>
ostream& operator << (ostream& os, const set<T_of_set>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class Key, class Value>
ostream& operator << (ostream& os, const map<Key, Value>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template <typename T_of_vector>
ostream& operator << (ostream& out, const vector<T_of_vector>& vect){
	out << "{";
	bool first = true;
	for (const auto& val : vect) {
		if (!first) {
			out << ", ";
		}
		first = false;
		out << val;
	}
	out << "}";
	return out;
}




class TestRunner {
public:
	TestRunner();
	template <typename Func_typ>
	void Runtest(Func_typ Func, const string& func_name){
		try{
			Func();
			cerr << func_name << " is OK." << endl;
		}catch(runtime_error& e){
			fail_counter++;
			cerr << "Fail: " << func_name << e.what() << endl;

		}
	}
	~TestRunner();
private:
	int fail_counter;
};


template <typename F, typename S>
void Assert_is_Equal(const F& first, const S& second, const string& hint) {
  if (first != second) {
    ostringstream os;
    os << "Assertion failed: " << first << " != " << second << " hint: " << hint;
    throw runtime_error(os.str());
  }
}

inline void Assert_is_true(bool b, const string& hint) {
	Assert_is_Equal(b, true, hint);
}




#endif /* MYTESTS_H_ */
