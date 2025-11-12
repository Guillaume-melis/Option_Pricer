#ifndef ASIAN_OPTION_HPP
#define ASIAN_OPTION_HPP

#include "Option.hpp"

enum class AverageType {Geometric, Arithmetic};

class AsianOption : public Option
{
    AverageType average_type_;

    public : 
    AsianOption(double K, double T, OptionType type, std::shared_ptr<Payoff> pyf, AverageType average);
    double simulate_payoff(double S0, double r, double sigma, int n_steps=252) const override;
};  

#endif