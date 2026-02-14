#pragma once
#include "Node.h"


void Node::SetNext(const std::shared_ptr<Node>& node){
	nextNode = node;
}