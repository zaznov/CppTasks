/*
 * token.cpp
 *
 *  Created on: 11 ????. 2021 ?.
 *      Author: NPK1
 */



#include "token.h"

#include <stdexcept>

using namespace std;

vector<Token> Tokenize(istream& cl) {
  vector<Token> tokens;

  char c;
  while (cl >> c) {
    if (isdigit(c)) {
      string date(1, c);
      for (int i = 0; i < 3; ++i) {
        while (isdigit(cl.peek())) {
          date += cl.get();
        }
        if (i < 2) {
          date += cl.get(); // Consume '-'
        }
      }
      tokens.push_back({date, TokenType::DATE});
    } else if (c == '"') {
      string event;
      getline(cl, event, '"');
      tokens.push_back({event, TokenType::EVENT});
    } else if (c == 'd') {
      if (cl.get() == 'a' && cl.get() == 't' && cl.get() == 'e') {
        tokens.push_back({"date", TokenType::COLUMN});
      } else {
        throw logic_error("Unknown token");
      }
    } else if (c == 'e') {
      if (cl.get() == 'v' && cl.get() == 'e' && cl.get() == 'n' &&
          cl.get() == 't') {
        tokens.push_back({"event", TokenType::COLUMN});
      } else {
        throw logic_error("Unknown token");
      }
    } else if (c == 'A') {
      if (cl.get() == 'N' && cl.get() == 'D') {
        tokens.push_back({"AND", TokenType::LOGICAL_OP});
      } else {
        throw logic_error("Unknown token");
      }
    } else if (c == 'O') {
      if (cl.get() == 'R') {
        tokens.push_back({"OR", TokenType::LOGICAL_OP});
      } else {
        throw logic_error("Unknown token");
      }
    } else if (c == '(') {
      tokens.push_back({"(", TokenType::PAREN_LEFT});
    } else if (c == ')') {
      tokens.push_back({")", TokenType::PAREN_RIGHT});
    } else if (c == '<') {
      if (cl.peek() == '=') {
        cl.get();
        tokens.push_back({"<=", TokenType::COMPARE_OP});
      } else {
        tokens.push_back({"<", TokenType::COMPARE_OP});
      }
    } else if (c == '>') {
      if (cl.peek() == '=') {
        cl.get();
        tokens.push_back({">=", TokenType::COMPARE_OP});
      } else {
        tokens.push_back({">", TokenType::COMPARE_OP});
      }
    } else if (c == '=') {
      if (cl.get() == '=') {
        tokens.push_back({"==", TokenType::COMPARE_OP});
      } else {
        throw logic_error("Unknown token");
      }
    } else if (c == '!') {
      if (cl.get() == '=') {
        tokens.push_back({"!=", TokenType::COMPARE_OP});
      } else {
        throw logic_error("Unknown token");
      }
    }
  }

  return tokens;
}


ostream& operator << (ostream& stream, const Token& token){
	if(token.type == TokenType::DATE) stream << "DATE";
	else if(token.type == TokenType::EVENT) stream << "EVENT";
	else if(token.type == TokenType::COLUMN) stream << "COLUMN";
	else if(token.type == TokenType::LOGICAL_OP) stream << "LOGICAL_OP";
	else if(token.type == TokenType::COMPARE_OP) stream << "COMPARE_OP";
	else if(token.type == TokenType::PAREN_LEFT) stream << "PAREN_LEFT";
	else if(token.type == TokenType::PAREN_RIGHT) stream << "PAREN_RIGHT";
	stream << ' ' << token.value;
	return stream;
}
