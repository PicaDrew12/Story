#pragma once 
#include "Node.h"
#include "DialogueNode.h"
#include "EndNode.h"
#include "JumpNode.h"
#include<unordered_map>
#include<memory>
#include<vector>
class Engine{
  public:
    std::shared_ptr<Node> startingNode;
    //void Run(Node* node);
    std::vector<std::shared_ptr<Node>> nodes;
    Engine();
    void Start();
    
};
