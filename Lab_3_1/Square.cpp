#include "Square.h"
#include <iostream>

Square::Square(double s) {
    side = new double(s);
}

Square::~Square() {
    delete side;
}

double Square::CalcArea() const {
    return (*side) * (*side);
}

void Square::Show() const {
    std::cout << "Квадрат: сторона = " << *side << std::endl;
}
