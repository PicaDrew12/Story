#include "JumpNode.h"

void JumpNode::Run(){

  if (nextNode) {
    nextNode->Run();
  }
}
