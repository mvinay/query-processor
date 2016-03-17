#include "BooleanExpr.h"
#include "Constant.h"

#include "Attribute.h"

#include <cassert>

BooleanExpr *BooleanExpr::create(Operand *lhs, Operand *rhs,
                                 BoolOperatorType operatorType,
                                 string operationName = "") {

  if (dynamic_cast<Attribute *>(lhs)) {
    if (!(dynamic_cast<Attribute *>(rhs)) && !(dynamic_cast<Constant *>(rhs))) {
      assert("Expecting the Attribute == Attribute | Constant");
    }
    assert(operatorType != AND && operatorType != OR);
  } else {
    // Or Both the arguments should be BooleanExpr;
    assert(dynamic_cast<BooleanExpr *>(lhs) &&
           dynamic_cast<BooleanExpr *>(rhs));
    assert(operatorType == AND || operatorType == OR);
  }

  return new BooleanExpr(lhs, rhs, operatorType, operationName);
}