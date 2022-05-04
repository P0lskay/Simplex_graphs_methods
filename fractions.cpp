#include "fractions.h"

const pair<int, int> &Fractions::getFraction() const
{
    return fraction;
}

void Fractions::setFraction(const pair<int, int> &newFraction)
{
    fraction = newFraction;
}

void Fractions::simpler_Fractions(Fractions& Fraction)
{
    for(int i = Fraction.fraction.first; i > 1; i--)
    {
        if(Fraction.fraction.first%i == 0 && Fraction.fraction.second%i == 0)
        {
            Fraction.fraction.first /= i;
            Fraction.fraction.second /= i;
            break;
        }
    }
}

Fractions Fractions::operator +(Fractions &rhs)
{
    Fractions result(this->fraction.first*rhs.fraction.second + rhs.fraction.first*this->fraction.second, this->fraction.second*rhs.fraction.second);
    simpler_Fractions(result);
    return result;
}

Fractions Fractions::operator -(Fractions &rhs)
{
    Fractions result(this->fraction.first*rhs.fraction.second - rhs.fraction.first*this->fraction.second, this->fraction.second*rhs.fraction.second);
    simpler_Fractions(result);
    return result;
}

Fractions Fractions::operator *(Fractions &rhs)
{
    Fractions result(this->fraction.first*rhs.fraction.first, this->fraction.second*rhs.fraction.second);
    simpler_Fractions(result);
    return result;
}

Fractions Fractions::operator /(Fractions &rhs)
{
    Fractions result(this->fraction.first*rhs.fraction.second, this->fraction.second*rhs.fraction.first);
    simpler_Fractions(result);
    return result;
}

bool Fractions::operator ==(Fractions &rhs)
{
    return this->fraction.first == rhs.fraction.first && this->fraction.second == rhs.fraction.second;
}

bool Fractions::operator <(Fractions &rhs)
{
    return static_cast<double>(this->fraction.first/this->fraction.second) < static_cast<double>(rhs.fraction.first/rhs.fraction.second);
}

bool Fractions::operator <(const Fractions& rhs) const
{
    return static_cast<double>(this->fraction.first/this->fraction.second) < static_cast<double>(rhs.fraction.first/rhs.fraction.second);
}

bool Fractions::operator >(int rhs)
{
    return static_cast<double>(this->fraction.first/this->fraction.second) > rhs;
}

 bool Fractions::operator <(int rhs)
 {
    return static_cast<double>(this->fraction.first/this->fraction.second) < rhs;
 }


Fractions::Fractions(int x, int y)
{
    fraction = {x, y};
}
