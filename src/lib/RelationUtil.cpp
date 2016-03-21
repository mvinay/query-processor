#include "Relation.h"
#include "Attribute.h"
#include "BooleanExpr.h"
#include "Tuple.h"

using std::string;

static const char *space = " ";
static const char *value = "%";

int Operand::operandNameCounter = 0;
string BooleanExpr::BoolOpNames[] = {"and", "or",  "eq", "neq",
                                     "lt",  "lte", "gt", "gte"};

std::string Attribute::dump() const {
  return std::string("[") + std::string(AttributeTypeNames[type]) +
         std::string("] @") + relation->getName() + std::string(".") + name;
}

Attribute *Attribute::create(std::string name, AttributeType type,
                             Query *query) {
  return new Attribute(name, type, query);
}

void Attribute::setRelation(Relation *relation) {
  this->relation = relation;
  this->setOperandName("@" + relation->getName() + "." + name);
}

Tuple *Tuple::create(AttributeSet attributeList, Query *query) {
  return new Tuple(attributeList, query);
}

Relation::Relation(std::string name, Tuple *tuple, Query *query)
    : Operand("@" + name, query), name(name), tuple(tuple) {
  setRelationForAttributes();
}

Relation *Relation::create(string name, Tuple *tuple, Query *query) {
  return new Relation(name, tuple, query);
}

std::string Relation::dump() const {
  string outputStr = getOperandName() + " = " + "[ \n";

  const AttributeSet attributeList = tuple->getAttributeList();

  int i = 0;
  for (auto itr = attributeList.begin(); itr != attributeList.end(); ++itr) {
    outputStr += "\t[ " + (*itr)->getTypeName() + " ] " + (*itr)->getName();
    if (i != attributeList.size() - 1) {
      outputStr += std::string(",\n");
    }
  }
  outputStr += " \n]";

  return outputStr;
}

void Relation::setRelationForAttributes() {
  for (auto *each : tuple->getAttributeList()) {
    each->setRelation(this);
  }
}

string printOperand(Operand *operand) {

  if (dynamic_cast<Tuple *>(operand) || dynamic_cast<Constant *>(operand) ||
      dynamic_cast<Attribute *>(operand) || dynamic_cast<Relation *>(operand)) {
    return operand->getOperandName();
  }

  BinaryRelationalOperation *relationalOp =
      dynamic_cast<BinaryRelationalOperation *>(operand);
  if (relationalOp) {
    return relationalOp->getOutputTuple()->dump() + space + value +
           relationalOp->getOperandName();
  }

  BinaryOperation *operation = dynamic_cast<BinaryOperation *>(operand);
  if (operation) {
    return value + operation->getOperandName();
  }

  assert(false && "Invalid operand");
}