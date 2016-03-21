#include "Attribute.h"
#include "BooleanExpr.h"
#include "Constant.h"
#include "ProjectOperation.h"
#include "SelectOperation.h"
#include "Tuple.h"
#include "pass/Pass.h"
#include "pass/Passes.h"

#include <iostream>
#include <set>

using std::cout;
using std::endl;



static Query * buildIR() {
  Query *query = Query::create("SimpleQuery");

  Attribute *attr1 = Attribute::create("id", INTEGER, query);
  Attribute *attr2 = Attribute::create("name", INTEGER, query);
  Attribute *attr3 = Attribute::create("something", INTEGER, query);

  AttributeSet attrList;
  attrList.insert(attr1);
  attrList.insert(attr2);

  Tuple *tuple = Tuple::create(attrList, query);
  Relation *R = Relation::create("Table1", tuple, query);

  Constant *constant = Constant::create(3, query);

  BooleanExpr *expr =
      BooleanExpr::create(attr1, constant, BooleanExpr::EQ, query, "expr1");

  SelectOperation *operation =
      SelectOperation::create(expr, R, "filter_id", query);

  AttributeSet smallList;
  smallList.insert(attr1);
  // NOTE: Un-commment below to see the error in project operation.
  // smallList.insert(attr3);
  Tuple *shortTuple = Tuple::create(smallList, query);

  ProjectOperation *projectOp =
      ProjectOperation::create(shortTuple, operation, "project_id", query);
      
  return query;
}
int main() {

  Query *query = buildIR();
  
  PassManager *manager = new PassManager(query);
  
  manager->addPass(getValidationPass());
  manager->run();
  
  return 0;
}
