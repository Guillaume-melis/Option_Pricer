#include "Option.hpp"
#include "AsianOption.hpp"
#include "Utils.hpp"


AsianOption::AsianOption(double K, double T, OptionType type, std::shared_ptr<Payoff> pyf, AverageType average) : Option(K, T, type, pyf)
{
    average_type_ = average;
}

double AsianOption::simulate_payoff(double S0, double r, double sigma, int n_steps) const
{
    n_steps = (int)(*this).get_Maturity() * 252;
    double dt = (*this).get_Maturity() / n_steps;
    double S = S0;

    if (average_type_ == AverageType::Geometric)
    {
        double G = 0.0;
        double sum = 0.0;
        for(int i=0; i<n_steps; i++)
        {
            double Z = rand_normal();
            S *= std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
            sum += std::log(S);
        }
        G = std::exp((1/(double)n_steps) * sum);
       return payoff(G);
    }
    else 
    {
        double A = 0.0;
        double sum = 0.0;
        for(int i=0; i<n_steps; i++)
        {
            double Z = rand_normal();
            S *= std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
            sum += S;
        }
        A = (1/(double)n_steps) * sum;
        return payoff(A);
    }
}