#pragma once 
#include<iostream>
#include<string>

class Printer{
  public:
    int printSpeed;
    void print();
    template<typename T, typename... Args>
    void print(const T first,const Args&... rest){
      std::cout<<first;
      print(rest...);
    }
    void Format(int color);
    void Format(std::string color);


};
