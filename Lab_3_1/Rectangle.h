#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
private:
    double *width;
    double *height;

public:
    Rectangle(double w, double h);

    ~Rectangle() override;

    double CalcArea() const override;

    void Show() const override;
};


#endif //RECTANGLE_H
