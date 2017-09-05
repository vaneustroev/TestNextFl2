#pragma once

// anydata.cpp: 
//
// 2017/08/10 - V.A. Neustroev
//
// www.vanmed.narod.ru
// vaneustroev@gmail.com, vaneustroev@yandex.ru
//

struct AnyData
{
  std::string name;
  std::vector<std::string> names;

};

extern AnyData& (*pUserFuncProcessObjects)(AnyData& object);
extern int (*pUserFuncChangeWeights)(AnyData& object, const int& weight);

