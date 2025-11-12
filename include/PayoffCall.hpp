#ifndef PAYOFF_CALL_HPP
#define PAYOFF_CALL_HPP

#include "Payoff.hpp"
#include <algorithm>

struct PayoffCall : public Payoff
{
    double K_;
    explicit PayoffCall(double K) : K_(K) {};

    double operator()(double ST) const override
    {
        return std::max(ST - K_,0.0);
    }
};

#endif