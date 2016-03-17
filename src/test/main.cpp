#include "Attribute.h"
#include "BooleanExpr.h"
#include "Constant.h"
#include "ProjectOperation.h"
#include "SelectOperation.h"

#include "Tuple.h"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main() {

  Attribute *attr1 = Attribute::create("id", INTEGER);
  Attribute *attr2 = Attribute::create("name", INTEGER);

  std::vector<Attribute *> attrList;
  attrList.push_back(attr1);
  attrList.push_back(attr2);
  Tuple *tuple = Tuple::create(attrList);
  Relation *R = Relation::create("Table1", tuple);

  Constant *constant = Constant::create(3);

  BooleanExpr *expr =
      BooleanExpr::create(attr1, constant, BooleanExpr::EQ, "expr1");

  SelectOperation *operation = SelectOperation::create(expr, R, "filter_id");

  std::vector<Attribute *> smallList;
  smallList.push_back(attr1);

  Tuple *shortTuple = Tuple::create(smallList);
  ProjectOperation *projectOp =
      ProjectOperation::create(shortTuple, operation, "project_id");

  cout << *constant << endl;
  cout << *attr1 << endl;
  cout << *expr << endl;
  cout << *operation << endl;
  cout << *projectOp << endl;

  return 0;
}