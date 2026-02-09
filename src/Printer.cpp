#include "Printer.h"

void Printer::print(){
  std::cout<<"\033[0m"<<std::endl;
}


void Printer::Format(int color){
  std::cout<<"\033["<<color<<"m";
}




//void Format(std::string color);
