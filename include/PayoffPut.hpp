#ifndef PAYOFF_PUT_HPP
#define PAYOFF_PUT_HPP

#include "Payoff.hpp"
#include <algorithm>

struct PayoffPut : public Payoff
{
    double K_;
    explicit PayoffPut(double K) : K_(K) {}

    double operator()(double ST) const override
    {
        return std::max(K_ - ST, 0.0);
    }
};

#endif