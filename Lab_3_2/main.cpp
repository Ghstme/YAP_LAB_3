#include <iostream>
#include <windows.h>
#include "Fish.h"
#include "Bird.h"
#include "FlyingBird.h"

void testEarlyBinding();

void testLateBinding();

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "=== Тестирование раннего связывания ===\n";
    testEarlyBinding();

    std::cout << "\n=== Тестирование позднего связывания ===\n";
    testLateBinding();

    return 0;
}

void testEarlyBinding() {
    Fish fish;
    Bird bird;
    FlyingBird flyingBird;

    std::cout << "-- Рыба --\n";
    fish.breathe();
    fish.eat();
    fish.swim();

    std::cout << "\n-- Обычная птица --\n";
    bird.breathe();
    bird.eat();
    bird.lay_eggs();

    std::cout << "\n-- Летающая птица --\n";
    flyingBird.breathe();
    flyingBird.eat();
    flyingBird.lay_eggs();
    flyingBird.fly();
}

void testLateBinding() {
    Animal *animals[3];

    animals[0] = new Fish();
    animals[1] = new Bird();
    animals[2] = new FlyingBird();

    for (int i = 0; i < 3; ++i) {
        std::cout << "\n-- Животное " << i + 1 << " --\n";
        animals[i]->breathe();
        animals[i]->eat();

        if (auto fish = dynamic_cast<Fish *>(animals[i])) {
            fish->swim();
        } else if (auto bird = dynamic_cast<Bird *>(animals[i])) {
            bird->lay_eggs();

            if (auto flyingBird = dynamic_cast<FlyingBird *>(animals[i])) {
                flyingBird->fly();
            }
        }

        delete animals[i];
    }
}
