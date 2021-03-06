#ifndef PROJECT_OPERATION_H
#define PROJECT_OPERATION_H

#include "Operation.h"
#include "Tuple.h"

#include "Attribute.h"

// Project operation filters the attributes in the provided operand
class ProjectOperation : public RelationalOperation {

private:
  ProjectOperation(Tuple *tuple, Operand *value, string operandName,
                   const Tuple *outputTuple, Query *query)
      : RelationalOperation("project", operandName, outputTuple, query) {
    addOperand(tuple);
    addOperand(value);
  }

public:
  static ProjectOperation *create(Tuple *tuple, Operand *value,
                                  string operandName, Query *query);

  const Tuple *getTuple() const { return static_cast<Tuple *>(getOperand(0)); }

  virtual void validate() const;
};
#endif