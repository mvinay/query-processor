#include "Constant.h"

Constant *Constant::create(int value) { return new IntConstant(value); }

Constant *Constant::create(float value) { return new FloatConstant(value); }

Constant *Constant::create(std::string value) {
  return new StringConstant(value);
}
