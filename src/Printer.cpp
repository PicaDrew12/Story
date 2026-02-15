#include "Printer.h"

Printer& printer = Printer::getInstance();


void Printer::print(){
  std::cout<<std::endl;
}

void Printer::printN(){
  //std::cout<<std::endl;
}

void Printer::typeWriterPrint(){
  std::cout<<std::endl;
}
void Printer::typeWriterPrintN(){
  
}


void Printer::Format(int color){
  std::cout<<"\033["<<color<<"m";
}

void Printer::ResetFormat() {
    std::cout << "\033[0m";
}




void Printer::Format(std::string color){
  
  int pickedColor =0;
  for(const auto& pair: colorMap){
    if(pair.first==color){
      pickedColor=pair.second;
    }
  }
  Format(30+pickedColor);
}
void Printer::FormatBackground(std::string color){
  
  int pickedColor =0;
  for(const auto& pair: colorMap){
    if(pair.first==color){
      pickedColor=pair.second;
    }
  }
  Format(40+pickedColor);
}

void Printer::FormatStyle(std::string style){
  
  int pickedStyle =0;
  for(const auto& pair: styleMap){
    if(pair.first==style){
      pickedStyle=pair.second;
    }
  }
  Format(pickedStyle);
}

enum class Section{
  NONE,
  COLORS,
  FORMATING
};

void Printer::InitFormater(){
  std::ifstream configFile("values.cfg");
  Section currentSection = Section::NONE;
  std::string line;
  while(std::getline(configFile,line)){
    if(line.empty()){
      continue;
    }
    if(line == "COLORS"){
      currentSection = Section::COLORS;
      continue;
    }

    if(line == "FORMATING"){
      currentSection = Section::FORMATING;
      continue;
    }
    std::istringstream iss(line);
    if(currentSection==Section::COLORS){
      std::string name;
      int code;
      if(iss>>name>>code){
        colorMap[name] = code;
      }
    }
    if(currentSection == Section::FORMATING){
      std::string name;
      int code;
      if(iss>>name>>code){
        styleMap[name]=code;
      }
    }
    
    
  }
}



void Printer::TypeWriterPrint(std::string text){
  for(char c :text ){
    std::cout<<c<<std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}




void Printer::SetRandomColor() {
    std::vector<std::string> v;
    for (auto key : colorMap) {
        if (key.first != "black" && key.first!="white") {
            v.push_back(key.first);
        }
    }
    int random = GetRandomInt(0, v.size() - 1);
   
    Format(v[random]);
}