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
	auto dialogue2 = std::make_shared<DialogueNode>();
	auto jump1 = std::make_shared<JumpNode>();
	dialogue1->Set("Andrei", "Salut");
	dialogue2->Set("Second", "Wow");
	dialogue1->SetNext(jump1);
	dialogue2->SetNext(end1);
	jump1->SetNext(end1);
	auto choice1 = std::make_shared<ChoiceNode>();
	jump1->SetNext(choice1);
	choice1->choices = { {"Andrei",dialogue1},{"Second",dialogue2} };
	choice1->question = "Andrei or Second?";
	engine.SetStartingNode(choice1);
	//std::cout << "_MSVC_LANG = " << _MSVC_LANG << std::endl;

	engine.Start();
}

enum class OS { Windows, Linux, MacOS, Unknown };

constexpr OS DetectOS() {
#if defined(_WIN32)
	return OS::Windows;   // _WIN32 is defined for both 32- and 64-bit Windows
#elif defined(__APPLE__)
	return OS::MacOS;
#elif defined(__linux__)
	return OS::Linux;
#else
	return OS::Unknown;
#endif
}

inline std::string OSName(OS os) {
	switch (os) {
	case OS::Windows: return "Windows";
	case OS::Linux:   return "Linux";
	case OS::MacOS:   return "macOS";
	default:          return "Unknown";
	}
}

void File() {
	Engine engine;
	if (OSName(DetectOS()) == "Linux") {
		engine.OpenProject("../TestGame");
	}if (OSName(DetectOS()) == "Windows") {
		engine.OpenProject("C:/Code/Story/Story/TestGame");
	}
	
}




int main(){
	printer.InitFormater();
  
  
	//InitPrint();
  //

  //TestNodes1();
	File();



}    
