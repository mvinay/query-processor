#ifndef TUPLE_H
#define TUPLE_H

#include "Operand.h"

// Tuple is the list of attributes.
class Tuple  : public Operand {

 private:
    std::vector<Atrribute*> attributeList;
    enum TYPE {
        INTEGER,
        FLOAT,
        STRING
    };
    
    Tuple(std::vector<Atrribute*> attributeList) : attributeList(attributeList) {}
    
 public:
    static Tuple* create (std::vector<Atrribute*> attributeList);
    
    const std::vector<Atrribute*> &getAttributeList()  const {
        return this.attributeList;
    }
 };
#endif