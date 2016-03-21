#include "Query.h"
#include "Operation.h"

using std::string;

Query *Query::create(string name) { return new Query(name); }

string Query::dump() const {

  string output = "";
  // Initially dump all the relations present.
  for (const Relation *each : relationSet) {
    output += each->dump() + "\n";
  }

  // Now output all the operations.
  for (const Operation *each : operationList) {
    output += each->dump() + "\n";
  }

  return output;
}