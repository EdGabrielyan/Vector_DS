#include <iostream>
#include "vector.h"

int main() {
    Vector v;

    //v.set_size(5);
    v.push_back(12);
    v.push_back(345);
    v.push_back(56);
    v.push_back(788);
    v.push_back(34);

    std::cout << "print vector elements" << '\n';
    v.print();

    v.push_front(333);
    std::cout << '\n' << "after using push_front() function" << '\n';
    v.print();
    return 0;
}
