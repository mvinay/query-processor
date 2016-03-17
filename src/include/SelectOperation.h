#ifndef SELECT_OP_H
#define SELECT_OP_H

#include "BooleanExpr.h"
#include "Operation.h"

// This class represents the node which holds the selection operator.
class SelectOperation : public BinaryOperation {
private:
  SelectOperation(BooleanExpr *boolExpr, Operand *operand, string operationName)
      : BinaryOperation(boolExpr, operand, "select", operationName) {}

public:
  static SelectOperation *create(Operand *boolExpr, Operand *value,
                                 string operandName);
};

#endif