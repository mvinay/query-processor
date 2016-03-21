#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP

#include "AttributeType.h"
#include "Operand.h"
#include "Relation.h"

#include <string>

// An argument might be list of attributes, or output of other
class Attribute : public Operand {
private:
  std::string name;
  AttributeType type;
  Relation *relation;
  Attribute(std::string name, AttributeType type, Query *query)
      : Operand(name, query), name(name), type(type){};

public:
  static Attribute *create(std::string, AttributeType type, Query *query);

  void setRelation(Relation *relation);

  virtual std::string dump() const;

  std::string getName() const { return name; }

  AttributeType getType() const { return type; }

  const std::string getTypeName() { return AttributeTypeNames[type]; }

  struct AttributeCompare {
    bool operator()(const Attribute *lhs, const Attribute *rhs) const {
      return lhs->getName() < rhs->getName();
    }
  };
};
#endif