#include <cmath>
#include <random>
#include "Utils.hpp"

double norm_cdf(double x)
{
    return 0.5 * std::erfc(-x / std::sqrt(2));
}

double rand_normal()
{
    static std::mt19937 gen(std::random_device{}()); // Générateur de nombres aléatoires
    static std::normal_distribution<> dist(0.0, 1.0); // Distribution normale standard
    return dist(gen);
}

double norm_pdf(double x)
{
    return (1.0 / std::sqrt(2.0 * M_PI)) * std::exp(-0.5 * x * x);
}