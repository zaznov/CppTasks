/*
 * token.h
 *
 *  Created on: 11 ����. 2021 �.
 *      Author: NPK1
 */

#ifndef TOKEN_H_
#define TOKEN_H_


#include <sstream>
#include <vector>
using namespace std;

enum class TokenType {
  DATE,
  EVENT,
  COLUMN,
  LOGICAL_OP,
  COMPARE_OP,
  PAREN_LEFT,
  PAREN_RIGHT,
};





struct Token {
  const string value;
  const TokenType type;
};

vector<Token> Tokenize(istream& cl);

ostream& operator << (ostream& stream, const Token& token);

#endif /* TOKEN_H_ */
