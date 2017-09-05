#include "stdafx.h"

#include "BpmnStateMachine.h"

// read table of transition from disk (xml, json), from net or so on
std::array<std::array<BpmnStateMachine::transition, eventMax>, stateMax>  BpmnStateMachine::transitionTable = {
  /*              events::ok                  events::cancel              events::next                events::error               events::stop   */
  /*states::st1*/ states::st2,type1,nullptr , states::st3,type2,nullptr , states::st4,type3,nullptr , states::st1,type4,nullptr , states::st2,type5,nullptr ,
  /*states::st2*/ states::st3,type2,nullptr , states::st4,type3,nullptr , states::st1,type4,nullptr , states::st2,type5,nullptr , states::st3,type1,nullptr ,
  /*states::st3*/ states::st4,type3,nullptr , states::st1,type4,nullptr , states::st2,type5,nullptr , states::st3,type1,nullptr , states::st4,type2,nullptr ,
  /*states::st4*/ states::st1,type4,nullptr , states::st2,type5,nullptr , states::st3,type1,nullptr , states::st4,type2,nullptr , states::st1,type3,nullptr
};

// read data from disk (xml, json), from net or so on
void BpmnStateMachine::init(void)
{
  fillTransitionTable();

  for (int s = 0; s < stateMax; s++) {
    for (int e = 0; e < eventMax; e++) {
      transitionTable[s][e]._object = createObjectFactory(transitionTable[s][e]._type);
      transitionTable[s][e]._object->setExternal(createExternalFactory(0));
    }
  }
  int i(0);
}

// step of the state machine 
events BpmnStateMachine::step(events event)
{
  //can use any automation tools
  const struct transition& trans(transitionTable[_state][event]);

  std::stringstream ss;
  ss << "state before - " << _state << " event - " << event << " state after - " << trans._state << std::endl;
  Logger logger(ss.str());

  _state = trans._state;
  return trans._object->event(event, nullptr);  //can put any data for current state 
}

// factory of objects 
std::shared_ptr<IObject> BpmnStateMachine::createObjectFactory(objectTypes type)
{
  // generate binary objects from any system, from COM for example

  std::shared_ptr<IObject> object2;
  switch (type)
  {
  case type1: object2 = std::make_shared<ObjectAskSystem>(std::string("Ask any question to system ")); break;
  case type2: object2 = std::make_shared<ObjectAskUser>(std::string("Ask question to user ")); break;
  case type3: object2 = std::make_shared<ObjectAskStart>(std::string("Ask question about start ")); break;
  case type4: object2 = std::make_shared<ObjectAskRun>(std::string("Ask user question to run ")); break;
  case type5: object2 = std::make_shared<ObjectAskStop>(std::string("Ask user question to to stop ")); break;
  }

  return object2;
}

// factory of external objects for connection - 
std::shared_ptr<IExternal> BpmnStateMachine::createExternalFactory(int exttype)
{
  // generate binary objects from any system, from COM for example

  std::shared_ptr<IExternal> external2;
  switch (exttype)
  {
  case 0: external2 = std::make_shared<ExternalSoap>(); break;
  case 1: external2 = std::make_shared<ExternalRest>(); break;
  case 2: external2 = std::make_shared<ExternalUser>(); break;
  }

  return external2;
}

void BpmnStateMachine::fillTransitionTable(void)
{
  // fill transitionTable[][] enum states, enum events, enum objectTypes and so on  from xml or json files
  // ..
}

