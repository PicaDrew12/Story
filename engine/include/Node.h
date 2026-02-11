#pragma once 
#include<string>
#include<../../include/Printer.h>

enum class NodeType{
  Start,
  Dialogue,
  Jump,
  End
};

class Node{
  public:
    std::string id;
    Node* nextNode=nullptr;
    NodeType nodeType;
    virtual void Run()=0;
    
};



