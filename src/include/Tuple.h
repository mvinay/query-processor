#ifndef TUPLE_H
#define TUPLE_H

#include "Attribute.h"
#include "Operand.h"

#include <algorithm>
#include <set>

typedef std::set<Attribute *, Attribute::AttributeCompare> AttributeSet;

// Tuple is the list of attributes.
class Tuple : public Operand {

private:
  AttributeSet attributeList;
  enum TYPE { INTEGER, FLOAT, STRING };

  Tuple(AttributeSet attributeList, Query *query)
      : Operand("", query), attributeList(attributeList) {
    setOperandName(print());
  }

public:
  static Tuple *create(AttributeSet attributeList, Query *query);

  const AttributeSet &getAttributeList() const { return this->attributeList; }

  std::string print() const {

    std::string outputStr = "[ ";

    int i = 0;
    for (auto itr = attributeList.begin(); itr != attributeList.end();
         ++itr, ++i) {
      outputStr += (*itr)->getOperandName();
      if (i != attributeList.size() - 1) {
        outputStr += std::string(", ");
      }
    }

    outputStr += " ]";

    return outputStr;
  }

  virtual std::string dump() const { return print(); }

  bool hasAttribute(Attribute *attribute) const {
    return attributeList.find(attribute) != attributeList.end();
  }

  bool isSuperSetOf(const Tuple *tuple) const {
    return std::includes(attributeList.begin(), attributeList.end(),
                         tuple->getAttributeList().begin(),
                         tuple->getAttributeList().end());
  }
};
#endif