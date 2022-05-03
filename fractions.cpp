#include "fractions.h"

const pair<int, int> &Fractions::getFraction() const
{
    return fraction;
}

void Fractions::setFraction(const pair<int, int> &newFraction)
{
    fraction = newFraction;
}

Fractions Fractions::operator +(Fractions &rhs)
{
    Fractions result(this->fraction.first*rhs.fraction.second + rhs.fraction.first*this->fraction.second, this->fraction.second*rhs.fraction.second);
    return result;
}

Fractions Fractions::operator -(Fractions &rhs)
{
    Fractions result(this->fraction.first*rhs.fraction.first, this->fraction.second*rhs.fraction.second);
    return result;
}

Fractions::Fractions(int x, int y)
{
    fraction = {x, y};
}
