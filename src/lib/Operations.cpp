#include "BooleanExpr.h"
#include "Helper.h"
#include "ProjectOperation.h"
#include "SelectOperation.h"

#include <cassert>

SelectOperation *SelectOperation::create(BooleanExpr *boolExpr,
                                         RelationalOperation *value,
                                         string operandName, Query *query) {
  assert(boolExpr && value);
  return new SelectOperation(boolExpr, value, operandName,
                             value->getOutputTuple(), query);
}

SelectOperation *SelectOperation::create(BooleanExpr *boolExpr,
                                         Relation *relation, string operandName,
                                         Query *query) {
  assert(boolExpr && relation);
  return new SelectOperation(boolExpr, relation, operandName,
                             relation->getTuple(), query);
}

static void checkBooleanExpr(BooleanExpr *boolExpr, const Tuple *tuple,
                             const SelectOperation *selectOp) {

  for (Operation::operand_iterator itr = boolExpr->operand_begin();
       itr != boolExpr->operand_end(); ++itr) {

    Operand *operand = *itr;

    if (dynamic_cast<Constant *>(operand)) {
      continue;
    }

    BooleanExpr *boolExprOp = dynamic_cast<BooleanExpr *>(operand);
    if (boolExprOp) {
      // Check the boolean expression recursively.
      checkBooleanExpr(boolExprOp, tuple, selectOp);
      return;
    }

    Attribute *attribute = dynamic_cast<Attribute *>(operand);
    if (attribute) {
      if (tuple->hasAttribute(attribute)) {
        return;
      }

      string output = "Attribute ";
      output.append(attribute->dump());
      output.append(" is invalid for select operation: ");
      output.append(selectOp->dump());

      ERROR(output);
    }
  }
}

// Check whether the bool expression contains only the attributes in the second
// operand.
void SelectOperation::validate() const {
  checkBooleanExpr(getCondition(), getOutputTuple(), this);
}

ProjectOperation *ProjectOperation::create(Tuple *tuple, Operand *value,
                                           string operandName, Query *query) {
  return new ProjectOperation(tuple, value, operandName, tuple, query);
}

void ProjectOperation::validate() const {

  // get the Tuple from the second operand.
  const Tuple *inTuple = getTupleFor(getOperand(1));

  // Tuple being projected.
  const Tuple *outTuple = getTuple();

  if (inTuple->isSuperSetOf(outTuple)) {
    return;
  }

  ERROR("Invalid project operation. out tuple is not subset of the in-tuple: " +
        dump());
}
