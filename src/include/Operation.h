#ifndef OPERATION_H
#define OPERATION_H
#include "Operand.h"

using std::string;

// This class acts as the Base class for all the nodes in the parse/ query tree.
class Operation : public Operand {

  string operatorName;

public:
  Operation(string operatorName, string operandName)
      : Operand(operandName), operatorName(operatorName) {}

  string getOperatorName() const { return operatorName; }
};

class BinaryOperation : public Operation {

private:
  Operand *lhs;
  Operand *rhs;

public:
  BinaryOperation(Operand *lhs, Operand *rhs, string operatorName,
                  string operandName)
      : Operation(operatorName, operandName), lhs(lhs), rhs(rhs) {}

  virtual string dump() const {

    const string space = " ";
    string output =
        "%" + getOperandName() + string(" = ") + getOperatorName() + space;

    if (dynamic_cast<Operation *>(lhs)) {
      output += "%";
    }
    output += lhs->getOperandName();

    output += string(", ");

    if (dynamic_cast<Operation *>(rhs)) {
      output += "%";
    }

    output += rhs->getOperandName();

    return output;
  }
};

#endif
