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

  Relation(std::string name, Tuple *tuple, Query *query);
  void setRelationForAttributes();

public:
  static Relation *create(std::string name, Tuple *tuple, Query *query);

  virtual std::string dump() const;

  void dumpRelation();

  std::string getName() const { return name; }

  const Tuple *getTuple() const { return tuple; }

  struct RelationCompare {
    bool operator()(const Relation *lhs, const Relation *rhs) const {
      return lhs->getName() < rhs->getName();
    }
  };
};

#endif