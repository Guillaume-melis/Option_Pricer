#ifndef OPTION_HPP
#define OPTION_HPP

#include "Payoff.hpp"
#include <memory>

enum class OptionType {Call, Put};

class Option
{
    double K_; 
    double T_;
    OptionType type_;
    std::shared_ptr<Payoff> payoff_;

    public:
    Option(double K, double T, OptionType type, std::shared_ptr<Payoff> pyf)
    {
        K_ = K; 
        T_ = T;
        type_ = type; 
        payoff_ = pyf;
    }
    virtual ~Option() = default;

    double get_Maturity() const {return T_;}
    double get_Strike() const {return K_;}
    OptionType get_OptionType() const {return type_;}

    virtual double payoff(double ST) const
    {
        return (*payoff_)(ST);
    }
    virtual double simulate_payoff(double S0, double r, double sigma, int n_steps = 252) const = 0;

    virtual bool has_barrier() const { return false; }
    virtual double get_barrier() const
    {
        throw std::logic_error("This option type has no barrier.");
    }
};

#endif