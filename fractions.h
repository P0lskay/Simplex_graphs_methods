#ifndef FRACTIONS_H
#define FRACTIONS_H

#include <utility>
#include <string>

using namespace std;

class Fractions
{
    pair<int, int> fraction;

public:
    Fractions();
    explicit Fractions(int x, int y = 1);

    const pair<int, int> &getFraction() const;
    void setFraction(const pair<int, int> &newFraction);
    //Метод отвечающий за упрощение дроби
    void simpler_Fractions(Fractions& Fraction);

    Fractions absFraction();

    Fractions operator +(Fractions& rhs);
    Fractions operator -(Fractions& rhs);
    Fractions operator *(Fractions& rhs);
    Fractions operator /(Fractions& rhs);
    bool operator ==(Fractions& rhs);
    bool operator ==(const Fractions& rhs) const;
    bool operator <(Fractions& rhs);
    bool operator <(const Fractions& rhs) const;
    bool operator <(int rhs);
    bool operator >(int rhs);
    bool operator ==(int rhs);
    operator string() const;

    static void setCommon_fractions(bool newCommon_fractions);
};

#endif // FRACTIONS_H
