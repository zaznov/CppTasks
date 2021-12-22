//============================================================================
// Name        : red_week2_complexity_of_algorithms_express.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "profile.h"
using namespace std;



class RouteManagerBasic {
public:
  void AddRoute(int start, int finish) {
    reachable_lists_[start].push_back(finish);
    reachable_lists_[finish].push_back(start);
  }
  int FindNearestFinish(int start, int finish) const {
    int result = abs(start - finish);
    if (reachable_lists_.count(start) < 1) {
        return result;
    }
    const vector<int>& reachable_stations = reachable_lists_.at(start);
    if (!reachable_stations.empty()) {
      result = min(
          result,
          abs(finish - *min_element(
              begin(reachable_stations), end(reachable_stations),
              [finish](int lhs, int rhs) { return abs(lhs - finish) < abs(rhs - finish); }
          ))
      );
    }
    return result;
  }
private:
  map<int, vector<int>> reachable_lists_;
};    //O(N^2)



class RouteManager {
public:
  void AddRoute(int start, int finish) {
    reachable_lists_[start].insert(finish);								//1
    reachable_lists_[finish].insert(start);
  }
  int FindNearestFinish(int start, int finish) const {
    int result = abs(start - finish);
    if (reachable_lists_.count(start) < 1) {
      return result;
    }
    const set<int>& reachable_stations = reachable_lists_.at(start); 	//logN
    const auto finish_pos = reachable_stations.lower_bound(finish);		//logN
    if (finish_pos != end(reachable_stations)) {
      result = min(result, abs(finish - *finish_pos));					//1
    }
    if (finish_pos != begin(reachable_stations)) {
      result = min(result, abs(finish - *prev(finish_pos)));			//1
    }
    return result;
  }		//2logN
private:
  map<int, set<int>> reachable_lists_;
};//O(N * logN)


class RouteManager2 {
public:

  void AddRoute(int &start, int &finish) {
    reachable_lists_[start].insert(finish);	// O(1)
    reachable_lists_[finish].insert(start);	// O(1)
  } // O(2)

  int FindNearestFinish(int &start, int &finish) const {
	int result = abs(start - finish);
    if (reachable_lists_.count(start) < 1) {	// O(logN)
        return result;
    }
    else{
    	auto IT = reachable_lists_.at(start).lower_bound(finish);	// O(logN)
    	return  min (result , min(abs(*IT - finish), abs(*prev(IT) - finish)));	// O(1)
    }
  }		//O(2 * logN)

private:
  map<int, set<int>> reachable_lists_;
};	//O(N * logN)


/*
int main() {
  RouteManager routes;
 cout << "sdf" << endl;
  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int start, finish;
    cin >> start >> finish;
    if (query_type == "ADD") {
      routes.AddRoute(start, finish);
    } else if (query_type == "GO") {
      cout << routes.FindNearestFinish(start, finish) << "\n";
    }
  }

  return 0;
}*/

int main() {
  RouteManager routes;
  RouteManager2 routes2;
  RouteManagerBasic routes3;

  const int query_count = 1000000;

  cout << "Lets start RouteManager" << endl;
  {
  	LOG_DURATION("ADD 10^5");
  	string query_type = "ADD";

  	for (int query_id = 0; query_id < query_count; ++query_id) {
  		int start = query_id;
		int finish = query_count - query_id;
  		if (query_type == "ADD") {
  			routes.AddRoute(start, finish);
  		} else if (query_type == "GO") {
  			routes.FindNearestFinish(start, finish);
  		}
  	}
  }
  {
	LOG_DURATION("GO 10^5");
	string query_type = "GO";
	for (int query_id = 0; query_id < query_count; ++query_id) {
		int start = query_id;
		int finish = query_count - query_id;
		if (query_type == "ADD") {
			routes.AddRoute(start, finish);
		} else if (query_type == "GO") {
			routes.FindNearestFinish(start, finish);
			//cout << routes.reachable_lists_.size() << endl;
		}
	}
  }
  cout << "Lets finish" << endl;

  cout << "Lets start RouteManager2" << endl;
    {
    	LOG_DURATION("ADD 10^5");
    	string query_type = "ADD";

    	for (int query_id = 0; query_id < query_count; ++query_id) {
    		int start = query_id;
  		int finish = query_count - query_id;
    		if (query_type == "ADD") {
    			routes2.AddRoute(start, finish);
    		} else if (query_type == "GO") {
    			routes2.FindNearestFinish(start, finish);
    		}
    	}
    }
    {
  	LOG_DURATION("GO 10^5");
  	string query_type = "GO";
  	for (int query_id = 0; query_id < query_count; ++query_id) {
  		int start = query_id;
  		int finish = query_count - query_id;
  		if (query_type == "ADD") {
  			routes2.AddRoute(start, finish);
  		} else if (query_type == "GO") {
  			routes2.FindNearestFinish(start, finish);
  			//cout << routes.reachable_lists_.size() << endl;
  		}
  	}
    }
    cout << "Lets finish" << endl;

    cout << "Lets start RouteManagerBasic" << endl;
        {
        	LOG_DURATION("ADD 10^5");
        	string query_type = "ADD";

        	for (int query_id = 0; query_id < query_count; ++query_id) {
        		int start = query_id;
      		int finish = query_count - query_id;
        		if (query_type == "ADD") {
        			routes3.AddRoute(start, finish);
        		} else if (query_type == "GO") {
        			routes3.FindNearestFinish(start, finish);
        		}
        	}
        }
        {
      	LOG_DURATION("GO 10^5");
      	string query_type = "GO";
      	for (int query_id = 0; query_id < query_count; ++query_id) {
      		int start = query_id;
      		int finish = query_count - query_id;
      		if (query_type == "ADD") {
      			routes3.AddRoute(start, finish);
      		} else if (query_type == "GO") {
      			routes3.FindNearestFinish(start, finish);
      			//cout << routes.reachable_lists_.size() << endl;
      		}
      	}
        }
        cout << "Lets finish" << endl;


  return 0;
}

















