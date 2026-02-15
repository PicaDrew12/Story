#pragma once
#include "Node.h"
#include<vector>

class ChoiceNode : public Node {
public:
	std::string question;

	std::unordered_map<std::string, std::shared_ptr<Node>> choices;
	void Run() override;
};