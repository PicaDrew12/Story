#include<iostream>
#include "Engine.h"


Engine::Engine() {
	
}

void Engine::Start() {
	startingNode->Run();
}

void Engine::SetStartingNode(const std::shared_ptr<Node>& node) {
	startingNode = node;
}