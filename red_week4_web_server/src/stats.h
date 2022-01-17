/*
 * stats.h
 *
 *  Created on: 14 янв. 2022 г.
 *      Author: NPK1
 */

#ifndef STATS_H_
#define STATS_H_

#include "http_request.h"

#include <string_view>
#include <map>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

enum m_metods {		//это тип
	GET,
	PUT,
	POST,
	DELETE,
	UNKNOWN
  };
enum m_uri {		//это тип
	nichts,
	order,
	product,
	basket,
	help,
	unknown
  };


class Stats {
public:
  Stats(){
	  methodStats = {{"GET", 0}, {"POST", 0}, {"PUT", 0}, {"DELETE", 0}, {"UNKNOWN", 0}};
	  uriStats = {{"/", 0}, {"/order", 0}, {"/product", 0}, {"/basket", 0}, {"/help", 0}, {"unknown", 0}};
  }
  void AddMethod(string_view method){
	  if(method == "GET" or method == "PUT" or method == "POST" or method == "DELETE") {
		  methodStats[method]++;
	  }
	  else {
		  methodStats["UNKNOWN"]++;
	  }
}
  void AddUri(string_view uri){
	  if(uri == "/" or uri == "/order" or uri == "/product" or uri == "/basket" or uri == "/help") {
		  uriStats[uri]++;
	  }
	  else {
		  uriStats["unknown"]++;
	  }
  }
  const map<string_view, int>& GetMethodStats() const{
	  return methodStats;
  }
  const map<string_view, int>& GetUriStats() const{
	  return uriStats;
  }
private:
  map<string_view, int> methodStats;
  map<string_view, int> uriStats;
};




//"POST /order HTTP/1.1"
//GET / HTTP/1.1
HttpRequest ParseRequest(string_view line){
	//cout << "whole line is = " << line <<endl;
	HttpRequest result;
	size_t space = line.find(' ', 0);
	while(space == 0){
		line.remove_prefix(space + 1);
		space = line.find(' ', 0);
	}
	//cout << "space 1 = " << space << endl;
	result.method = line.substr(0, space);
	line.remove_prefix(space + 1);

	space = line.find(' ', 0);
	//cout << "space 2 = " << space << endl;
	result.uri = line.substr(0, space);
	line.remove_prefix(space + 1);

	result.protocol = line.substr(0, line.npos);

	//cout << "new request with result.metod = <<" << result.method << ">> and result.uri = <<" << result.uri << ">> and result.protocol = <<" << result.protocol << ">>" <<endl;
	return result;
}



#endif /* STATS_H_ */









