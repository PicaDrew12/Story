#pragma once 
#include<string>
#include<../../include/Printer.h>
#include<memory>
enum class NodeType{
  Start,
  Dialogue,
  Jump,
  End
};

class Node{
  public:
    std::string id;
    std::shared_ptr<Node> nextNode=nullptr;
    NodeType nodeType;
    virtual void Run()=0;
    
};



