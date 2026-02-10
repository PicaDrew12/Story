#pragma once 
#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>


class Printer{
  public:
    int printSpeed;
    void print();
    template<typename T, typename... Args>
    void print(const T first,const Args&... rest){
      std::cout<<first;
      print(rest...);
    }
    std::unordered_map<std::string, int> colorMap; 
    void InitFormater();
    void Format(int color);
    void Format(std::string color);
    void FormatBackground(std::string color);


};
