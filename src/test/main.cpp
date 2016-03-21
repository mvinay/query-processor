#include "Attribute.h"
#include "BooleanExpr.h"
#include "Constant.h"
#include "ProjectOperation.h"
#include "SelectOperation.h"

#include "Tuple.h"

#include <iostream>
#include <set>

using std::cout;
using std::endl;

int main() {

  Query *query = Query::create("SimpleQuery");

  Attribute *attr1 = Attribute::create("id", INTEGER, query);
  Attribute *attr2 = Attribute::create("name", INTEGER, query);
  Attribute *attr3 = Attribute::create("name", INTEGER, query);

  AttributeSet attrList;
  attrList.insert(attr1);
  attrList.insert(attr2);

  Tuple *tuple = Tuple::create(attrList, query);
  Relation *R = Relation::create("Table1", tuple, query);
  cout << *R << endl;

  Constant *constant = Constant::create(3, query);

  BooleanExpr *expr =
      BooleanExpr::create(attr1, constant, BooleanExpr::EQ, query, "expr1");
  cout << *expr << endl;

  SelectOperation *operation =
      SelectOperation::create(expr, R, "filter_id", query);
  cout << *operation << endl;

  AttributeSet smallList;
  smallList.insert(attr1);
  Tuple *shortTuple = Tuple::create(smallList, query);

  ProjectOperation *projectOp =
      ProjectOperation::create(shortTuple, operation, "project_id", query);
  cout << *projectOp << endl;

  return 0;
}
