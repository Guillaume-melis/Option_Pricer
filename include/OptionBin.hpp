#ifndef OPTION_BIN_HPP
#define OPTION_BIN_HPP

#include "Option.hpp"
#include "PayoffBin.hpp"
#include "Utils.hpp"
#include <memory>

class OptionBin : public Option
{
    std::shared_ptr<PayoffBin> payoff_;

    public : 
    OptionBin(double K, double T, OptionType opt, std::shared_ptr<PayoffBin> payoff);
    double simulate_payoff(double S0, double r, double sigma, int n_steps = 252) const override;
};

#endif