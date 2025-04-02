#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
    virtual ~Figure() = default;

    virtual double CalcArea() const = 0;

    virtual void Show() const = 0;
};
#endif //FIGURE_H
