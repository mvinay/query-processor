#include "Operand.h"
#include "Query.h"

#include <map>

using std::to_string;

Operand::Operand(std::string operandName, Query *query)
    : operandName(operandName), query(query) {
  if (query->operandNameMap.find(operandName) != query->operandNameMap.end()) {
    operandName += to_string(getNextNumber());
  }

  query->operandNameMap[operandName] = this;
}