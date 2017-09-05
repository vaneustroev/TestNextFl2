// Test01.cpp: 
//
// 2017/08/10 - V.A. Neustroev
//
// www.vanmed.narod.ru
// vaneustroev@gmail.com, vaneustroev@yandex.ru
//

//Create a c++ class that can store relatively big amounts(around 100 000) of an arbitrary type of object.
//1. The class should be able to associate each stored object with an integer "weight".If no weight is
//provided by a user at the time of adding the object, a default weight is associated with the object.
//
//2. The class should be able to provide a list of items of a specified weight.The class should also be
//able to provide a list of used weights.
//
//3. The class should have a method for executing an arbitrary function(provided by a user), which takes
//a stored object type as a parameter, sequentially on all stored objects in the ascending order of
//associated weights.E.g.object with an associated weight of 0 will be passed to the function before
//the object with an associated weight of 1.
//
//4. The class should have a method for altering associated object weights.This method takes a function
//(provided by a user) as a parameter, said function takes an object and it's current weight and returns 
//the new weight.The class should reassociate it's object weights based on that function. E.g. an object 
//with an associated weight of 2 after the method call can have an associated weight of 32, based on the
//user - provided function.
//
//To complete this assignment, you need to provide the source code for that class and class usage examples
//which cover all points outlined above.Also please explain in a few words why a specific approach was
//chosen.

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

void testWithAnyData(void)
{
  Nextflow<AnyData> nextflow;
  AnyData anyData;
  long counter(0);

  // task 1
  std::cout << "Task 1 begin " << std::endl;
  std::srand(unsigned(std::time(0)));
  nextflow.add(anyData);
  nextflow.add(anyData);
  nextflow.add(anyData);
  counter = 0;
  for (long i = 0; i < 100000; i++) {
    nextflow.add(anyData, std::rand());

    if (counter % 1000 == 0)
      std::cout << ">";
    ++counter;
  }
  std::cout << std::endl;
  std::cout << "Task 1 end " << std::endl;

  // task 2
  std::cout << "Task 2 begin " << std::endl;
  counter = 0;
  std::map<int, int> weights;
  std::multimap<int, AnyData> objects;
  weights = nextflow.weightes();
  for (auto& w : weights) {
    objects.clear();
    objects = nextflow.objects(w.first);
    for (auto& object : objects) {
      if (counter % 1000 == 0)
        std::cout << "Task 2 [" << counter << "] weight " << object.first << std::endl;
      ++counter;
    }
  }
  std::cout << "Task 2 end " << std::endl;

  // task 3
  std::cout << "Task 3 begin " << std::endl;
  nextflow.processObjects(pUserFuncProcessObjects);
  std::cout << "Task 3 end " << std::endl;

  // task 4
  std::cout << "Task 4 begin " << std::endl;
  nextflow.changeWeights(pUserFuncChangeWeights);
  std::cout << "Task 4 end " << std::endl;

}

void testWithOtherData(void)
{
  Nextflow<OtherData> nextflowOther;
  OtherData otherData;
  long counter(0);

  // task 1
  std::cout << "Task 1 begin " << std::endl;
  std::srand(unsigned(std::time(0)));
  nextflowOther.add(otherData);
  nextflowOther.add(otherData);
  nextflowOther.add(otherData);
  counter = 0;
  for (long i = 0; i < 100000; i++) {
    nextflowOther.add(otherData, std::rand());

    if (counter % 1000 == 0)
      std::cout << ">";
    ++counter;
  }
  std::cout << std::endl;
  std::cout << "Task 1 end " << std::endl;

  // task 2
  std::cout << "Task 2 begin " << std::endl;
  counter = 0;
  std::map<int, int> weights;
  std::multimap<int, OtherData> objects;
  weights = nextflowOther.weightes();
  for (auto& w : weights) {
    objects.clear();
    objects = nextflowOther.objects(w.first);
    for (auto& object : objects) {
      if (counter % 1000 == 0)
        std::cout << "Task 2 [" << counter << "] weight " << object.first << std::endl;
      ++counter;
    }
  }
  std::cout << "Task 2 end " << std::endl;

  // task 3
  std::cout << "Task 3 begin " << std::endl;
  nextflowOther.processObjects(pUserFuncOtherProcessObjects);
  std::cout << "Task 3 end " << std::endl;

  // task 4
  std::cout << "Task 4 begin " << std::endl;
  nextflowOther.changeWeights(pUserFuncOtherChangeWeights);
  std::cout << "Task 4 end " << std::endl;

}

int main()
{
  testWithAnyData();
  testWithOtherData();

  return 0;
}

