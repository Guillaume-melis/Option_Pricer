#include <iostream>
#include "Utils.hpp"
#include "Option.hpp"
#include "Pricer.hpp"
#include "MarketData.hpp"
#include <algorithm>
#include <cmath>
#include <random>
#include <array>

/*Pricer::Pricer(Option opt, MarketData mkt)
{

    MC_price_ = compute_MonteCarlo_price(opt,mkt,1000000);
    BS_price_ = compute_BlackScholes_price(opt,mkt);

    
};

double Pricer::compute_MonteCarlo_price(Option opt, MarketData mkt, int n_simulations) // C++ est construit pour travailler avec des boucles pas des vecteurs
    {
        std::vector <double> payoffs;
        double T = opt.get_Maturity();
        double S0 = mkt.get_Spot();
        double sigma = mkt.get_volatility();
        double r = mkt.get_rates();
        double K = opt.get_Strike();

        for(int i=0; i < n_simulations; i++)
        {
            double Wt = rand_normal() * std::sqrt(T);
            double St = S0 * std::exp(sigma*Wt + (r-0.5*sigma*sigma)*T);

            double payoff;
            if(opt.get_OptionType() == OptionType::Call)
            {
                payoff = std::max(St-K, 0.0);
            }
            else if(opt.get_OptionType() == OptionType::Put)
            {
                payoff = std::max(K-St,0.0);
            }
            payoffs.push_back(payoff);

        }

        double sum = std::accumulate(payoffs.begin(), payoffs.end(), 0.0);
        double mean_payoff = sum/payoffs.size();

        double std_dev = 0.0;
        for(double p : payoffs)
        {
            std_dev += (p - mean_payoff) * (p - mean_payoff);
        }
        std_dev = std_dev/(payoffs.size());

        double upper_bound = mean_payoff + 1.96*std_dev/std::sqrt(n_simulations);
        double lower_bound = mean_payoff - 1.96*std_dev/std::sqrt(n_simulations);

        std::cout << "Upper bound price : " << upper_bound << std::endl;
        std::cout << "Prix Monter Carlo : " << mean_payoff << std::endl;
        std::cout << "Lower bound price : " << lower_bound << std::endl;

        return mean_payoff;

    } 

double Pricer::compute_BlackScholes_price(Option opt, MarketData mkt)
    {
        double S = mkt.get_Spot();
        double K = opt.get_Strike();
        double r = mkt.get_rates();
        double T = opt.get_Maturity();
        double sigma = mkt.get_volatility();

        double d1 = (std::log(S/K) + (r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));
        double d2 = d1 - sigma*std::sqrt(T);

        double option_price = 0.0;
        if(opt.get_OptionType() == OptionType::Call)
        {
            option_price = S*norm_cdf(d1) - K*std::exp(-r*T)*norm_cdf(d2);
        }
        else if(opt.get_OptionType() == OptionType::Put)
        {
            option_price = K*std::exp(-r*T)*norm_cdf(-d2) - S*norm_cdf(-d1);
        }

        std::cout << "Prix de l'option sous Black Scholes : " << option_price << std::endl;

        return option_price;
    }

double Pricer::get_MC_price() {return MC_price_;}
double Pricer::get_BS_price() {return BS_price_;}*/