#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure {
private:
    double *base;
    double *height;

public:
    Triangle(double b, double h);

    ~Triangle() override;

    double CalcArea() const override;

    void Show() const override;
};


#endif //TRIANGLE_H
