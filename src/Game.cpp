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

int main(){

  
  
	InitPrint();
  //
  //Engine engine;
  EndNode endNode;
  DialogueNode text2;
  text2.speaker = "Kyle";
  text2.text = "HELLO!";
  //text2.nextNode = text2;
  text2.nodeType = NodeType::Dialogue;
  text2.nextNode = &endNode;

  

  DialogueNode text1;
  text1.speaker = "BOB";
  text1.text = "HELLO!";
  text1.nodeType = NodeType::Dialogue;
  text1.nextNode = &text2;
  
  text1.Run();
  printer.ResetFormat();
}    
