#ifndef BOOL_OPERATION_H
#define BOOL_OPERATION_H

#include "Operation.h"

using std::string;

class BooleanExpr : public BinaryOperation {
public:
  typedef enum { AND, OR, EQ, NEQ, LT, LTE, GT, GTE } BoolOperatorType;
  static string BoolOpNames[];

  static BooleanExpr *create(Operand *lhs, Operand *rhs, BoolOperatorType,
                             string operationName);

private:
  BoolOperatorType operatorType;

  BooleanExpr(Operand *_lhs, Operand *_rhs, BoolOperatorType _operatorType,
              string operandName)
      : BinaryOperation(_lhs, _rhs, BoolOpNames[_operatorType], operandName),
        operatorType(_operatorType) {}
};

#endif