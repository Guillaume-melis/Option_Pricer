#ifndef PAYOFF_BIN_HPP
#define PAYOFF_BIN_HPP

#include "Payoff.hpp"
#include <algorithm>

struct PayoffBin : public Payoff
{
    double K_;
    explicit PayoffBin(double K) : K_(K) {};

    double operator()(double ST) const override
    {
        if(ST > K_)
            return 1;
        else
            return 0;
    }
};

#endif