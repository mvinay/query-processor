#include "pass/Pass.h"
#include "Query.h"

#include <iostream>

using std::cout;
using std::endl;

void PassManager::run() {
  for (Pass *each : passList) {
    cout << "\nRunning pass: " << each->getName() << endl;
    each->runOnQuery(query);
    cout << "\n Query: \n" << query->dump() << endl;
  }
}