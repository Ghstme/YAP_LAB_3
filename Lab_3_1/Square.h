#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"

class Square : public Figure {
private:
    double *side;

public:
    Square(double s);

    ~Square() override;

    double CalcArea() const override;

    void Show() const override;
};


#endif //SQUARE_H
