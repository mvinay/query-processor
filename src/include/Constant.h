#ifndef CONSTANT_H
#define CONSTANT_H

#include "AttributeType.h"
#include "Operand.h"

#include <string>

#define CREATE_CONSTANT(TYPE) static Constant *create(TYPE value, Query *query);

using std::to_string;
using std::string;

class Constant : public Operand {
protected:
  AttributeType type;
  Constant(AttributeType type, Query *query) : Operand("", query), type(type) {}

public:
  CREATE_CONSTANT(int);
  CREATE_CONSTANT(float);
  CREATE_CONSTANT(string);

  AttributeType getType() { return type; }
};

class IntConstant : public Constant {
private:
  int value;

public:
  IntConstant(int value, Query *query)
      : Constant(INTEGER, query), value(value) {
    setOperandName(print());
  }

  string print() const {
    return std::string("[") + std::string(AttributeTypeNames[type]) +
           std::string("] ") + to_string(value);
  }

  virtual std::string dump() const { return print(); }

  int getValue() { return value; }
};

class FloatConstant : public Constant {
private:
  float value;

public:
  FloatConstant(float value, Query *query)
      : Constant(FLOAT, query), value(value) {
    setOperandName(print());
  }

  string print() const {
    return std::string("[") + std::string(AttributeTypeNames[type]) +
           std::string("] ") + to_string(value);
  }

  virtual std::string dump() const { return print(); }

  float getValue() { return value; }
};

class StringConstant : public Constant {
private:
  std::string value;

public:
  StringConstant(std::string value, Query *query)
      : Constant(STRING, query), value(value) {
    setOperandName(print());
  }

  string print() const {
    return std::string("[") + std::string(AttributeTypeNames[type]) +
           std::string("] ") + (value);
  }

  virtual std::string dump() const {
    return std::string("[") + std::string(AttributeTypeNames[type]) +
           std::string("] ") + value;
  }

  std::string getValue() { return value; }
};
#endif