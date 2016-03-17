#ifndef TUPLE_H
#define TUPLE_H

#include "Attribute.h"
#include "Operand.h"
#include <vector>

// Tuple is the list of attributes.
class Tuple : public Operand {

private:
  std::vector<Attribute *> attributeList;
  enum TYPE { INTEGER, FLOAT, STRING };

  Tuple(std::vector<Attribute *> attributeList)
      : Operand(""), attributeList(attributeList) {
    setOperandName(print());
  }

public:
  static Tuple *create(std::vector<Attribute *> attributeList);

  const std::vector<Attribute *> &getAttributeList() const {
    return this->attributeList;
  }

  std::string print() const {

    std::string outputStr = "[Tuple] [ ";

    for (int i = 0; i < attributeList.size(); ++i) {
      outputStr += attributeList[i]->getOperandName();
      if (i != attributeList.size() - 1) {
        outputStr += std::string(", ");
      }
    }

    outputStr += " ]";

    return outputStr;
  }

  virtual std::string dump() const { return print(); }
};
#endif