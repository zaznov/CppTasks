//============================================================================
// Name        : week_3_ReversibleString.cpp
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

using namespace std;


class ReversibleString{
	public:
	ReversibleString(){
		str = "";
	}
	ReversibleString(const string& str_in){
		str = str_in;
	}
	void Reverse(){
		reverse(str.begin(), str.end());
	}
	string ToString () const {
			return str;
		}
	private:
	string str;
};




int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
