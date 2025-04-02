#ifndef SQUARESUMMATOR_H
#define SQUARESUMMATOR_H
#include "Summator.h"

class SquareSummator : public Summator {
public:
    int transform(int i) const override;
};
#endif //SQUARESUMMATOR_H
