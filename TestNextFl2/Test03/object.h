#pragma once

#include "data.h"
#include "external.h"

class IData;
class IExternal;

//interface of object 
class IObject
{
public:
  IObject(void) { ; }
  virtual ~IObject(void) { ; }

  virtual events event(events event, IData*data) = 0;

  virtual void setDescription(const std::string& description) = 0;
  virtual const std::string& description(void) = 0;
  virtual void setExternal(const std::shared_ptr<IExternal>& external) = 0;
  virtual const std::shared_ptr<IExternal>& external(void) = 0;
};

//any object - can be script or can connect to external SOAP, REST API and so on
class ObjectAskSystem : public IObject
{
public:
  ObjectAskSystem(std::string& description) : _event(next) {
    //init array of external connection; 
    _description = description;
  }
  ~ObjectAskSystem() { ; }

  events event(events event, IData*data) override {
    //ask external system or other objects, after that return any _event, show "comment"
    _external->set(data);
    _external->get(data);

    std::stringstream ss;
    ss << "type - '" << typeid(this).name() << "'" << _description << " - press Enter to continue ...";
    Logger logger(ss.str());

    std::cin.get();
    return _event;
  }
  void setDescription(const std::string& description) {
    _description = description;
  }
  const std::string& description(void) {
    return _description;
  }
  void setExternal(const std::shared_ptr<IExternal>& external) {
    _external = external;
  }
  const std::shared_ptr<IExternal>& external(void) {
    return _external;
  }

private:

  events _event;
  std::string _description;
  std::shared_ptr<IExternal> _external;

};

//any object - can be script or can connect to external SOAP, REST API and so on
class ObjectAskUser : public IObject
{
public:
  ObjectAskUser(std::string& description) : _event(next) {
    _description = description;
  }
  ~ObjectAskUser() { ; }

  events event(events event, IData*data) override {
    std::stringstream ss;
    ss << "type - '" << typeid(this).name() << "'" << _description << " - press Enter to continue ...";
    Logger logger(ss.str());

    std::cin.get();
    return _event;
  }
  void setDescription(const std::string& description) {
    _description = description;
  }
  const std::string& description(void) {
    return _description;
  }
  void setExternal(const std::shared_ptr<IExternal>& external) {
    _external = external;
  }
  const std::shared_ptr<IExternal>& external(void) {
    return _external;
  }

private:

  events _event;
  std::string _description;
  std::shared_ptr<IExternal> _external;

};

//any object - can be script or can connect to external SOAP, REST API and so on
class ObjectAskStart : public IObject
{
public:
  ObjectAskStart(std::string& description) : _event(error) {
    _description = description;
  }
  ~ObjectAskStart() { ; }

  events event(events event, IData*data) override {
    std::stringstream ss;
    ss << "type - '" << typeid(this).name() << "'" << _description << " - press Enter to continue ...";
    Logger logger(ss.str());

    std::cin.get();
    return _event;
  }
  void setDescription(const std::string& description) {
    _description = description;
  }
  const std::string& description(void) {
    return _description;
  }
  void setExternal(const std::shared_ptr<IExternal>& external) {
    _external = external;
  }
  const std::shared_ptr<IExternal>& external(void) {
    return _external;
  }

private:

  events _event;
  std::string _description;
  std::shared_ptr<IExternal> _external;

};

//any object - can be script or can connect to external SOAP, REST API and so on
class ObjectAskStop : public IObject
{
public:
  ObjectAskStop(std::string& description) : _event(stop) {
    _description = description;
  }
  ~ObjectAskStop() { ; }

  events event(events event, IData*data) override {
    std::stringstream ss;
    ss << "type - '" << typeid(this).name() << "'" << _description << " - press Enter to continue ...";
    Logger logger(ss.str());

    std::cin.get();
    return _event;
  }
  void setDescription(const std::string& description) {
    _description = description;
  }
  const std::string& description(void) {
    return _description;
  }
  void setExternal(const std::shared_ptr<IExternal>& external) {
    _external = external;
  }
  const std::shared_ptr<IExternal>& external(void) {
    return _external;
  }

private:

  events _event;
  std::string _description;
  std::shared_ptr<IExternal> _external;

};

//any object - can be script or can connect to external SOAP, REST API and so on
class ObjectAskRun : public IObject
{
public:
  ObjectAskRun(std::string& description) : _event(cancel) {
    _description = description;
  }
  ~ObjectAskRun() { ; }

  events event(events event, IData*data) override {
    std::stringstream ss;
    ss << "type - '" << typeid(this).name() << "'" << _description << " - press Enter to continue ...";
    Logger logger(ss.str());

    std::cin.get();
    return _event;
  }
  void setDescription(const std::string& description) {
    _description = description;
  }
  const std::string& description(void) {
    return _description;
  }
  void setExternal(const std::shared_ptr<IExternal>& external) {
    _external = external;
  }
  const std::shared_ptr<IExternal>& external(void) {
    return _external;
  }

private:

  events _event;
  std::string _description;
  std::shared_ptr<IExternal> _external;

};

