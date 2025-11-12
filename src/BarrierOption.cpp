#include "Option.hpp"
#include "BarrierOption.hpp"
#include "Utils.hpp"


BarrierOption::BarrierOption(double K, double T, OptionType type, std::shared_ptr<Payoff> pyf, double B) : Option(K,T,type, std::move(pyf))
{

}

double BarrierOption::simulate_payoff(double S0, double r, double sigma, int n_steps) const
{
    n_steps = (int)(*this).get_Maturity() * 252;
    double dt = (*this).get_Maturity() / n_steps;
    double S = S0;
    double B = B_;

    for (int i = 0; i < n_steps; ++i)
    {
        double Z = rand_normal();
        S *= std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);

        if(S <= B)
            return 0.0;
    }

    return payoff(S);
}


