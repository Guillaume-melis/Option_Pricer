#ifndef PRICER_CPP
#define PRICER_CPP

#include "MarketData.hpp"
#include "Option.hpp"

class Pricer
{
    double MC_price_, BS_price_;
    double compute_MonteCarlo_price(Option opt, MarketData mkt, int n_sim);
    double compute_BlackScholes_price(Option opt, MarketData mkt);

    public :
    Pricer(Option opt, MarketData mkt);
    double get_MC_price();
    double get_BS_price();
};

#endif