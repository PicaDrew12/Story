#include "DialogueNode.h"

void DialogueNode::Run() {
    //std::cout << "RAN" << std::endl;
    printer.typeWriterPrint(speaker, ": " + text);
    if (nextNode) {
        nextNode->Run();
    }
}

DialogueNode::DialogueNode(){
  nodeType = NodeType::Dialogue;
}
