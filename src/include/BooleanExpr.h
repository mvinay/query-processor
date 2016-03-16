#ifndef BOOL_OPERATION_H
#define BOOL_OPERATION_H

#include "Operand.h"
#include "CompareOpertaion.h"

class BooleanExpr {
private:     
     Operand *lhs;
     Operand *rhs;
     BooleanOperator operatorType;   
     
    BooleanExpr(Operand *_lhs , Operand *_rhs, BoolOperatorType _operatorType)
        : lhs(_lhs), rhs(_rhs), operatorType(_operatorType) {}

 public:  
     enum BoolOperatorType {
        AND,
        OR,
        EQ,
        NEQ,
        LT,
        LTE,
        GT,
        GTE
     };
     
     static BooleanExpr* create(Operand *lhs, Operand *rhs, BoolOperatorType);
   
};
#endif