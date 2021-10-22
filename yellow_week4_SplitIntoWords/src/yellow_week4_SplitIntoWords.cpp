//============================================================================
// Name        : yellow_week4_SplitIntoWords.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <string>
using namespace std;



			/*First option*/
/*
vector<string> SplitIntoWords(const string& s){
	vector<string> result;
	string current_str;
	for(auto IT = s.begin(); IT != s.end(); IT++){
		if(*IT  == ' '){
			result.push_back(current_str);
			current_str.clear();
		}
		else{
			current_str +=*IT;
		}
		if(IT+1 == s.end()){
			result.push_back(current_str);
			current_str.clear();
		}
	}
	return result;
}*/

			/*Second option*/

vector<string> SplitIntoWords(const string& s){
	vector<string> result;
		string current_str;
		for(auto IT_current_begin = s.begin(); IT_current_begin != s.end(); ){
			auto IT_current_end = find(IT_current_begin, s.end(), ' ');

			current_str = string(IT_current_begin, IT_current_end);
			result.push_back(current_str);
			current_str.clear();

			if(IT_current_end != s.end()){
				IT_current_begin = IT_current_end + 1;
			}
			else{
				break;
			}
		}
	return result;
}



int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); it++) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}




























