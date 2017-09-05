// otherdata.cpp: 
//
// 2017/08/10 - V.A. Neustroev
//
// www.vanmed.narod.ru
// vaneustroev@gmail.com, vaneustroev@yandex.ru
//

#include "stdafx.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <vector>

#include "nextflow.h"
#include "otherdata.h"

//task 3 
template<typename T>
T& userFuncOtherProcessObjects(T &object)
{
  std::cout << "task 3, other object name " << object.name << std::endl;

  return object;
}

//task 4 
template<typename T>
int userFuncOtherChangeWeights(T &object, const int& weight)
{
  return weight / 2;
}

OtherData& (*pUserFuncOtherProcessObjects)(OtherData& object) = userFuncOtherProcessObjects<OtherData>;
int(*pUserFuncOtherChangeWeights)(OtherData& object, const int& weight) = userFuncOtherChangeWeights<OtherData>;

