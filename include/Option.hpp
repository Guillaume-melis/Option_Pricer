#ifndef OPTION_HPP
#define OPTION_HPP

enum class OptionType {Call, Put};

class Option
{
    double K_; 
    double T_;
    OptionType type_;

    public:
    Option(double K, double T, OptionType type);
    double get_Maturity() const;
    double get_Strike() const;
    OptionType get_OptionType() const;

};

#endif