#ifndef OPERAND_H
#define OPERAND_H

#include <iostream>
#include <string>

using std::ostream;

class Operand {

public:
  static int operandNameCounter;

private:
  std::string operandName;

protected:
  Operand(std::string operandName) : operandName(operandName) {}

public:
  virtual std::string dump() const = 0;

  friend ostream &operator<<(ostream &output, const Operand &operand) {
    output << operand.dump();
    return output;
  }

  void setOperandName(std::string name) { this->operandName = name; }

  std::string getOperandName() const { return operandName; }

  static int getNextNumber() { return ++operandNameCounter; }
};

#endif