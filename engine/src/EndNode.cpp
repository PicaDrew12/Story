#include "EndNode.h"

void EndNode::Run() {
	std::cout << "END" << std::endl;
}

EndNode::EndNode() {
	nodeType = NodeType::End;
}