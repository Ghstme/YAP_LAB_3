#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double w, double h) {
    width = new double(w);
    height = new double(h);
}

Rectangle::~Rectangle() {
    delete width;
    delete height;
}

double Rectangle::CalcArea() const {
    return (*width) * (*height);
}

void Rectangle::Show() const {
    std::cout << "Прямоугольник: ширина = " << *width << ", высота = " << *height << std::endl;
}
