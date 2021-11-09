//============================================================================
// Name        : week_4_timeServer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <exception>
//#include <system_error>
#include <fstream>
#include <iomanip>
using namespace std;

string AskTimeServer() {
	//return "15:12:13";
	throw system_error(EDOM, std::generic_category(), "hello world");
}

class TimeServer {
public:
    string GetCurrentTime() {
    	return  AskTimeServer();
    	try {
    			return last_fetched_time = AskTimeServer();
    	    } catch (system_error& e) {
    	    	return last_fetched_time;
    	    } /*catch (exception& e) {
    	    	throw system_error(error_code());
    	    }*/
    	}

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
