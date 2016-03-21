#include "BooleanExpr.h"
#include "ProjectOperation.h"
#include "SelectOperation.h"

#include <cassert>

SelectOperation *SelectOperation::create(Operand *boolExpr, Operand *value,
                                         string operandName, Query *query) {

  BooleanExpr *expr = dynamic_cast<BooleanExpr *>(boolExpr);
  assert(expr && "First operation should be a Boolean Expression");

  BinaryRelationalOperation *operation =
      dynamic_cast<BinaryRelationalOperation *>(value);

  const Tuple *tuple;
  if (operation) {
    tuple = operation->getOutputTuple();
  } else {
    Relation *relation = dynamic_cast<Relation *>(value);
    if (relation) {
      tuple = relation->getTuple();
    }
  }

  assert(tuple && "Second operand is not relational Operation or Relation");

  return new SelectOperation(expr, value, operandName, tuple, query);
}

ProjectOperation *ProjectOperation::create(Tuple *tuple, Operand *value,
                                           string operandName, Query *query) {
  return new ProjectOperation(tuple, value, operandName, tuple, query);
}
