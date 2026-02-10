#include<iostream>
#include "Printer.h"
int main(){
  Printer printer;
  //printer.Format(33);
  printer.InitFormater();
  printer.Format("cyan");
  printer.print("Hello from Android");
  printer.Format("red");
  printer.FormatBackground("white");
  printer.FormatStyle("italic");
  printer.print("890",77);
  
}
