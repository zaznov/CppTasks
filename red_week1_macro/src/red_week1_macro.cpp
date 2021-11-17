//============================================================================
// Name        : red_week1_macro.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "test_runner.h"
#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) {
	  log_line = value;

  }
  void SetLogFile(bool value) {
	  log_file= value;
  }

  void Log(const string& message){
	  stringstream ss(message);
	  string file;
	  string line;
	  string local_message;
	  ss >> file >> line >> local_message;


	  if((log_line) && (log_file)){
		  os << file << ":" << line << " ";
	  }
	  if((log_line) && (!log_file)){
		  os << "Line " << line << " ";
	  }
	  if((!log_line) && (log_file)){
		  os << file << " ";
	  }

	  os << local_message <<"\n";

  }

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};


#define STRINGIZE_DETAIL(x) #x
#define STRINGIZE(x) STRINGIZE_DETAIL(x)

#define LOG(logger, message) {										\
	string str = (__FILE__ " " STRINGIZE(__LINE__)  " " message); 	\
	logger.Log(str);												\
}

void TestLog() {

#line 1 "logger.cpp"

  ostringstream logs;
  Logger l(logs);
  LOG(l, "hello");

  l.SetLogFile(true);
  LOG(l, "hello");

  l.SetLogLine(true);
  LOG(l, "hello");

  l.SetLogFile(false);
  LOG(l, "hello");

  string expected = "hello\n";
  expected += "logger.cpp hello\n";
  expected += "logger.cpp:10 hello\n";
  expected += "Line 13 hello\n";

  ASSERT_EQUAL(logs.str(), expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestLog);
}
