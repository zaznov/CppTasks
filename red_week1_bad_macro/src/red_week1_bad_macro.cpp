//============================================================================
// Name        : red_week1_bad_macro.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) (out << (x) << endl << (y) << endl)

int main() {
  /*TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    PRINT_VALUES(output, 5, "red belt");
    ASSERT_EQUAL(output.str(), "5\nred belt\n");
  }, "PRINT_VALUES usage example");*/

	int x = 5;
	if(x == 5)
		PRINT_VALUES(cout, x, x);
	else
		cout << "end";


  return 0;
}
