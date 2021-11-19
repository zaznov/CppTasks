/*
 * condition_parser_test.cpp
 *
 *  Created on: 11 но€б. 2021 г.
 *      Author: NPK1
 */


/*

#include "condition_parser.h"
#include "Mytests.h"

#include <sstream>
using namespace std;

void TestParseCondition() {
  {
    istringstream is("date != 2017-11-18");
    shared_ptr<Node> root = ParseCondition(is);
    Assert_is_Equal(root->Evaluate({2017, 1, 1}, ""), "Parse condition 1");
    Assert_is_Equal(!root->Evaluate({2017, 11, 18}, ""), "Parse condition 2");
  }
  {
    istringstream is(R"(event == "sport event")");
    shared_ptr<Node> root = ParseCondition(is);
    Assert_is_Equal(root->Evaluate({2017, 1, 1}, "sport event"), "Parse condition 3");
    Assert_is_Equal(!root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 4");
  }
  {
    istringstream is("date >= 2017-01-01 AND date < 2017-07-01");
    shared_ptr<Node> root = ParseCondition(is);
    Assert_is_Equal(root->Evaluate({2017, 1, 1}, ""), "Parse condition 5");
    Assert_is_Equal(root->Evaluate({2017, 3, 1}, ""), "Parse condition 6");
    Assert_is_Equal(root->Evaluate({2017, 6, 30}, ""), "Parse condition 7");
    Assert_is_Equal(!root->Evaluate({2017, 7, 1}, ""), "Parse condition 8");
    Assert_is_Equal(!root->Evaluate({2016, 12, 31}, ""), "Parse condition 9");
  }
  {
    istringstream is(R"(event != "sport event" AND event != "Wednesday")");
    shared_ptr<Node> root = ParseCondition(is);
    Assert_is_Equal(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 10");
    Assert_is_Equal(!root->Evaluate({2017, 1, 1}, "sport event"), "Parse condition 11");
    Assert_is_Equal(!root->Evaluate({2017, 1, 1}, "Wednesday"), "Parse condition 12");
  }
  {
    istringstream is(R"(event == "holiday AND date == 2017-11-18")");
    shared_ptr<Node> root = ParseCondition(is);
    Assert_is_Equal(!root->Evaluate({2017, 11, 18}, "holiday"), "Parse condition 13");
    Assert_is_Equal(!root->Evaluate({2017, 11, 18}, "work day"), "Parse condition 14");
    Assert_is_Equal(root->Evaluate({1, 1, 1}, "holiday AND date == 2017-11-18"), "Parse condition 15");
  }
  {
    istringstream is(R"(((event == "holiday" AND date == 2017-01-01)))");
    shared_ptr<Node> root = ParseCondition(is);
    Assert_is_Equal(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 16");
    Assert_is_Equal(!root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 17");
  }
  {
    istringstream is(R"(date > 2017-01-01 AND (event == "holiday" OR date < 2017-07-01))");
    shared_ptr<Node> root = ParseCondition(is);
    Assert_is_Equal(!root->Evaluate({2016, 1, 1}, "holiday"), "Parse condition 18");
    Assert_is_Equal(root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 19");
    Assert_is_Equal(root->Evaluate({2017, 1, 2}, "workday"), "Parse condition 20");
    Assert_is_Equal(!root->Evaluate({2018, 1, 2}, "workday"), "Parse condition 21");
  }
  {
    istringstream is(R"(date > 2017-01-01 AND event == "holiday" OR date < 2017-07-01)");
    shared_ptr<Node> root = ParseCondition(is);
    Assert_is_Equal(root->Evaluate({2016, 1, 1}, "event"), "Parse condition 22");
    Assert_is_Equal(root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 23");
    Assert_is_Equal(root->Evaluate({2017, 1, 2}, "workday"), "Parse condition 24");
    Assert_is_Equal(!root->Evaluate({2018, 1, 2}, "workday"), "Parse condition 25");
  }
  {
    istringstream is(R"(((date == 2017-01-01 AND event == "holiday")))");
    shared_ptr<Node> root = ParseCondition(is);
    Assert_is_Equal(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 26");
    Assert_is_Equal(!root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 27");
  }
  {
    istringstream is(R"(((event == "2017-01-01" OR date > 2016-01-01)))");
    shared_ptr<Node> root = ParseCondition(is);
    Assert_is_Equal(root->Evaluate({1, 1, 1}, "2017-01-01"), "Parse condition 28");
    Assert_is_Equal(!root->Evaluate({2016, 1, 1}, "event"), "Parse condition 29");
    Assert_is_Equal(root->Evaluate({2016, 1, 2}, "event"), "Parse condition 30");
  }
}

*/
