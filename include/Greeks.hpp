#ifndef GREEK_HPP
#define GREEK_HPP

#include "Option.hpp"
#include "MarketData.hpp"
#include "Utils.hpp"

class Greeks
{
    double Delta_, Gamma_, Vega_, Rho_, Theta_;

    double compute_Delta(Option opt, MarketData mkt);
    double compute_Gamma(Option opt, MarketData mkt);
    double compute_Vega(Option opt, MarketData mkt);
    double compute_Rho(Option opt, MarketData mkt);
    double compute_Theta(Option opt, MarketData mkt);
    

    public :
    Greeks(Option opt, MarketData mkt);
    double get_Delta() const;
    double get_Gamma() const;
    double get_Vega() const;
    double get_Rho() const;
    double get_Theta() const;
};

#endif