#pragma once

// otherdata.cpp: 
//
// 2017/08/10 - V.A. Neustroev
//
// www.vanmed.narod.ru
// vaneustroev@gmail.com, vaneustroev@yandex.ru
//

struct OtherData
{
  std::string name;
  std::vector<std::string> names;

};

extern OtherData& (*pUserFuncOtherProcessObjects)(OtherData& object);
extern int(*pUserFuncOtherChangeWeights)(OtherData& object, const int& weight);

