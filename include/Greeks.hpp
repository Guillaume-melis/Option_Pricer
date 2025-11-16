#ifndef GREEK_HPP
#define GREEK_HPP

#include "Option.hpp"
#include "MarketData.hpp"
#include "Utils.hpp"
#include "MultiPricer.hpp"
#include "AsianOption.hpp"
#include "EuropeanOption.hpp"
#include "BarrierOption.hpp"
#include "OptionBin.hpp"

template <typename T>
class Greeks
{
    double Delta_, Gamma_, Vega_, Rho_, Theta_;

    double compute_Delta(const T& opt, MarketData mkt)
    {
        double sigma = mkt.get_volatility();
        double r = mkt.get_rates();
        double S = mkt.get_Spot();

        double h = 0.01*S;

        MarketData mkt_up(r, S+h, sigma);
        MultiPricer<T> pricer_up(opt, mkt_up);
        double V_up = pricer_up.get_price();

        MarketData mkt_down(r, S-h, sigma);
        MultiPricer<T> pricer_down(opt, mkt_down);
        double V_down = pricer_down.get_price();

        double Delta = (V_up - V_down)/(2 * h);

        return Delta;
        
    }
    double compute_Gamma(const T& opt, MarketData mkt)
    {
        double sigma = mkt.get_volatility();
        double r = mkt.get_rates();
        double S = mkt.get_Spot();

        double h = 0.01*S;

        MarketData mkt_up(r, S+h, sigma);
        MultiPricer<T> pricer_up(opt, mkt_up);
        double V_up = pricer_up.get_price();

        MultiPricer<T> pricer_mid(opt, mkt);
        double V_mid = pricer_mid.get_price();

        MarketData mkt_down(r, S-h, sigma);
        MultiPricer<T> pricer_down(opt, mkt_down);
        double V_down = pricer_down.get_price();

        double Gamma = (V_up - 2.0 * V_mid + V_down) / (h * h);

        return Gamma;
    }
    double compute_Vega(const T& opt, MarketData mkt)
    {
        double sigma = mkt.get_volatility();
        double r = mkt.get_rates();
        double S = mkt.get_Spot();

        double h = 0.01*sigma;

        MarketData mkt_up(r,S,sigma+h);
        MultiPricer<T> pricer_up(opt, mkt_up);
        double V_up = pricer_up.get_price();

        MarketData mkt_down(r,S,sigma-h);
        MultiPricer<T> pricer_down(opt, mkt_down);
        double V_down = pricer_down.get_price();

        double Vega = (V_up - V_down)/(2*h);
        return Vega;
    }
    double compute_Rho(const T& opt, MarketData mkt)
    {
        double sigma = mkt.get_volatility();
        double r = mkt.get_rates();
        double S = mkt.get_Spot();

        double h = 0.0001;

        MarketData mkt_up(r+h,S,sigma);
        MultiPricer<T> pricer_up(opt, mkt_up);
        double V_up = pricer_up.get_price();

        MarketData mkt_down(r-h,S,sigma);
        MultiPricer<T> pricer_down(opt, mkt_down);
        double V_down = pricer_down.get_price();

        double Rho = (V_up - V_down)/(2*h);
        return Rho;
    }
    double compute_Theta(const T& opt, MarketData mkt)
    {
        double h = 1.0/365; 

        MultiPricer<T> pricer_today(opt, mkt);
        double V_today = pricer_today.get_price();

        T opt_shorter(opt.get_Strike(), opt.get_Maturity()-h, opt.get_OptionType(),opt.get_Payoff());

        MultiPricer<T> pricer_earlier(opt_shorter, mkt);
        double V_earlier = pricer_earlier.get_price();

        double Theta = -(V_today - V_earlier)/h;
        return Theta;
    }
    

    public :
    Greeks(const T& opt, MarketData mkt)
    {
        Delta_ = compute_Delta(opt, mkt);
        Vega_ = compute_Vega(opt,mkt);
        Gamma_ = compute_Gamma(opt, mkt);
        Rho_ = compute_Rho(opt, mkt);
        Theta_ = compute_Theta(opt,mkt);
    }
    double get_Delta() const {return Delta_;}
    double get_Gamma() const {return Gamma_;}
    double get_Vega() const {return Vega_;}
    double get_Rho() const {return Rho_;}
    double get_Theta() const {return Theta_;}
};

#endif