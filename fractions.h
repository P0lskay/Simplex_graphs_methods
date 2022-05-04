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
    //Метод отвечающий за упрощение дроби
    void simpler_Fractions(Fractions& Fraction);

    Fractions operator +(Fractions& rhs);
    Fractions operator -(Fractions& rhs);
    Fractions operator *(Fractions& rhs);
    Fractions operator /(Fractions& rhs);
    bool operator ==(Fractions& rhs);
    bool operator <(Fractions& rhs);
    bool operator <(const Fractions& rhs) const;
    bool operator <(int rhs);
    bool operator >(int rhs);

};


#endif // FRACTIONS_H
