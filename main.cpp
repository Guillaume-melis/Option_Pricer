#include <iostream>
#include <memory>

#include "include/Option.hpp"
#include "include/AsianOption.hpp"
#include "EuropeanOption.hpp"
#include "include/OptionBin.hpp"
#include "include/BarrierOption.hpp"
#include "include/MarketData.hpp"
#include "include/MultiPricer.hpp"
#include "include/Payoff.hpp"
#include "PayoffCall.hpp"
#include "PayoffPut.hpp"
#include "PayoffBin.hpp"

int main()
{
    // --- Market data ---
    MarketData market(0.05, 100.0, 0.2); // Spot=100, rate=5%, vol=20%

    // --- Payoffs ---
    auto call_payoff = std::make_shared<PayoffCall>(110.0);
    auto put_payoff  = std::make_shared<PayoffPut>(90.0);
    auto bin_payoff  = std::make_shared<PayoffBin>(100.0); // si tu as défini
    auto barrier_payoff = std::make_shared<PayoffCall>(100.0);

    // --- Options ---
    EuropeanOption call_vanille(110.0, 1.0, OptionType::Call, call_payoff);
    EuropeanOption put_vanille(90.0, 1.0, OptionType::Put, put_payoff);
    OptionBin      binary_call(100.0, 1.0, OptionType::Call, bin_payoff);
    BarrierOption  barrier_call(100.0, 1.0, OptionType::Call, barrier_payoff, 90.0);

    call_payoff = std::make_shared<PayoffCall>(100.0);
    AsianOption    asian_call(100.0, 1.0, OptionType::Call, call_payoff, AverageType::Arithmetic);

    // --- MultiPricer pour toutes les options ---
    MultiPricer<EuropeanOption> pricer_call(call_vanille, market);
    MultiPricer<EuropeanOption> pricer_put(put_vanille, market);
    MultiPricer<AsianOption>    pricer_asian(asian_call, market);
    MultiPricer<OptionBin>      pricer_binary(binary_call, market);
    MultiPricer<BarrierOption>  pricer_barrier(barrier_call, market);

    // --- Affichage des prix Monte Carlo ---
    std::cout << "Call vanille MC price     : " << pricer_call.get_price() << std::endl;
    std::cout << "Put vanille MC price      : " << pricer_put.get_price() << std::endl;
    std::cout << "Asian call MC price       : " << pricer_asian.get_price() << std::endl;
    std::cout << "Binary call MC price      : " << pricer_binary.get_price() << std::endl;
    std::cout << "Barrier call MC price     : " << pricer_barrier.get_price() << std::endl;

    // --- Partie Greeks (commentée pour l'instant) ---
    /*
    Greeks sensi_call(call_vanille, market);
    Greeks sensi_put(put_vanille, market);

    std::cout << "Call vanille Greeks - Delta: " << sensi_call.get_Delta()
              << ", Gamma: " << sensi_call.get_Gamma()
              << ", Vega: " << sensi_call.get_Vega() << std::endl;

    std::cout << "Put vanille Greeks - Delta: " << sensi_put.get_Delta()
              << ", Gamma: " << sensi_put.get_Gamma()
              << ", Vega: " << sensi_put.get_Vega() << std::endl;
    */

    return 0;
}
