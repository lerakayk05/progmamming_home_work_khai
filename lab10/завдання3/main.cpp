#include <iostream>
#include "circle.h"
#include "triangle.h"

int main() {
    // Обробка задачі Begin15
    Circle circle;
    InputCircle(circle);
    ProcessCircle(circle);
    std::cout << "Diameter (D): " << circle.D << std::endl;
    std::cout << "Circumference (L): " << circle.L << std::endl;

    // Обробка задачі Boolean32
    Triangle triangle;
    InputTriangle(triangle);
    ProcessTriangle(triangle);
    std::cout << "Is the triangle right-angled? " << (triangle.isRight ? "Yes" : "No") << std::endl;

    return 0;
}