#include <iostream>
#include "MarketData.hpp"


MarketData::MarketData(double r, double S, double sigma) 
    {
        r_ = r; 
        S_ = S; 
        sigma_ = sigma;
        std::cout << "Données de marché " << " "
                  << "Taux d'intérêt : " << r << " "
                  << "Niveau du spot : " << S << " "
                  << "Volatilité : " << sigma << std::endl;
    };
double MarketData::get_rates() const {return r_;}
double MarketData::get_volatility() const {return sigma_;}
double MarketData::get_Spot() const {return S_;}
