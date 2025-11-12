#ifndef EUROPEAN_OPTION_HPP
#define EUROPEAN_OPTION_HPP

#include "Option.hpp"
#include <memory>

class EuropeanOption : public Option
{
    public :
    EuropeanOption(double K, double T, OptionType type, std::shared_ptr<Payoff> pyf);
    double simulate_payoff(double S0, double r, double sigma, int n_steps=252) const override;
}; 

#endif