// Test02.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>

//#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/thread/thread.hpp> 

#include <chrono>
#include <thread>
#include <ctime>
#include <iostream>

namespace sc = boost::statechart;

//step 1 

struct Greeting;

struct Machine : sc::state_machine< Machine, Greeting > {};

struct Greeting : sc::simple_state< Greeting, Machine >
{
  Greeting() { std::cout << "Hello World!\n"; } // entry
  ~Greeting() { std::cout << "Bye Bye World!\n"; } // exit
};



//step 2 

struct IElapsedTime
{
  virtual double ElapsedTime() const = 0;
}; 

struct EvStartStop : sc::event< EvStartStop > 
{
  //int i(0);
};
struct EvReset : sc::event< EvReset > 
{
  //int i(0);
};

struct Active;
struct StopWatch : sc::state_machine< StopWatch, Active > 
{
  double ElapsedTime() const {
    return state_cast< const IElapsedTime & >().ElapsedTime();
  }
};

struct Stopped;

struct Active : sc::simple_state< Active, StopWatch, Stopped > 
{
public:
  typedef sc::transition< EvReset, Active > reactions;

  Active() : elapsedTime_(0.0) {}
  double ElapsedTime() const { 
    return elapsedTime_; 
  }
  double & ElapsedTime() { 
    return elapsedTime_; 
  }
private:
  double elapsedTime_;
};

struct Running : IElapsedTime, sc::simple_state< Running, Active >
{
public:
  typedef sc::transition< EvStartStop, Stopped > reactions;

  Running() : startTime_(std::time(0)) {}
  ~Running()
  {
    context< Active >().ElapsedTime() +=
      std::difftime(std::time(0), startTime_);

    context< Active >().ElapsedTime() = ElapsedTime();
  }

  virtual double ElapsedTime() const
  {
    return context< Active >().ElapsedTime() +
      std::difftime(std::time(0), startTime_);
  }

private:
  std::time_t startTime_;
};

struct Stopped : IElapsedTime, sc::simple_state< Stopped, Active >
{
  typedef sc::transition< EvStartStop, Running > reactions;

  virtual double ElapsedTime() const {
    return context< Active >().ElapsedTime();
  }
};



int main_()
{
  ////step 1 
  //Machine myMachine;
  //// The machine is not yet running after construction. We start
  //// it by calling initiate(). This triggers the construction of
  //// the initial state Greeting
  //myMachine.initiate();
  //// When we leave main(), myMachine is destructed what leads to
  //// the destruction of all currently active states.

  //step 2 
  StopWatch myWatch;
  myWatch.initiate();

  //boost::this_thread::sleep(boost::posix_time::milliseconds(256));
  //std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << myWatch.ElapsedTime() << "\n";
  myWatch.process_event(EvStartStop());

  //boost::this_thread::sleep(boost::posix_time::milliseconds(256));
  //std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << myWatch.ElapsedTime() << "\n";
  myWatch.process_event(EvStartStop());

  //boost::this_thread::sleep(boost::posix_time::milliseconds(256));
  //std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << myWatch.ElapsedTime() << "\n";
  myWatch.process_event(EvStartStop());

  //boost::this_thread::sleep(boost::posix_time::milliseconds(256));
  //std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << myWatch.ElapsedTime() << "\n";
  myWatch.process_event(EvReset());

  //boost::this_thread::sleep(boost::posix_time::milliseconds(256));
  //std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << myWatch.ElapsedTime() << "\n";

  return 0;
}



#include <stdio.h>

class StateMachine 
{
  enum states { before = 0, inside = 1, after = 2 } state;

  struct branch {
    enum states new_state : 4;
    unsigned should_putchar : 4;
  };

  static struct branch the_table[3][3];

public:
  StateMachine() : state(before) {
    ;
  }

  void FeedChar(int c) 
  {
    int idx2 = (c == ' ') ? 0 : (c == '\n') ? 1 : 2;
    struct branch *b = &the_table[state][idx2];
    state = b->new_state;
    if (b->should_putchar) putchar(c);
  }
};

struct StateMachine::branch StateMachine::the_table[3][3] = {
  /*             ' '          '\n'         others */
  /* before */{ { before, 0 },{ before, 1 },{ inside, 1 } },
  /* inside */{ { after,  0 },{ before, 1 },{ inside, 1 } },
  /* after  */{ { after,  0 },{ before, 1 },{ after,  0 } }
};

int main()
{
  int c;
  StateMachine machine;

  while ((c = getchar()) != EOF)
    machine.FeedChar(c);

  return 0;
}

