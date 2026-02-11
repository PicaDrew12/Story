#pragma once

#include "Node.h"

class EndNode : public Node {
public:
	void Run() override;
	EndNode();
};