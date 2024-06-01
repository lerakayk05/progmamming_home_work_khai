#include <iostream>
#include <cmath>

// Структура для задачі Begin15
struct Circle {
    double S;  // площа кола
    double D;  // діаметр кола
    double L;  // довжина кола
};

// Структура для задачі Boolean32
struct Triangle {
    int a, b, c; // сторони трикутника
    bool isRight; // чи є трикутник прямокутним
};

// Функція для обробки задачі Begin15
void ProcessCircle(Circle &circle) {
    const double PI = 3.14;
    circle.D = sqrt((4 * circle.S) / PI);
    circle.L = PI * circle.D;
}

// Функція для обробки задачі Boolean32
void ProcessTriangle(Triangle &triangle) {
    int a = triangle.a;
    int b = triangle.b;
    int c = triangle.c;
    triangle.isRight = (a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a);
}

// Функція для перевірки та заповнення полів задачі Begin15
void InputCircle(Circle &circle) {
    std::cout << "Enter the area of the circle (S): ";
    std::cin >> circle.S;
}

// Функція для перевірки та заповнення полів задачі Boolean32
void InputTriangle(Triangle &triangle) {
    std::cout << "Enter the sides of the triangle (a, b, c): ";
    std::cin >> triangle.a >> triangle.b >> triangle.c;
}

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

