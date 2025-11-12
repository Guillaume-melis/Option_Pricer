#include "Option.hpp"
#include "OptionBin.hpp"
#include "Utils.hpp"
#include <algorithm>

OptionBin::OptionBin(double K, double T, OptionType type, std::shared_ptr<PayoffBin> payoff) : Option(K, T, type, std::move(payoff))
{

}

double OptionBin::simulate_payoff(double S0, double r, double sigma, int n_steps) const
{
        n_steps = (int)(*this).get_Maturity() * 252;
        double dt = (*this).get_Maturity() / n_steps;
        double S = S0;

        for (int i = 0; i < n_steps; ++i)
        {
            double Z = rand_normal();
            S *= std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
        }

        return payoff(S);
}