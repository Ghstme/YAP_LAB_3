#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure {
private:
    double *radius;

public:
    Circle(double r);

    ~Circle() override;

    double CalcArea() const override;

    void Show() const override;
};


#endif //CIRCLE_H
