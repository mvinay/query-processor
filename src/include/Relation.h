#ifndef RELATION_H
#define RELATION_H

#include "Operand.h"

// The relation is the one which holds the data.
// It is equivalent to the mysql Table.
class Relation : public Operand {
private:
    // Name of the relation.
    std::string name;
    
    // Tuple of the relation.
    Tuple *tuple;
    
    Relation(Tuple *tuple) : tuple(tuple) {
        setRelationForAttributes();
    }
    setRelationForAttributes();
public:
    static Relation* Relation::create(Tuple *tuple)
};

#endif