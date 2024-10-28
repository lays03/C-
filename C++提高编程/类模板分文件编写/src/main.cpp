#include <iostream>
#include "Person.hpp"
int main(int argc, char *argv[])
{
    Person<string, int>p("孙悟空", 100);
    p.showPerson();
}
