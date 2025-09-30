#include <iostream>
#include "include/Option.hpp"
#include "include/Pricer.hpp"
#include "include/Greeks.hpp"
#include "include/MarketData.hpp"

int main()
{
    Option Call_vanille(110.0,1.0,OptionType::Call);
    Option Put_vanille(90.0,1,OptionType::Put);
    MarketData market(0.05,100.0,0.2);
    Pricer prix_Call(Call_vanille,market);
    Pricer prix_Put(Put_vanille,market);
    Greeks sensi_Call(Call_vanille,market), sensi_Put(Put_vanille,market);

    std::cout << "Pour le Call " 
              << prix_Call.get_BS_price() << " " 
              << "Delta : " << sensi_Call.get_Delta() << " "
              << "Gamma : " << sensi_Call.get_Gamma() << " "
              << "Vega : " << sensi_Call.get_Vega() << std::endl;
    
    std::cout << "Pour le Put " 
              << prix_Put.get_BS_price() << " " 
              << "Delta : " << sensi_Put.get_Delta() << " "
              << "Gamma : " << sensi_Put.get_Gamma() << " "
              << "Vega : " << sensi_Put.get_Vega() << std::endl;

    return 0;

}
