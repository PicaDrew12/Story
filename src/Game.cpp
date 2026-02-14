#include<iostream>
#include "Printer.h"
#include "Engine.h"


void InitPrint() {
	//printer.Format(33);
	printer.InitFormater();
	printer.printSpeed = 50;
	printer.Format("cyan");
	//printer.print("Hello from Android");
	printer.Format("red");
	//printer.FormatBackground("white");
	printer.FormatStyle("italic");
	//printer.print("890",77, std::endl);
	//printer.typeWriterPrint("HELLO", "  ", "\n", 4563);
}




void TestNodes(){
  Engine engine;
  auto dialogue1 = std::make_shared<DialogueNode>();
  auto jump1 = std::make_shared<JumpNode>();
  dialogue1->speaker = "OPA";
  dialogue1->text = "HHH";
  dialogue1->nextNode = jump1;
  jump1->nextNode = dialogue1;
  engine.startingNode = dialogue1;
  engine.Start();
}

int main(){

  
  
	InitPrint();
  //

  TestNodes();



}    
