#include "Bird.h"
#include <iostream>

void Bird::breathe() const {
    std::cout << "Птица дышит легкими\n";
}

void Bird::eat() const {
    std::cout << "Птица клюет зерна\n";
}

void Bird::lay_eggs() const {
    std::cout << "Птица откладывает яйца\n";
}
