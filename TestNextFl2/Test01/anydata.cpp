// anydata.cpp: 
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
#include "anydata.h"

//task 3 
template<typename T>
T& userFuncProcessObjects(T &object)
{
  std::cout << "task 3, object name " << object.name << std::endl;

  return object;
}

//task 4 
template<typename T>
int userFuncChangeWeights(T &object, const int& weight)
{
  return weight * 16;
}

AnyData& (*pUserFuncProcessObjects)(AnyData& object) = userFuncProcessObjects<AnyData>;
int(*pUserFuncChangeWeights)(AnyData& object, const int& weight) = userFuncChangeWeights<AnyData>;

