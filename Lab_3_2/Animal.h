#ifndef ANIMAL_H
#define ANIMAL_H


class Animal {
public:
    virtual ~Animal() = default;

    virtual void breathe() const = 0;

    virtual void eat() const = 0;
};
#endif //ANIMAL_H
