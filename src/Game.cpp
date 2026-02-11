#include<iostream>
#include "Printer.h"
#include "Engine.h"
int main(){

  
  Printer printer;
  //printer.Format(33);
  printer.InitFormater();
  printer.Format("cyan");
  printer.print("Hello from Android");
  printer.Format("red");
  printer.FormatBackground("white");
  printer.FormatStyle("italic");
  //printer.print("890",77, std::endl);
  printer.TypeWriterPrint("HELLO");
  //
  Engine engine;
  DialogueNode text2;
  text2.speaker = "BOB";
  text2.text = "HELLO!";
  //text2.nextNode = text2;
  text2.nodeType = NodeType::End;

  DialogueNode text1;
  text1.speaker = "BOB";
  text1.text = "HELLO!";
  text1.nodeType = NodeType::Dialogue;
  text1.nextNode = &text2;

  text1.Run();
}    
