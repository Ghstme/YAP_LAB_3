#include "Circle.h"
#include <iostream>
#include <cmath>

Circle::Circle(double r) {
    radius = new double(r);
}

Circle::~Circle() {
    delete radius;
}

double Circle::CalcArea() const {
    return M_PI * (*radius) * (*radius);
}

void Circle::Show() const {
    std::cout << "Круг: радиус = " << *radius << std::endl;
}
