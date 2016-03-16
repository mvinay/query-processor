#ifndef PROJECT_OPERATION_H
#defined PROJECT_OPERATION_H

#include "Operation.h"
#include "Tuple.h"

// Project operation filters the attributes in the provided operand
class ProjectOperation : public Operation {
 
 private:   
    // Tuple which needs to be projected.
    Tuple *tuple;
 
    // Operand for which the @tuple needs to be filtered.
    Operand *operand;
};
#endif