#ifndef OPERATION_H
#define OPERATION_H
#include "Constant.h"
#include "Operand.h"
#include "PrintUtil.h"
#include "Query.h"
#include "Tuple.h"

#include <cassert>
#include <vector>

using std::string;

// This class acts as the Base class for all the nodes in the parse/ query tree.
class Operation : public Operand {

  std::vector<Operand *> operandList;
  string operatorName;

protected:
  void addOperand(Operand *operand) { operandList.push_back(operand); }

public:
  Operation(string operatorName, string operandName, Query *query)
      : Operand(operandName, query), operatorName(operatorName) {
    query->pushBackOperation(this);
  }

  string getOperatorName() const { return operatorName; }

  virtual unsigned int getNumOperands() const { return operandList.size(); }

  virtual Operand *getOperand(unsigned int i) const {
    assert(i < operandList.size());
    return operandList[i];
  }

  // Check whether all the operation and its operands are valid.
  virtual void validate() const = 0;

  typedef std::vector<Operand *>::iterator operand_iterator;

  virtual operand_iterator operand_begin() { return operandList.begin(); }
  virtual operand_iterator operand_end() { return operandList.end(); };

  virtual string dump() const {

    const string space = " ";
    string output =
        "%" + getOperandName() + string(" = ") + getOperatorName() + space;

    for (int i = 0; i < operandList.size(); ++i) {
      output += printOperand(operandList[i]);
      if (i != operandList.size() - 1) {
        output += string(", ");
      }
    }
    return output;
  }
};

// An operation with the output tuple.
class RelationalOperation : public Operation {

private:
  // Every relational operation outputs a tuple.
  const Tuple *outputTuple;

public:
  RelationalOperation(string operatorName, string operandName,
                      const Tuple *outputTuple, Query *query)
      : Operation(operatorName, operandName, query), outputTuple(outputTuple) {}

  const Tuple *getOutputTuple() const { return outputTuple; }
};

#endif
