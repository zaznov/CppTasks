/*
 * node.h
 *
 *  Created on: 11 но€б. 2021 г.
 *      Author: NPK1
 */

#ifndef NODE_H_
#define NODE_H_
#include "date.h"


enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};


enum class LogicalOperation {
	Or,
	And,
};

class Node {
public:
	virtual bool Evaluate( const Date& date, const string& event) = 0;

private:
};


class EmptyNode : public Node {
public:
	bool Evaluate ( const Date& date, const string& event) override{
		return true;
	};


private:

};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison cmp, const Date& date);
	bool Evaluate ( const Date& date, const string& event) override{
		if(cmp_ == Comparison::Less && date < date_){
			return true;
		}else if (cmp_ == Comparison::LessOrEqual && date <= date_){
			return true;
		}else if (cmp_ == Comparison::Equal && date == date_){
			return true;
		}
		if(cmp_ == Comparison::Greater && date > date_){
			return true;
		}else if (cmp_ == Comparison::GreaterOrEqual && date >= date_){
			return true;
		}else if (cmp_ == Comparison::NotEqual && date != date_){
			return true;
		}
		return false;

	}
	~DateComparisonNode();
private:
	const Date date_;
	Comparison cmp_;


};


class EventComparisonNode : public Node {
public:
	EventComparisonNode(Comparison cmp, const string& event);
	bool Evaluate ( const Date& date, const string& event) override{
		//cout << "-----event to compare is " << event_ << endl;
		if(cmp_ == Comparison::Equal && event == event_){
			//cout << "!!!!" << endl;
			return true;
		}else if (cmp_ == Comparison::NotEqual && event != event_){

			//cout << "-----event != event_" << endl;
			return true;
		}
		//cout << "-----event == event_" << endl;
		return false;
	}
private:
	const string event_;
	Comparison cmp_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(LogicalOperation logical_operation, shared_ptr<Node> left, shared_ptr<Node> right);
	bool Evaluate ( const Date& date, const string& event) override{
		if(logical_operation_ == LogicalOperation::And){
			if(left_->Evaluate(date, event) && right_->Evaluate(date, event)){
				return true;
			}
		}
		else if(logical_operation_ == LogicalOperation::Or){
			if(left_->Evaluate(date, event) || right_->Evaluate(date, event)){
				return true;
			}
		}
		return false;
	};
private:
	shared_ptr<Node> left_;
	shared_ptr<Node> right_;
	LogicalOperation logical_operation_;
};












#endif /* NODE_H_ */
