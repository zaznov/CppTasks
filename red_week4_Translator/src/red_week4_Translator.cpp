//============================================================================
// Name        : red_week4_Translator.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string_view>
#include "test_runner.h"
#include <string>
#include <vector>
#include <map>
#include <set>


using namespace std;


class Translator {
public:
  void Add(string_view source, string_view target){
	  auto IT_source = words.insert(string(source)).first;
	  auto IT_target = words.insert(string(target)).first;
	  forward_dict[*IT_source] = *IT_target;
	  backward_dict[*IT_target] = *IT_source;

  }
  string_view TranslateForward(string_view source) const{
	  if(forward_dict.count(source)){
		  return forward_dict.at(source);
	  }
	  else{
		  return "";
	  }
  }
  string_view TranslateBackward(string_view target) const {
	  if(backward_dict.count(target)){
		  return backward_dict.at(target);
	  }
	  else{
		  return "";
	  }
  }
private:

  map<string_view, string_view> forward_dict;	// с руск на англ
  map<string_view, string_view> backward_dict;	// с англ на руск
  set<string> words;
};

void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}


int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  return 0;
}
