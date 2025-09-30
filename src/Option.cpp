#include <iostream>
#include "Option.hpp"

Option::Option(double K, double T, OptionType type)
{
    K_ = K;
    std::cout << "Option de strike :" << K << std::endl;
    T_ = T;
    std::cout << "Option de maturité :" << T << "années" << std::endl;
    type_ = type;
    if(type == OptionType::Call)
        {std::cout << "Option de type call" << std::endl;}
    else { std::cout << "Option de type Put" << std::endl;}

};

double Option::get_Maturity() const { return T_;}
double Option::get_Strike() const { return K_;}
OptionType Option::get_OptionType() const {return type_;}

