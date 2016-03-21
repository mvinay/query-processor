#include "Query.h"

#include <string>

Query *Query::create(std::string name) { return new Query(name); }