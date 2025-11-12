#ifndef BARRIER_OPTION_HPP
#define BARRIER_OPTION_HPP

#include "Option.hpp"

class BarrierOption : public Option
{
    double B_;

    public : 
    BarrierOption(double K, double T, OptionType type, std::shared_ptr<Payoff> pyf, double B);
    double simulate_payoff(double S0, double r, double sigma, int n_steps = 252) const override;
    bool has_barrier() const override {return true;}
};

#endif