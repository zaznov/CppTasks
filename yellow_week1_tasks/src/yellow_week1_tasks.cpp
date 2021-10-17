//============================================================================
// Name        : yellow_week1_tasks.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <tuple>
#include <utility>
#include <algorithm>


using namespace std;


// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;


class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const{
		return Persons_and_tasks.at(person);
  };

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person){
	  Persons_and_tasks.at(person)[TaskStatus::NEW]++;
  };

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){

	  TasksInfo Updated_tasks;
	  TasksInfo Not_updated_tasks = Persons_and_tasks.at(person);
	  TasksInfo All_tasks_befor = Persons_and_tasks.at(person);
	  TasksInfo All_tasks_after = Persons_and_tasks.at(person);

	  int &NEW = Persons_and_tasks.at(person)[TaskStatus::NEW];
	  int &IN_PROGRESS = Persons_and_tasks.at(person)[TaskStatus::IN_PROGRESS];
	  int &TESTING = Persons_and_tasks.at(person)[TaskStatus::TESTING];
	  int &DONE = Persons_and_tasks.at(person)[TaskStatus::DONE];

	  while(task_count-- > 0){
		  if(All_tasks_befor[TaskStatus::NEW]){
			  All_tasks_befor[TaskStatus::NEW]--;
			  All_tasks_after[TaskStatus::NEW]--;
			  All_tasks_after[TaskStatus::IN_PROGRESS]++;
			  Updated_tasks[TaskStatus::IN_PROGRESS]++;
			  Not_updated_tasks[TaskStatus::NEW]--;
		  }
		  else if(All_tasks_befor[TaskStatus::IN_PROGRESS]){
			  All_tasks_befor[TaskStatus::IN_PROGRESS]--;
			  All_tasks_after[TaskStatus::IN_PROGRESS]--;
			  All_tasks_after[TaskStatus::TESTING]++;
			  Updated_tasks[TaskStatus::TESTING]++;
			  Not_updated_tasks[TaskStatus::IN_PROGRESS]--;
		  }
		  else if(All_tasks_befor[TaskStatus::TESTING]){
			  All_tasks_befor[TaskStatus::TESTING]--;
			  All_tasks_after[TaskStatus::TESTING]--;
			  All_tasks_after[TaskStatus::DONE]++;
			  Updated_tasks[TaskStatus::DONE]++;
			  Not_updated_tasks[TaskStatus::TESTING]--;
		  }
		  /*if(All_tasks_befor[TaskStatus::DONE]){

		  }*/
	  }

Persons_and_tasks.at(person) = All_tasks_after;

		for(auto i : Updated_tasks){
			if (i.second == 0) Updated_tasks.erase(i.first);
		}
		for(auto i : Not_updated_tasks){
			if (i.second == 0) Not_updated_tasks.erase(i.first);
		}

	  Not_updated_tasks.erase(TaskStatus::DONE);

	  return tie(Updated_tasks, Not_updated_tasks);



  };

private:
  map <string, TasksInfo> Persons_and_tasks = {
		  	  	  	  	  	  	  	  	  {"Ilia",{{TaskStatus::NEW, 1}, {TaskStatus::IN_PROGRESS, 2}, {TaskStatus::TESTING, 7}, {TaskStatus::DONE, 8}}},
										  {"Alex",{{TaskStatus::NEW, 3}, {TaskStatus::IN_PROGRESS, 4}, {TaskStatus::TESTING, 9}, {TaskStatus::DONE, 10}}},
		  	  	  	  	  	  	  	  	  {"Anna",{{TaskStatus::NEW, 5}, {TaskStatus::IN_PROGRESS, 6}, {TaskStatus::TESTING, 11}, {TaskStatus::DONE, 12}}}
  	  	  	  	  	  	  	  	  	  	  };



};



int main() {


	TeamTasks TeamTasks_standart;
	TasksInfo Alexs_tasks_info = TeamTasks_standart.GetPersonTasksInfo("Alex");

	cout  << "NEW" 			<< " " << Alexs_tasks_info.at(TaskStatus::NEW) << endl;
	cout  << "IN PROGRESS" 	<< " " << Alexs_tasks_info.at(TaskStatus::IN_PROGRESS) << endl;
	cout  << "TESTING" 		<< " " << Alexs_tasks_info.at(TaskStatus::TESTING) << endl;
	cout  << "DONE" 		<< " " << Alexs_tasks_info.at(TaskStatus::DONE) << endl;
	cout  << endl;



	auto [Updated_tasks, Not_updated_tasks] = TeamTasks_standart.PerformPersonTasks("Alex", 50);
	Alexs_tasks_info = TeamTasks_standart.GetPersonTasksInfo("Alex");


	cout  << "--------------" << endl;
	cout  << "NEW" 			<< " " << Alexs_tasks_info.at(TaskStatus::NEW) << endl;
	cout  << "IN PROGRESS" 	<< " " << Alexs_tasks_info.at(TaskStatus::IN_PROGRESS) << endl;
	cout  << "TESTING" 		<< " " << Alexs_tasks_info.at(TaskStatus::TESTING) << endl;
	cout  << "DONE" 		<< " " << Alexs_tasks_info.at(TaskStatus::DONE) << endl;
	cout  << endl;


	cout  << "--------Updated_tasks------" << endl;
	cout  << "NEW" 			<< " " << Updated_tasks[TaskStatus::NEW] << endl;
	cout  << "IN PROGRESS" 			<< " " << Updated_tasks[TaskStatus::IN_PROGRESS] << endl;
	cout  << "TESTING" 			<< " " << Updated_tasks[TaskStatus::TESTING] << endl;
	cout  << "DONE" 			<< " " << Updated_tasks[TaskStatus::DONE] << endl;
	cout  << endl;

	cout  << "--------Not_updated_tasks------" << endl;
		cout  << "NEW" 			<< " " << Not_updated_tasks[TaskStatus::NEW] << endl;
		cout  << "IN PROGRESS" 			<< " " << Not_updated_tasks[TaskStatus::IN_PROGRESS] << endl;
		cout  << "TESTING" 			<< " " << Not_updated_tasks[TaskStatus::TESTING] << endl;
		cout  << "DONE" 			<< " " << Not_updated_tasks[TaskStatus::DONE] << endl;
		cout  << endl;


	return 0;
}
