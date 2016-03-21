#ifndef OPERATION_H
#define OPERATION_H
#include "Constant.h"
#include "Operand.h"
#include "PrintUtil.h"
#include "Query.h"
#include "Tuple.h"

#include <cassert>

using std::string;

// This class acts as the Base class for all the nodes in the parse/ query tree.
class Operation : public Operand {

  string operatorName;

public:
  Operation(string operatorName, string operandName, Query *query)
      : Operand(operandName, query), operatorName(operatorName) {
    query->pushBackOperation(this);
  }

  string getOperatorName() const { return operatorName; }

  virtual unsigned int getNumOperands() const = 0;

  virtual Operand *getOperand(unsigned int) const = 0;
};

class BinaryOperation : public Operation {

private:
  Operand *operand1;
  Operand *operand2;

public:
  BinaryOperation(Operand *lhs, Operand *rhs, string operatorName,
                  string operandName, Query *query)
      : Operation(operatorName, operandName, query), operand1(lhs),
        operand2(rhs) {}

  virtual string dump() const {

    const string space = " ";
    string output =
        "%" + getOperandName() + string(" = ") + getOperatorName() + space;

    output += printOperand(operand1);
    output += string(", ");
    output += printOperand(operand2);

    return output;
  }

  virtual unsigned int getNumOperands() const { return 2; }

  virtual Operand *getOperand(unsigned int i) const {
    assert(i < 2);
    return (i == 0) ? operand1 : operand2;
  }
};

// A binary operation with the output tuple.
class BinaryRelationalOperation : public BinaryOperation {

private:
  // Every relational operation outputs a tuple.
  const Tuple *outputTuple;

public:
  BinaryRelationalOperation(Operand *lhs, Operand *rhs, string operatorName,
                            string operandName, const Tuple *outputTuple,
                            Query *query)
      : BinaryOperation(lhs, rhs, operatorName, operandName, query),
        outputTuple(outputTuple) {}

  const Tuple *getOutputTuple() const { return outputTuple; }
};

#endif
