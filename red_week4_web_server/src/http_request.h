/*
 * http_request.h
 *
 *  Created on: 14 ���. 2022 �.
 *      Author: NPK1
 */

#ifndef HTTP_REQUEST_H_
#define HTTP_REQUEST_H_


#include <string_view>
using namespace std;

struct HttpRequest {
  string_view method, uri, protocol;
};





#endif /* HTTP_REQUEST_H_ */
