#include<iostream>
#include "Printer.h"
#include "Engine.h"
#include<filesystem>

void InitPrint() {
	//printer.Format(33);
	printer.InitFormater();
	printer.printSpeed = 50;
	printer.Format("cyan");
	//printer.print("Hello from Android");
	printer.Format("yellow");
	//printer.FormatBackground("white");
	printer.FormatStyle("bold");
	//printer.print("890",77, std::endl);
	//printer.typeWriterPrint("HELLO", "  ", "\n", 4563);
}




void TestNodes(){
  Engine engine;
  auto end1 = std::make_shared<EndNode>();
  auto dialogue1 = std::make_shared<DialogueNode>();
  auto jump1 = std::make_shared<JumpNode>();
  dialogue1->speaker = "OPA";
  dialogue1->text = "HHH";
  dialogue1->nextNode = jump1;
  jump1->nextNode = end1;
  engine.startingNode = dialogue1;
  engine.Start();
}

void TestNodes1() {
	Engine engine;
	auto end1 = std::make_shared<EndNode>();
	auto dialogue1 = std::make_shared<DialogueNode>();
	auto jump1 = std::make_shared<JumpNode>();
	dialogue1->Set("Andrei", "Salut");
	dialogue1->SetNext(jump1);
	jump1->SetNext(end1);
	engine.SetStartingNode(dialogue1);
	std::cout << "_MSVC_LANG = " << _MSVC_LANG << std::endl;

	engine.Start();
}


int main(){

  
  
	InitPrint();
  //

  TestNodes1();



}    
