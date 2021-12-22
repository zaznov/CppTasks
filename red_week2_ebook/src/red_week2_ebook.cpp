//============================================================================
// Name        : red_week2_ebook.cpp
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

using namespace std;
/*
class ReadingManager {
public:
  ReadingManager()
      : user_page_counts_(MAX_USER_COUNT_ + 1, 0),		// индекс в векторе - номер пользователя, значение -страница до которой он дочитал
        sorted_users_(),								// векотор отсортированных юзеров
        user_positions_(MAX_USER_COUNT_ + 1, -1) {}		// размер до 100 000

  void Read(int user_id, int page_count) {
    if (user_page_counts_[user_id] == 0) {
      AddUser(user_id);
    }
    user_page_counts_[user_id] = page_count;
    int& position = user_positions_[user_id];
    while (position > 0 && page_count > user_page_counts_[sorted_users_[position - 1]]) {	// O(N)
      SwapUsers(position, position - 1);													// O(1)
    }
  }

  double Cheer(int user_id) const {
    if (user_page_counts_[user_id] == 0) {
      return 0;
    }
    const int user_count = GetUserCount();
    if (user_count == 1) {
      return 1;
    }
    const int page_count = user_page_counts_[user_id];
    int position = user_positions_[user_id];
    while (position < user_count &&
      user_page_counts_[sorted_users_[position]] == page_count) {							// O(N)
      ++position;
    }
    if (position == user_count) {
        return 0;
    }

    return (user_count - position) * 1.0 / (user_count - 1);
  }

private:

  static const int MAX_USER_COUNT_ = 100'000;

  vector<int> user_page_counts_;
  vector<int> sorted_users_;
  vector<int> user_positions_;


  int GetUserCount() const {
    return sorted_users_.size();
  }
  void AddUser(int user_id) {
    sorted_users_.push_back(user_id);
    user_positions_[user_id] = sorted_users_.size() - 1;
  }
  void SwapUsers(int lhs_position, int rhs_position) {
    const int lhs_id = sorted_users_[lhs_position];
    const int rhs_id = sorted_users_[rhs_position];
    swap(sorted_users_[lhs_position], sorted_users_[rhs_position]);
    swap(user_positions_[lhs_id], user_positions_[rhs_id]);
  }
};	//при Q = 10^6 запросах и числе пользователей не более 10^5 сложность = O(Q * N) = 10^11.
*/



class ReadingManager2 {
public:
  ReadingManager2()  : users_on_pages(1000, 0){}

  void Read(int user_id, int page_count) {
	  //cout << "In Read" << endl;
	  if(users_to_pages.count(user_id)){
		  if(users_to_pages[user_id] != page_count){			// O(logN)
			  users_on_pages[users_to_pages[user_id]]--;		// O(logM)
			  users_on_pages[page_count]++;						// O(logM)
			  users_to_pages[user_id] = page_count;				// O(logN)
		  }
	  }// O((logN)^2 )
	  else{
		  //cout << "added new page" << endl;
		  users_to_pages[user_id] = page_count;
		  users_on_pages[page_count]++;

		  //cout << users_to_pages.size() << endl;
		  //cout << users_on_pages.size() << endl;
	  }	//O(logN * logM)


  }	//O((logN)^2 )

  double Cheer(int user_id)  {
	  //cout << "*users_on_pages.begin() = " << *users_on_pages.begin() << endl;
	  //cout << "*users_on_pages.begin()+10 = " << *(users_on_pages.begin()+10) << endl;
	  if(users_to_pages[user_id] == 0){
		  //cout << "users_to_pages[user_id] == 0" << endl;
		  return 0;
	  }
	  if(users_to_pages.size() == 1){
		  //cout << "users_to_pages.size() == 1" << endl;
		  return 1;
	  }
	  else{
		  double less  = accumulate(users_on_pages.begin() + 1, users_on_pages.begin() + users_to_pages[user_id], 0.0);
		  //cout << "less = " << less << endl;
		  double more_or_the_same  = accumulate(users_on_pages.begin() + users_to_pages[user_id], users_on_pages. end(), 0.0);
		  //cout << "more_or_the_same = " << more_or_the_same << endl;
		  double all_users = less + more_or_the_same;
		  //cout << "all_users = " << all_users << endl;
		  if (all_users == 1) return 1;
		  double result = (less)/(all_users - 1);
		  return result;

	  }

  }	//O(M)

private:
  map<int, int> users_to_pages;
  vector<int> users_on_pages;

};		//при Q = 10^6 запросах и количестве страниц M = 10^3 сложность = O(Q * M) = 10^9.

int main() {

  //ios::sync_with_stdio(false);
  //cin.tie(nullptr);

  ReadingManager2 manager;

  cout << "lests start" << endl;
  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}
