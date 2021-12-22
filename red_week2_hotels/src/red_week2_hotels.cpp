//============================================================================
// Name        : red_week2_hotels.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>

#include <iostream>
using namespace std;

struct Order{
	Order(){
		time = 0;
		client_id = 0;
		room_count = 0;
	}
	Order(long long time_, unsigned int client_id_, short room_count_){
		time = time_;
		client_id = client_id_;
		room_count = room_count_;
	}
	long long time;
	unsigned int client_id;
	short room_count;
};

class BookingManager {	//количество запросов Q — натуральное число, не превосходящее 10^5
public:
	BookingManager(){
	}

	void book(long long time, string hotelName, unsigned int client_id, short room_count){
		hotel_to_Orders[hotelName].push(Order(time, client_id, room_count));	//O(logQ)
		hotel_to_Rooms[hotelName] += room_count;								//O(logQ)
		hotel_to_Clients_to_orders[hotelName][client_id]++;						//O(log(Q)^2)
		Adjust_time(time);
	}
	unsigned int clients(string hotelName){
		return hotel_to_Clients_to_orders[hotelName].size();	//O(logQ)
	}
	short rooms(string hotelName){
		return hotel_to_Rooms[hotelName];	//O(logQ)
	}

private:
	map<string, queue<Order>> hotel_to_Orders;
	map<string, short> hotel_to_Rooms;
	map<string, map<int,int>> hotel_to_Clients_to_orders;
	void Adjust_time(long long time){
		for(auto hotel : hotel_to_Orders){	//O(Q)
			while(!hotel.second.empty() && hotel.second.front().time <= time - 86400){	//O(Q)
				//cout << "For " << hotel.first << " and client_id = " << hotel.second.front().client_id << ", time <= time - 86400 = " << time - 86400 << endl;
				hotel_to_Rooms[hotel.first] -= hotel.second.front().room_count;
				hotel_to_Clients_to_orders[hotel.first].at(hotel.second.front().client_id)--;
				if(hotel_to_Clients_to_orders[hotel.first].at(hotel.second.front().client_id) == 0){
					hotel_to_Clients_to_orders[hotel.first].erase(hotel.second.front().client_id);
				}
				hotel.second.pop();
			}
		}
	}
};

int main() {
	BookingManager mBookingManager;
	  cout << "lests start" << endl;
	  int query_count;
	  cin >> query_count;
	  for (int query_id = 0; query_id < query_count; ++query_id) {
	    string query_type;
	    cin >> query_type;
	    if (query_type == "BOOK") {
	      long long time;
	      string hotelName;
	      unsigned int client_id;
	      short room_count;
	      cin >> time;
	      cin >> hotelName;
	      cin >> client_id;
	      cin >> room_count;
	      mBookingManager.book(time, hotelName, client_id, room_count);
	    } else if (query_type == "CLIENTS") {
		  string hotelName;
		  cin >> hotelName;
	      cout << "CLIENTS in " << hotelName << " " << mBookingManager.clients(hotelName) << endl;
	    }else if (query_type == "ROOMS") {
		  string hotelName;
		  cin >> hotelName;
		  cout << "ROOMS in " << hotelName << " " << mBookingManager.rooms(hotelName) << "\n";
		}
	  }

	  return 0;
}
