// Nextflow.cpp: 
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
#include "otherdata.h"

template<typename T>
Nextflow<T>::Nextflow(void)
{
  ;
}

template<typename T>
Nextflow<T>::~Nextflow(void)
{
  ;
}

template<typename T>
void Nextflow<T>::add(T&object, int weight)
{
  double t(weight);
  object.name = std::to_string(t);
  _objects.insert(std::pair<int, T>(weight, object));
  _weightes[weight] += 1;
}

template<typename T>
std::multimap<int, T>& Nextflow<T>::objects(int weight)
{
  _subobjects.clear();

  auto range = _objects.equal_range(weight);
  _subobjects.insert(range.first, range.second);

  return _subobjects;
}

template<typename T>
const std::map<int, int>& Nextflow<T>::weightes(void)
{
  return _weightes;
}

template<typename T>
void Nextflow<T>::processObjects(T& (*userFuncProcessObjects)(T& object))
{
  long counter(0);
  for (auto& obj : _objects) {
    //(*userFuncProcessObjects)(obj.second);
    if (counter % 1000 == 0)  
      (*userFuncProcessObjects)(obj.second);
    ++counter;
  }
}

template<typename T>
void Nextflow<T>::changeWeights(int (*userFuncChangeWeights)(T& object, const int& weight))
{
  long counter(0);
  std::multimap<int, T> objects;

  std::cout << "Task 4 Step 1 " << std::endl;

  long size1 = _objects.size();

  counter = 0;
  for (auto it = _objects.begin(); it != _objects.end();) {
    objects.insert(std::pair<int, T>((*userFuncChangeWeights)(it->second, it->first), it->second));
    it = _objects.erase(it);

    if (counter % 1000 == 0)
      std::cout << ">";

    ++counter;
  }
  std::cout << std::endl;

  std::cout << "Task 4 Step 2 " << std::endl;

  counter = 0;
  for (auto it = objects.begin(); it != objects.end();) {
    _objects.insert(std::pair<int, T>(it->first, it->second));
    it = objects.erase(it);

    if (counter % 1000 == 0)
      std::cout << ">";

    ++counter;
  }
  std::cout << std::endl;

  long size2 = _objects.size();

  counter = 0;
  for (auto& obj : _objects) {
    if (counter % 1000 == 0)
      std::cout << "task 4, object name " << obj.second.name << " - new weight =" << obj.first << std::endl;
    ++counter;
  }
}

// only for linker 

template<typename T>
void anydataInit(void)
{
  Nextflow<T> nextflow;
  T anyData;
  std::map<int, int> weights = nextflow.weightes();
  std::multimap<int, T> objects = nextflow.objects(0);
  nextflow.add(anyData);
  nextflow.processObjects(nullptr);
  nextflow.changeWeights(nullptr);
}

void Init()
{
  anydataInit<AnyData>();
  anydataInit<OtherData>();
}

