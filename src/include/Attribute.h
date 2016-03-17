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
  Attribute(std::string name, AttributeType type)
      : Operand("@" + name), name(name), type(type){};

public:
  static Attribute *create(std::string, AttributeType type);

  void setRelation(Relation *relation);

  virtual std::string dump() const;
};

#endif