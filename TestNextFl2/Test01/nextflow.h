#pragma once

// Nextflow.h: 
//
// 2017/08/10 - V.A. Neustroev
//
// www.vanmed.narod.ru
// vaneustroev@gmail.com, vaneustroev@yandex.ru
//

template<typename T>
class Nextflow
{
public:
  Nextflow(void);
  ~Nextflow(void);

  void add(T&object, int weight = 100); // for task 1
  std::multimap<int, T>& objects(int weight); // for task 2
  const std::map<int, int>& weightes(void); // for task 2
  void processObjects(T& (*userFuncProcessObjects)(T& object)); // for task 3
  void changeWeights(int (*userFuncChangeWeights)(T& object, const int& weight)); // for task 4

private:
  std::multimap<int, T> _objects;
  std::multimap<int, T> _subobjects;
  std::map<int, int> _weightes;

};

