#ifndef SELECT_OP_H
#define SELECT_OP_H

#include "BooleanExpr.h"
#include "Operation.h"

// This class represents the node which holds the selection operator.
class SelectOperation : public BinaryRelationalOperation {
private:
  SelectOperation(BooleanExpr *boolExpr, Operand *operand, string operandName,
                  const Tuple *outputTuple, Query *query)
      : BinaryRelationalOperation(boolExpr, operand, "select", operandName,
                                  outputTuple, query) {}

public:
  static SelectOperation *create(Operand *boolExpr, Operand *value,
                                 string operandName, Query *query);
};

#endif