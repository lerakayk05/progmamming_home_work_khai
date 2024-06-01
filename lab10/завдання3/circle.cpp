#include "circle.h"
#include <cmath>
#include <iostream>

void ProcessCircle(Circle &circle) {
    const double PI = 3.14;
    circle.D = sqrt((4 * circle.S) / PI);
    circle.L = PI * circle.D;
}

void InputCircle(Circle &circle) {
    std::cout << "Enter the area of the circle (S): ";
    std::cin >> circle.S;
}