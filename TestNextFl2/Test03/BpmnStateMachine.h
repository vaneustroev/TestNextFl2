#pragma once

#include <stdio.h>

#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

#include <boost/date_time.hpp>

#include "object.h"
#include "external.h"

class BpmnStateMachine; 

const int stateMax(4); 
const int eventMax(5); 

// state machine 
class BpmnStateMachine 
{
public:
  BpmnStateMachine()
    : _state(states::st1)
    , _event(events::ok)
  {
    ;
  }

  // read data from disk (xml, json), from net or so on
  void init(void);

  // step of the state machine 
  events step(events event);

  // factory of objects 
  std::shared_ptr<IObject> createObjectFactory(objectTypes type);

  // factory of external objects for connection - 
  std::shared_ptr<IExternal> createExternalFactory(int exttype);

  void fillTransitionTable(void);

private:

  states _state;
  events _event;

  struct transition { 
    states _state; 
    objectTypes _type; 
    std::shared_ptr<IObject> _object; 
  }; 

  // table of transition 
  static std::array<std::array<transition, eventMax>, stateMax> transitionTable; 

};

