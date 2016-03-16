#ifndef CONSTANT_H
#define CONSTANT_H

#include "Operand.h"
#include <string>

class IntConstant : public Constant {
 private:
        int value;      
 public:
        IntConstant(int value);
};

class FloatConstant : public Constant {
 private:
        float value;
 public:
        FloatConst(float value);      
};

class StringConstant: public Constant {
private:
    std::string value;
public:
    StringConst(std::string value);
};

class Constant : public Operand {
    private:
      // Type of the constant
      AttributeType type;
};
#endif