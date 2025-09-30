#ifndef MARKETDATA_HPP
#define MARKETDATA_HPP

class MarketData
{
    double r_;
    double sigma_;
    double S_;

    public : 
    MarketData(double r, double S, double sigma);
    double get_rates() const;
    double get_volatility() const; 
    double get_Spot() const;
};

#endif