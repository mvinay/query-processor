#include "Relation.h"
#include "Attribute.h"
#include "BooleanExpr.h"
#include "Tuple.h"

#include <vector>

using std::string;

int Operand::operandNameCounter = 0;
string BooleanExpr::BoolOpNames[] = {"and", "or",  "eq", "neq",
                                     "lt",  "lte", "gt", "gte"};

std::string Attribute::dump() const {
  return std::string("[") + std::string(AttributeTypeNames[type]) +
         std::string("] @") + relation->getName() + std::string(".") + name;
}

Attribute *Attribute::create(std::string name, AttributeType type) {
  return new Attribute(name, type);
}

std::string Relation::dump() const {
  return getOperandName() + " = " + tuple->dump();
  ;
}

void Attribute::setRelation(Relation *relation) {
  this->relation = relation;
  this->setOperandName("@" + relation->getName() + "." + name);
}

Tuple *Tuple::create(std::vector<Attribute *> attributeList) {
  return new Tuple(attributeList);
}

Relation *Relation::create(string name, Tuple *tuple) {
  return new Relation(name, tuple);
}

void Relation::setRelationForAttributes() {
  for (auto *each : tuple->getAttributeList()) {
    each->setRelation(this);
  }
}