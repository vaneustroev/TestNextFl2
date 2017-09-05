#pragma once

class IExternal
{
public:
  IExternal(void) { ; }
  virtual ~IExternal(void) { ; }

  virtual int set(IData*) = 0;
  virtual int get(IData*) = 0;
};

class ExternalSoap : public IExternal
{
public:
  ExternalSoap(void) { ; }
  virtual ~ExternalSoap(void) { ; }

  int set(IData*) { return 0; }
  int get(IData*) { return 0; }
};

class ExternalRest : public IExternal
{
public:
  ExternalRest(void) { ; }
  virtual ~ExternalRest(void) { ; }

  int set(IData*) { return 0; }
  int get(IData*) { return 0; }
};

class ExternalUser : public IExternal
{
public:
  ExternalUser(void) { ; }
  virtual ~ExternalUser(void) { ; }

  int set(IData*) { return 0; }
  int get(IData*) { return 0; }
};

