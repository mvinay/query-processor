#ifndef BOOL_OPERATION_H
#define BOOL_OPERATION_H

#include "Operation.h"

using std::string;

class BooleanExpr : public Operation {
public:
  typedef enum { AND, OR, EQ, NEQ, LT, LTE, GT, GTE } BoolOperatorType;
  static const string BoolOpNames[];

  static BooleanExpr *create(Operand *lhs, Operand *rhs, BoolOperatorType,
                             Query *query, string operationName);

  virtual void validate() const;

private:
  BoolOperatorType operatorType;

  BooleanExpr(BoolOperatorType _operatorType, string operandName, Query *query)
      : Operation(BoolOpNames[_operatorType], operandName, query),
        operatorType(_operatorType) {}
};

#endif