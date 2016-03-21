#include "Helper.h"
#include "Operation.h"
#include "PrintUtil.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
/// ------------- Print helper functions --------------------//

static const char *space = " ";
static const char *value = "%";

void ERROR(string msg) {
  cout << "ERROR: " << msg << endl;
  exit(1);
}

string printOperand(Operand *operand) {

  if (dynamic_cast<Tuple *>(operand) || dynamic_cast<Constant *>(operand) ||
      dynamic_cast<Attribute *>(operand) || dynamic_cast<Relation *>(operand)) {
    return operand->getOperandName();
  }

  RelationalOperation *relationalOp =
      dynamic_cast<RelationalOperation *>(operand);
  if (relationalOp) {
    return relationalOp->getOutputTuple()->dump() + space + value +
           relationalOp->getOperandName();
  }

  Operation *operation = dynamic_cast<Operation *>(operand);
  if (operation) {
    return value + operation->getOperandName();
  }

  assert(false && "Invalid operand");
}

// -------------------Other helper functions ------------------///

// Get the tuple for the operand. Operand should be either relationalOperation
// or
// Relation.
const Tuple *getTupleFor(Operand *operand) {
  Relation *relation = dynamic_cast<Relation *>(operand);
  if (relation) {
    return relation->getTuple();
  }

  RelationalOperation *operation = dynamic_cast<RelationalOperation *>(operand);
  if (operation) {
    return operation->getOutputTuple();
  }

  assert(false && "Invalid operand type ");
}
