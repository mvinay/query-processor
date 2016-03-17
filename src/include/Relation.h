#ifndef RELATION_H
#define RELATION_H

#include "Operand.h"

class Tuple;

// The relation is the one which holds the data.
// It is equivalent to the mysql Table.
class Relation : public Operand {
private:
  // Name of the relation.
  std::string name;

  // Tuple of the relation.
  const Tuple *tuple;

  Relation(std::string name, Tuple *tuple)
      : Operand("@" + name), name(name), tuple(tuple) {
    setRelationForAttributes();
  }
  void setRelationForAttributes();

public:
  static Relation *create(std::string name, Tuple *tuple);

  virtual std::string dump() const;

  void dumpRelation();

  std::string getName() { return name; }
};

#endif