#pragma once
#include "Node.h"

class DialogueNode:public Node{
  public:
    std::string speaker;
    std::string text;
    DialogueNode();
    void Run() override;
    void Set(std::string speaker, std::string text);
    
};

