#ifndef SELECT_OP_H
#define SELECT_OP_H

#include "BooleanExpr.h"
#include "Operation.h"

// This class represents the node which holds the selection operator.
class SelectOperation : public RelationalOperation {
private:
  SelectOperation(BooleanExpr *boolExpr, Operand *operand, string operandName,
                  const Tuple *outputTuple, Query *query)
      : RelationalOperation("select", operandName, outputTuple, query) {
    addOperand(boolExpr);
    addOperand(operand);
  }

public:
  static SelectOperation *create(BooleanExpr *boolExpr, Relation *relation,
                                 string operandName, Query *query);

  static SelectOperation *create(BooleanExpr *, RelationalOperation *, string,
                                 Query *);
  BooleanExpr *getCondition() const {
    return static_cast<BooleanExpr *>(getOperand(0));
  }

  virtual void validate() const;
};

#endif