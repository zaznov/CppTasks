//============================================================================
// Name        : week_3_training.cpp
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

class SortedStrings {
public:
  void AddString(const string& s) {
	  my_strings.push_back(s);
  }
  vector<string> GetSortedStrings() {
	  sort(begin(my_strings), end(my_strings));
	  return my_strings;
  }
private:
  vector<string> my_strings;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("aecond");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);
  return 0;
}
