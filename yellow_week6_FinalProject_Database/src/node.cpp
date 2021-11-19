/*
 * node.cpp
 *
 *  Created on: 11 ����. 2021 �.
 *      Author: NPK1
 */


#include "node.h"
#include <string>



DateComparisonNode::DateComparisonNode (Comparison cmp, const Date& date) : date_(date), cmp_(cmp){


}

DateComparisonNode::~DateComparisonNode(){

}


EventComparisonNode::EventComparisonNode(Comparison cmp, const string& event) : event_(event), cmp_(cmp){

}


LogicalOperationNode::LogicalOperationNode(LogicalOperation logical_operation, shared_ptr<Node> left, shared_ptr<Node> right){
	logical_operation_ = logical_operation;
	left_ = left;
	right_ = right;

}
