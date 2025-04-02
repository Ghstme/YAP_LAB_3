#include "Triangle.h"
#include <iostream>

Triangle::Triangle(double b, double h) {
    base = new double(b);
    height = new double(h);
}

Triangle::~Triangle() {
    delete base;
    delete height;
}

double Triangle::CalcArea() const {
    return 0.5 * (*base) * (*height);
}

void Triangle::Show() const {
    std::cout << "Треугольник: основание = " << *base << ", высота = " << *height << std::endl;
}
