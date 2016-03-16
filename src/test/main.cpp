#include "Attribute.h"

#include <iostream>

using std::cout;

int main() {
    
    Attribute *attr1 = Attribute::create("simple", AttributeType.INTEGER);
    cout << *attr1 << endl; 
    return 0;    
}