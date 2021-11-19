/*
 * condition_parser.h
 *
 *  Created on: 11 ����. 2021 �.
 *      Author: NPK1
 */

#ifndef CONDITION_PARSER_H_
#define CONDITION_PARSER_H_

#include "node.h"
#include <memory>
#include <iostream>

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);

//void TestParseCondition();


#endif /* CONDITION_PARSER_H_ */
