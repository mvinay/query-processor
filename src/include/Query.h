#ifndef QUERY_H
#define QUERY_H

class Operand;
class Operation;

#include "Relation.h"

#include <list>
#include <map>
#include <set>
#include <string>

typedef std::set<Relation *, Relation::RelationCompare> RelationSet;

typedef std::list<Operation *> OperationList;

class Query {

private:
  std::string name;
  RelationSet relationSet;
  OperationList operationList;

  Query(std::string name) : name(name) {}

public:
  static Query *create(std::string name);

  // The match which holds all the operand names.
  // Similar to the symbolTable in the compiler.
  std::map<std::string, Operand *> operandNameMap;

  void addRelation(Relation *relation) { relationSet.insert(relation); }

  void pushBackOperation(Operation *operation) {
    operationList.push_back(operation);
  }

  typedef OperationList::iterator optr_iterator;

  optr_iterator optr_begin() { return operationList.begin(); }
  optr_iterator optr_end() { return operationList.end(); }

  std::string dump() const;
};

#endif
