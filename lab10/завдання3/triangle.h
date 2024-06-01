#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Triangle {
    int a, b, c;
    bool isRight;
};

void ProcessTriangle(Triangle &triangle);
void InputTriangle(Triangle &triangle);

#endif // TRIANGLE_H