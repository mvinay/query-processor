#include "BooleanExpr.h"
#include "Constant.h"

#include "Attribute.h"
#include "PrintUtil.h"

#include <cassert>

BooleanExpr *BooleanExpr::create(Operand *lhs, Operand *rhs,
                                 BoolOperatorType operatorType, Query *query,
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

  BooleanExpr *newBoolExpr =
      new BooleanExpr(operatorType, operationName, query);
  newBoolExpr->addOperand(lhs);
  newBoolExpr->addOperand(rhs);
  return newBoolExpr;
}

void BooleanExpr::validate() const {

  const Operand *lhs = getOperand(0);
  const Operand *rhs = getOperand(1);

  const Attribute *lAttr = dynamic_cast<const Attribute *>(lhs);
  if (lAttr) {
    const Attribute *rAttr = dynamic_cast<const Attribute *>(rhs);
    if (rAttr) {
      if (lAttr->getType() != rAttr->getType()) {
        ERROR("Invalid attribute types for Operation: " + dump());
      }
      return;
    }

    const Constant *rConst = dynamic_cast<const Constant *>(rhs);
    if (!rConst) {
      ERROR("Second operand should be of Constant Or Attribute type for "
            "Operation: " +
            dump());
    }

    if (rConst->getType() != lAttr->getType()) {
      ERROR("Invalid Constant type for Operation: " + dump());
    }

    return;
  }

  const BooleanExpr *lExpr = dynamic_cast<const BooleanExpr *>(lhs);
  if (lExpr && !(dynamic_cast<const BooleanExpr *>(rhs))) {
    ERROR("Second operand should be BooleanExpr for Operation: " + dump());
  }

  ERROR("Unknown opperands for Operation: " + dump());
}