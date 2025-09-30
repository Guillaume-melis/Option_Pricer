#include <iostream>
#include "Option.hpp"
#include "MarketData.hpp"
#include "Greeks.hpp"
#include "Utils.hpp"


Greeks::Greeks(Option opt, MarketData mkt) {
    Delta_ = compute_Delta(opt, mkt);
    Gamma_ = compute_Gamma(opt, mkt);
    Vega_ = compute_Vega(opt, mkt);
    Rho_ = compute_Rho(opt, mkt);
    Theta_ = compute_Theta(opt, mkt);
}

double Greeks::compute_Delta(Option opt, MarketData mkt)
{
    double S = mkt.get_Spot();
    double K = opt.get_Strike();
    double r = mkt.get_rates();
    double T = opt.get_Maturity();
    double sigma = mkt.get_volatility();
    double delta = 0.0;
    double d1 = (std::log(S/K) + (r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));
    if(opt.get_OptionType() == OptionType::Call)
    {
        
        delta =  norm_cdf(d1);
    }
    else if(opt.get_OptionType() == OptionType::Put)
    {
        delta = norm_cdf(d1) - 1;
    }
    return delta;

}

double Greeks::compute_Gamma(Option opt, MarketData mkt)
{
        double S = mkt.get_Spot();
        double K = opt.get_Strike();
        double r = mkt.get_rates();
        double T = opt.get_Maturity();
        double sigma = mkt.get_volatility();
        double d1 = (std::log(S/K) + (r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));

        double gamma;
        gamma = norm_pdf(d1)/(S*sigma*std::sqrt(T));

        return gamma; 
}

double Greeks::compute_Vega(Option opt, MarketData mkt)
{
    double S = mkt.get_Spot();
    double K = opt.get_Strike();
    double r = mkt.get_rates();
    double T = opt.get_Maturity();
    double sigma = mkt.get_volatility();
    double d1 = (std::log(S/K) + (r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));

    double vega;
    vega = S*std::sqrt(T)*norm_pdf(d1);
    return vega;
}

double Greeks::compute_Rho(Option opt, MarketData mkt)
{
    double S = mkt.get_Spot();
    double K = opt.get_Strike();
    double r = mkt.get_rates();
    double T = opt.get_Maturity();
    double sigma = mkt.get_volatility();
    double d1 = (std::log(S/K) + (r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));
    double d2 = d1 - sigma*std::sqrt(T);

    double rho = 0.0; 
    if(opt.get_OptionType() == OptionType::Call)
    {
        rho = K*T*std::exp(-r*T)*norm_cdf(d2);
    }
    else if(opt.get_OptionType() == OptionType::Put)
    {
        rho = K*T*std::exp(-r*T)*norm_cdf(-d2);
    }
    return rho;
}

double Greeks::compute_Theta(Option opt, MarketData mkt)
{
    double S = mkt.get_Spot();
    double K = opt.get_Strike();
    double r = mkt.get_rates();
    double T = opt.get_Maturity();
    double sigma = mkt.get_volatility();
    double d1 = (std::log(S/K) + (r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));
    double d2 = d1 - sigma*std::sqrt(T);

    double theta = 0.0;
    if(opt.get_OptionType() == OptionType::Call)
    {
        theta = -(S*norm_pdf(d1)*sigma)/(2*std::sqrt(T)) - r*K*std::exp(-r*T)*norm_cdf(d2);
    }
    else if(opt.get_OptionType() == OptionType::Put)
    {
        theta = -(S*norm_pdf(d1)*sigma)/(2*std::sqrt(T)) + r*K*std::exp(-r*T)*norm_cdf(-d2);
    }
    return theta;
}

double Greeks::get_Delta() const {return Delta_;}
double Greeks::get_Gamma() const {return Gamma_;}
double Greeks::get_Vega() const {return Vega_;}
double Greeks::get_Rho() const {return Rho_;}
double Greeks::get_Theta() const {return Theta_;}