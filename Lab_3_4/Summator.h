#ifndef SUMMATOR_H
#define SUMMATOR_H

class Summator {
public:
    virtual ~Summator() = default;

    virtual int transform(int i) const;

    int sum(int N) const;
};
#endif //SUMMATOR_H
