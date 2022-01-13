//============================================================================
// Name        : red_week4_TestEditor.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <sstream>
#include <iostream>
#include "test_runner.h"
using namespace std;

class Editor {
 public:

  Editor(){
	  curent_position = editor.begin();

  }
  void Left(){
	  if (editor.size() > 0) curent_position--;

  }
  void Right(){
	  if (curent_position != editor.end() /*and curent_position != prev(editor.end())*/) curent_position++;
  }
  void Insert(char token){
	  //editor.insert(curent_position, token);
	  curent_position = next(editor.insert(curent_position, token));
  }
  void Cut(size_t tokens = 1){
	  clipboard.clear();
	 while(tokens-- > 0){
		  clipboard.push_back(*curent_position++);
		  editor.erase(prev(curent_position));
		  if(curent_position == editor.end()) break;
	  }
  }
  void Copy(size_t tokens = 1){
	  clipboard.clear();

	  auto end_iterator = next(curent_position, tokens);
	  clipboard = {curent_position, end_iterator};

	  /*while(tokens-- > 0){
		  clipboard.push_back(*curent_position++);
		  if(curent_position == editor.end()) break;
	  }*/

  }
  void Paste(){

	  while(!clipboard.empty()){
		  editor.insert(curent_position, clipboard.front());
		  clipboard.pop_front();
	  }
	  clipboard.clear();
  }
  string GetText() const{

	  /*
	  stringstream st;
	  for(auto i : editor){
		  st << i;
	  }
	  return st.str();
	  */
	  return {editor.begin(), editor.end()};
  }
private:
  list<char>::iterator curent_position;
  list<char> editor;
  list<char> clipboard;

};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {

    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);

    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);
    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;

    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }

  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");

  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();

  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();

  ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);





  return 0;
}
