#include "Relation.h"
#include "Attribute.h"
#include "BooleanExpr.h"
#include "Tuple.h"

using std::string;

int Operand::operandNameCounter = 0;
const string BooleanExpr::BoolOpNames[] = {"and", "or",  "eq", "neq",
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
  query->addRelation(this);
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
