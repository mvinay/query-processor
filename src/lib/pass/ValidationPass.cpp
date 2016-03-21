#include "pass/Pass.h"
#include "Query.h"
#include "Operation.h"

class ValidationPass : public Pass {

public:
  ValidationPass() : Pass("IR Validation Pass") {}

  virtual void runOnQuery(Query *query) {
    // Iterate and validate all the operations.
    for (Query::optr_iterator itr = query->optr_begin();
         itr != query->optr_end(); ++itr) {
      Operation *operation = *itr;
      operation->validate();
    }
  }
};

Pass * getValidationPass() {
  return new ValidationPass();
}