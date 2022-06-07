#include "fractions.h"

static bool common_fractions = true;



//АЛГОРИТМ ЕВКЛИДА
int gcd(int a, int b) {
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

const pair<int, int>& Fractions::getFraction() const
{
    return fraction;
}

void Fractions::setFraction(const pair<int, int>& newFraction)
{
    fraction = newFraction;
}

void Fractions::simpler_Fractions(Fractions& Fraction)
{
        bool negative = false;
        if(Fraction.fraction.first < 0 && Fraction.fraction.second < 0)
        {
            Fraction.fraction.first *= -1;
            Fraction.fraction.second *= -1;
        }
        else if(Fraction.fraction.first < 0)
        {
            negative = true;
            Fraction.fraction.first *= -1;
        }
        else if(Fraction.fraction.second < 0)
        {
            negative = true;
            Fraction.fraction.second *= -1;
        }

         int mod = gcd(Fraction.fraction.first, Fraction.fraction.second);
         Fraction.fraction.first /= mod;
         Fraction.fraction.second /= mod;

        if(negative)
            Fraction.fraction.first *= -1;
}

Fractions Fractions::absFraction()
{
    return Fractions(abs(this->fraction.first), abs(this->fraction.second));
}



Fractions Fractions::operator +(Fractions& rhs)
{
    Fractions result(this->fraction.first * rhs.fraction.second + rhs.fraction.first * this->fraction.second, this->fraction.second * rhs.fraction.second);
    simpler_Fractions(result);
    return result;
}

Fractions Fractions::operator -(Fractions& rhs)
{
    Fractions result(this->fraction.first * rhs.fraction.second - rhs.fraction.first * this->fraction.second, this->fraction.second * rhs.fraction.second);
    simpler_Fractions(result);
    return result;
}

Fractions Fractions::operator *(Fractions& rhs)
{
    Fractions result(this->fraction.first * rhs.fraction.first, this->fraction.second * rhs.fraction.second);
    simpler_Fractions(result);
    return result;
}

Fractions Fractions::operator /(Fractions& rhs)
{
    Fractions result(this->fraction.first * rhs.fraction.second, this->fraction.second * rhs.fraction.first);
    simpler_Fractions(result);
    return result;
}

bool Fractions::operator ==(Fractions& rhs)
{
    return this->fraction.first == rhs.fraction.first && this->fraction.second == rhs.fraction.second;
}

bool Fractions::operator ==(const Fractions& rhs) const
{
    return this->fraction.first == rhs.fraction.first && this->fraction.second == rhs.fraction.second;
}

bool Fractions::operator <(Fractions& rhs)
{
    return static_cast<double>(static_cast<double>(this->fraction.first) / static_cast<double>(this->fraction.second)) < static_cast<double>(static_cast<double>(rhs.fraction.first) / static_cast<double>(rhs.fraction.second));
}

bool Fractions::operator <(const Fractions& rhs) const
{
    return static_cast<double>(static_cast<double>(this->fraction.first) / static_cast<double>(this->fraction.second)) < static_cast<double>(static_cast<double>(rhs.fraction.first) / static_cast<double>(rhs.fraction.second));
}

bool Fractions::operator >(int rhs)
{
    return static_cast<double>(static_cast<double>(this->fraction.first) / static_cast<double>(this->fraction.second)) > rhs;
}

bool Fractions::operator ==(int rhs)
{
    return static_cast<double>(static_cast<double>(this->fraction.first) / static_cast<double>(this->fraction.second)) == rhs;
}

Fractions::operator string() const
{
    if (common_fractions && fraction.first != 0)
    {
        if (fraction.second == 1)
            return to_string(fraction.first);

        return (to_string(fraction.first) + "/" + to_string(fraction.second));
    }
    if (fraction.first == 0)
        return "0";
    return to_string(static_cast<double>(fraction.first) / static_cast<double>(fraction.second));
}

bool Fractions::operator <(int rhs)
{
    return static_cast<double>(static_cast<double>(this->fraction.first) / static_cast<double>(this->fraction.second)) < rhs;
}


void Fractions::setCommon_fractions(bool newCommon_fractions)
{
    common_fractions = newCommon_fractions;
}

Fractions::Fractions()
{

}

Fractions::Fractions(int x, int y)
{
    fraction = { x, y };
}
