#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP

#include "Operand.h"
#include "AttributeType.h"

#include <string>

// An argument might be list of attributes, or output of other 
class Attribute : public Operand {
private: 
        std::string name;
        AttributeType type;
        Relation *relation;
        Attribute(name, type): name(name), type(type);
public:
    static Attribute* create(std::string, AttributeType type);
};

#endif