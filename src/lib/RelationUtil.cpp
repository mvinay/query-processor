#include "Attribute.h"

static Attribute* Attribute* create(std::string name, AttributeType type) {
    return new Attribute(name, type);
}

void Attribute::setRelation(Relation *relation) {
    this.relation = relation;    
}

 static Tuple* Tuple::create (std::vector<Atrribute*> attributeList) {
    return new Tuple(attributeList);
}
 
static Relation* Relation::create(Tuple *tuple) {
     return new Relation(tuple);
}
 
void Relation::setRelationForAttributes() {
    for (Atrribute* each : tuple->getAttributeList()) {
        each->setRelation(this);
    }    
}