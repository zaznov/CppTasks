//============================================================================
// Name        : red_week1_table_templates.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "test_runner.h"

using namespace std;
#include <iostream>
#include <vector>


template <typename T>
class Table{
public:
	Table(size_t strings, size_t rows): strings(strings), rows(rows){
		Resize(strings, rows);
		/*table.resize(strings);
		for(size_t i = 0; i < strings; i++){
			table[i].resize(rows);
		}*/

	}
	Table(): strings(0), rows(0){
	}
	void Resize(size_t strings_, size_t rows_){
		table.resize(strings_);
		for(size_t i = 0; i < strings_; i++){
			table[i].resize(rows_);
		}
	strings = strings_;
	rows = rows_;
	}

	pair<size_t, size_t> Size(){
		if(strings == 0 || rows == 0) {
			strings =0;
			rows = 0;
		}
		return make_pair(strings, rows);
	}


	vector<T>& operator[] (const int index);
private:
	size_t strings;

	size_t rows;

	vector<vector<T>> table;
};

template <typename T>
vector<T>& Table<T>::operator[] (const int index)
{
    return table[index];
}



void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
/*	size_t str = 3;
	size_t rw = 3;
	Table<int> t(str, rw);


	for(size_t i = 0; i < str; i++){
		for(size_t j = 0; j < rw; j++){
			t[i][j] = rw*i+j;
			cout << t[i][j] << ",";
		}
		cout <<  endl;
	}

	cout <<  endl;
	str = 7;
	rw = 7;
	t.Resize(str, rw);


	for(size_t i = 0; i < str; i++){
		for(size_t j = 0; j < rw; j++){
			cout << t[i][j] << ",";
		}
		cout <<  endl;
	}

	cout <<  endl;
	str = 5;
	rw = 5;
	t.Resize(str, rw);


	for(size_t i = 0; i < str; i++){
		for(size_t j = 0; j < rw; j++){
			cout << t[i][j] << ",";
		}
		cout <<  endl;
	}

	auto size = t.Size();
	cout << size.first << endl;
	cout << size.second << endl;
*/
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}

