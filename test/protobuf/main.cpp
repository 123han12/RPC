#include <iostream>
#include "test.pb.h"
using namespace std ; 
int main() {

    Person person ; 
    person.set_age(10) ; 
    cout << person.age() << endl ; 
    return 0 ; 
}