#ifndef PROJECT_OPERATION_H
#define PROJECT_OPERATION_H

#include "Operation.h"
#include "Tuple.h"

#include "Attribute.h"

// Project operation filters the attributes in the provided operand
class ProjectOperation : public BinaryOperation {

private:
  ProjectOperation(Tuple *tuple, Operand *value, string operationName)
      : BinaryOperation(tuple, value, "project", operationName) {}

public:
  static ProjectOperation *create(Tuple *tuple, Operand *value,
                                  string operandName);
};
#endif