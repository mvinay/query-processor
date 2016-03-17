#include "BooleanExpr.h"
#include "ProjectOperation.h"
#include "SelectOperation.h"

#include <cassert>

SelectOperation *SelectOperation::create(Operand *boolExpr, Operand *value,
                                         string operandName) {

  BooleanExpr *expr = dynamic_cast<BooleanExpr *>(boolExpr);
  assert(expr && "First operation should be a Boolean Expression");
  return new SelectOperation(expr, value, operandName);
}

ProjectOperation *ProjectOperation::create(Tuple *tuple, Operand *value,
                                           string operandName) {
  return new ProjectOperation(tuple, value, operandName);
}