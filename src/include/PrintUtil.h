#ifndef PRINT_UTIL_H
#define PRINT_UTIL_H

#include <string>

class Operand;

extern std::string printOperand(Operand *operand);

extern void ERROR(std::string msg);

#endif