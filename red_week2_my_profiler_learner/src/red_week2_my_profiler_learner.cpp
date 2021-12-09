//============================================================================
// Name        : red_week2_my_profiler_learner.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include "profile.h"

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    for (const auto& word : words) {
    	dict.insert(word);
    }
    return dict.size();
  }

  vector<string> KnownWords() {
    //return dict;
	  return {dict.begin(), dict.end()};
  }
};



int main() {
  Learner learner;
  string line;
  stringstream input;
  {
	  LOG_DURATION("Build stream");
	  for (int i = 0; i < 10000; ++i) {
		input << "word" << i << ' ';
	  }
  }

	  while (getline(input, line)) {
		vector<string> words;
		stringstream ss(line);
		string word;
		{
			LOG_DURATION("Build vector");
			while (ss >> word) {
			  words.push_back(word);
			}
		}
		{
			LOG_DURATION("Writing");
			cout << "Total words = " << learner.Learn(words) << "\n";
		}
  }
  cout << "=== known words ===\n";
  for (auto word : learner.KnownWords()) {
    cout << word << "\n";
  }
}
