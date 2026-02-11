#pragma once
#include "Node.h"

class DialogueNode:public Node{
  public:
    std::string speaker;
    std::string text;
    void Run() override;
    
};
