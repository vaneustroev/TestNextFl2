// Test03.cpp: определяет точку входа для консольного приложения.
//
// 2017/08/17 - V.A. Neustroev
//
// www.vanmed.narod.ru
// vaneustroev@gmail.com, vaneustroev@yandex.ru
//

// Tasks - BPMN Engine
// Design and Write C++ application to execute BPMN file(BPMN engine).There are many BPMN
// elements, but for our purpose, we only support elements that appear on Camunda example
// invoice.v2.bpmn.You can open BPMN file using Camunda Modeler.In that file we have : start event,
// user task, exclusive gateway, service task and end event.
//
// Note :
//  1. We should parse BPMN file but we skip during this task(we are developing XSD to C++ class
//    generator and we will using it later).We only focus on execution.You can hardcoded the
//  elements.
//  2. Execution should follow BPMN element definitions and execution semantic standard as in
//  specification(link above)
//  3. BPMN engine is not running by itself.It has external component such as user task list(where
//    user can see his tasks.This is user task element purpose) and external service app to execute
//  service task element.Your applications should consider this.But you don't need to create those
//  external components(just mock them).We will use REST API so that user can query his task and
//  any external service will expose REST API so BPMN engine can just call it.
//  4. Our stack is : C++ to create BPMN engine, Golang for any web based application, Couchbase for
//  database and RabbitMQ for message queue.Use Couchbase if you need to store something and
//  RabbitMQ if you need to queue something.
//  5. We use boost C++ library.

#include "stdafx.h"

#include "BpmnStateMachine.h"

int main()
{
  try
  {
    events event(events::ok); //init state 
    BpmnStateMachine machine;

    machine.init();

    while (event != events::stop) {
      event = machine.step(event);
    }
  }
  catch (std::exception e) {
    std::stringstream ss;
    ss << "exception: " << e.what();
    Logger logger(ss.str());
  }

  return 0;
}

