#ifndef SELECT_OP_H
#define SELECT_OP_H

#include "Operation.h"

// This class represents the node which holds the selection operator.
class SelectOperation : Operation {
private:
  BooleanExpr  *boolExpr;
  Operand valueOperand;
  
public:
    SelectOperatiion(BooleanExpr *boolExpr, Operand *operand) 
        : boolExpr(boolExpr), operand(valueOperand) {}
        
};

#endif