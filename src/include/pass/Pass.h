#ifndef PASS_H
#define PASS_H

#include <string>
#include <vector>

class Query;

using std::string;

class Pass {
private:
  string name;

public:
  Pass(string name) : name(name) {}

  std::string getName() const { return name; }
  virtual void runOnQuery(Query *query) = 0;
};

class PassManager {
private:
  // Query
  Query *query;

  // Runs the pass in the same order mentioned.
  std::vector<Pass *> passList;

public:
  PassManager(Query *query) : query(query) {}

  void addPass(Pass *pass) { passList.push_back(pass); }

  void run();
};
#endif