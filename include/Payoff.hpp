#ifndef PAYOFF_HPP
#define PAYOFF_HPP

struct Payoff
{
    virtual double operator()(double ST) const = 0; 
    virtual ~Payoff() = default;                  
};

#endif
