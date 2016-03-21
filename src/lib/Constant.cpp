#include "Constant.h"

Constant *Constant::create(int value, Query *query) {
  return new IntConstant(value, query);
}

Constant *Constant::create(float value, Query *query) {
  return new FloatConstant(value, query);
}

Constant *Constant::create(std::string value, Query *query) {
  return new StringConstant(value, query);
}
