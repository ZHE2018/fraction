#include "fraction.h"
//============================================================================
// Name        : fraction.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "fraction.h"


#define ABS(x) ((x>0)?x:-x)

const fraction operator+(int x, const fraction& rv)
{
    return fraction(x) + rv;
}

const fraction operator-(int x, const fraction& rv)
{
    return fraction(x) - rv;
}

const fraction operator*(int x, const fraction& rv)
{
    return fraction(x) * rv;
}

const fraction operator/(int x, const fraction& rv)
{
    return fraction(x) / rv;
}

bool operator>(int x, const fraction& rv)
{
    return fraction(x) > rv;
}

bool operator>=(int x, const fraction& rv)
{
    return fraction(x) >= rv;
}

bool operator<(int x, const fraction& rv)
{
    return fraction(x) < rv;
}

bool operator<=(int x, const fraction& rv)
{
    return fraction(x) <= rv;
}

bool operator==(int x, const fraction& rv)
{
    return fraction(x) == rv;
}

bool operator!=(int x, const fraction& rv)
{
    return fraction(x) != rv;
}

fraction::fraction(int numerator, int denominator)
{
    if((numerator>=0 && denominator>0)|| (numerator<=0 && denominator<0))
    {
        this->numerator = ABS(numerator);
        this->denominator = ABS(denominator);
    }else{
        this->numerator = -ABS(numerator);
        this->denominator = ABS(denominator);
    }

}

fraction fraction::operator+(const fraction& rv) const
{
    fraction a = fraction(numerator*rv.denominator + rv.numerator*denominator, denominator*rv.denominator);
    a.fractionReduction();
    return a;
}

fraction fraction::operator-(const fraction& rv) const
{
    fraction a = fraction(numerator*rv.denominator - rv.numerator*denominator, denominator*rv.denominator);
    a.fractionReduction();
    return a;
}

fraction fraction::operator*(const fraction& rv) const
{
    fraction a = fraction(numerator * rv.numerator, denominator * rv.denominator);
    a.fractionReduction();
    return a;
}

fraction fraction::operator/(const fraction& rv) const
{
    fraction a = fraction(numerator * rv.denominator, denominator * rv.numerator);
    a.fractionReduction();
    return a;
}

fraction fraction::operator-()
{
    numerator = -numerator;
    return *this;
}

fraction& fraction::operator=(const fraction& rv)
{
    numerator=rv.numerator;
    denominator=rv.denominator;
    return *this;
}

bool fraction::operator>(const fraction& rv) const
{
    if(numerator*rv.denominator > rv.numerator*denominator)
        return true;
    else
        return false;
}

bool fraction::operator>=(const fraction& rv) const
{
    if(numerator*rv.denominator >= rv.numerator*denominator)
        return true;
    else
        return false;
}

bool fraction::operator<(const fraction& rv) const
{
    if(numerator*rv.denominator < rv.numerator*denominator)
        return true;
    else
        return false;
}

bool fraction::operator<=(const fraction& rv) const
{
    if(numerator*rv.denominator <= rv.numerator*denominator)
        return true;
    else
        return false;
}

bool fraction::operator==(const fraction& rv) const
{
    if(numerator*rv.denominator == rv.numerator*denominator)
        return true;
    else
        return false;
}

bool fraction::operator!=(const fraction& rv) const
{
    if(numerator*rv.denominator != rv.numerator*denominator)
        return true;
    else
        return false;
}


int fraction::maxFactor(int nr,int dr)
{
    int th=nr,tl=dr;
    if(nr<dr)
    {
        th=dr;
        tl=nr;
    }
    if(th%tl==0)
        return tl;
    else
        return maxFactor(tl,th%tl);
}

void fraction::fractionReduction()
{
    int a = maxFactor(ABS(denominator), ABS(numerator));
    if(a>1){
        denominator /= a;
        numerator /= a;
    }

    if((numerator>=0 && denominator>0)|| (numerator<=0 && denominator<0))
    {
        numerator = ABS(numerator);
        denominator = ABS(denominator);
    }else{
        numerator = -ABS(numerator);
        denominator = ABS(denominator);
    }
}

void fraction::reciprocal()
{
    if(numerator>=0)
    {
        int temp = numerator;
        numerator = denominator;
        denominator = temp;
    }else{
        int temp = numerator;
        numerator = -denominator;
        denominator = ABS(temp);
    }
}

fraction::~fraction()
{
}

