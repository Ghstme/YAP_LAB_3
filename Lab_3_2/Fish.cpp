#include "Fish.h"
#include <iostream>

void Fish::breathe() const {
    std::cout << "Рыба дышит через жабры\n";
}

void Fish::eat() const {
    std::cout << "Рыба ест планктон\n";
}

void Fish::swim() const {
    std::cout << "Рыба плывет, извиваясь\n";
}
