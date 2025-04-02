#ifndef CUBESUMMATOR_H
#define CUBESUMMATOR_H
#include "Summator.h"

class CubeSummator : public Summator {
public:
    int transform(int i) const override;
};
#endif //CUBESUMMATOR_H
