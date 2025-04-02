#ifndef FISH_H
#define FISH_H
#include "Animal.h"

class Fish : public Animal {
public:
    void breathe() const override;

    void eat() const override;

    void swim() const;
};
#endif //FISH_H
