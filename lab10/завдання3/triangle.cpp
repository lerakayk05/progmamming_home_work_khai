#include "triangle.h"
#include <iostream>

void ProcessTriangle(Triangle &triangle) {
    int a = triangle.a;
    int b = triangle.b;
    int c = triangle.c;
    triangle.isRight = (a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a);
}

void InputTriangle(Triangle &triangle) {
    std::cout << "Enter the sides of the triangle (a, b, c): ";
    std::cin >> triangle.a >> triangle.b >> triangle.c;
}