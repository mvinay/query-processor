#ifndef OPERAND_H
#define OPERAND_H

#include <iostream>
#include <string>

using std::ostream;
using std::to_string;

class Query;

class Operand {

public:
  static int operandNameCounter;

private:
  std::string operandName;
  Query *query;

protected:
  Operand(std::string operandName, Query *query);

public:
  virtual std::string dump() const = 0;

  friend ostream &operator<<(ostream &output, const Operand &operand) {
    output << operand.dump();
    return output;
  }

  void setOperandName(std::string name) { this->operandName = name; }

  std::string getOperandName() const { return operandName; }

  static int getNextNumber() { return ++operandNameCounter; }

  Query *getQuery() { return query; }
};

#endif