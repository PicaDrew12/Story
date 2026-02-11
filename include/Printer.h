#pragma once 
#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<chrono>
#include<thread>

class Printer{
  public:
    int printSpeed;
    void print();
    void typeWriterPrint();
    template <typename T>
    std::string toString(const T& value) {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }
    template<typename T, typename... Args>
    void print(const T first,const Args&... rest){
      
      std::cout<<first;
      print(rest...);
    }
    template<typename T, typename... Args>
    void typeWriterPrint(const T first, const Args&... rest) {
        std::string newString = toString(first);
        //std::cout << first
        for (char c : newString) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(printSpeed));
        }
        typeWriterPrint(rest...);
    }
  
    std::unordered_map<std::string, int> colorMap; 
    std::unordered_map<std::string, int> styleMap; 

    void InitFormater();
    void Format(int color);
    void Format(std::string color);
    void FormatBackground(std::string color);
    void FormatStyle(std::string style);
    void TypeWriterPrint(std::string text);

    static Printer& getInstance() {
        static Printer instance;
        return instance;
    }

    private:
        Printer() {}
        Printer(const Printer&) = delete;
        Printer& operator=(const Printer&) = delete;

};


extern Printer& printer;