#ifndef FRACTIONS_H
#define FRACTIONS_H

#include <utility>

using namespace std;

class Fractions
{
    pair<int, int> fraction;

public:
    explicit Fractions(int x, int y = 1);

    const pair<int, int> &getFraction() const;
    void setFraction(const pair<int, int> &newFraction);

    Fractions operator +(Fractions& rhs);
    Fractions operator -(Fractions& rhs);
    Fractions operator *(Fractions& rhs);

};

#endif // FRACTIONS_H
