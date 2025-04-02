#include "CylinderVolume.h"

double CalculateCylinderVolume(const Figure *base, double height) {
    return base->CalcArea() * height;
}
