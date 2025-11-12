#ifndef MULTI_PRICER_HPP
#define MULTI_PRICER_HPP

#include <vector>
#include "Option.hpp"

template<typename T>
class MultiPricer
{
    double MC_price_;
    double compute_MonteCarlo(const T& opt, MarketData mkt, int n_sim)
    {
        double maturity = opt.get_Maturity();
        double S0 = mkt.get_Spot();
        double sigma = mkt.get_volatility();
        double r = mkt.get_rates();

        double sum = 0.0;

        for(int i=0; i<n_sim; i++)
        {
            sum += opt.simulate_payoff(S0, r, sigma);
        }

        double result = std::exp(-r*maturity) * (sum/n_sim);
        return result;
    }

    public :
    MultiPricer(const T& opt, MarketData mkt)
    {
        MC_price_ = compute_MonteCarlo(opt, mkt,100000);
    }

    const double get_price() {return MC_price_;}
};

#endif