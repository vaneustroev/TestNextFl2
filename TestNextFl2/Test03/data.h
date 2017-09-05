#pragma once

#include <array>
#include <chrono>
#include <thread>
#include <ctime>
#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>

class IData
{
public:
  IData(void) { ; }
  virtual ~IData(void) { ; }

};

class Logger
{
public:
  Logger(const std::string& s) { std::cout << s; }
  ~Logger(void) { ; }

  void out(const std::string& s) { std::cout << s; }

private:
  //std::string _text;

};

//load from disk 
enum states {
  st1 = 0,
  st2 = 1,
  st3 = 2,
  st4 = 3
}; // state;

   //load from disk 
enum events {
  ok = 0, //ok
  cancel = 1, //cancel
  next = 2, //next
  error = 3, //error
  stop = 4  //stop
}; // event;

   //load from disk 
enum objectTypes {
  type1 = 0,
  type2 = 1,
  type3 = 2,
  type4 = 3,
  type5 = 4
}; // objectType;

