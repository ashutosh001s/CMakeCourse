#include "my_mathlib.h"
#include "nlohmann/json.hpp"
#include <fmt/format.h>
#include <cxxopts.hpp>
#include <spdlog/spdlog.h>
#include "iostream"


/**
 * @brief Prints information about the library versions.
 */
void Math::PrintInfo()
{
    std::cout << "Hello from math lib\n";

    std::cout << "JSON LIB VERSION :";
    std::cout << NLOHMANN_JSON_VERSION_MAJOR << "."<<NLOHMANN_JSON_VERSION_MINOR << "."<<NLOHMANN_JSON_VERSION_PATCH<<"\n";

    std::cout << "CXXOPTS LIB VERSION :";
    std::cout << CXXOPTS__VERSION_MAJOR << "."<<CXXOPTS__VERSION_MINOR << "."<<CXXOPTS__VERSION_PATCH<<"\n";

    std::cout << "FMT LIB VERSION :";
    std::cout << FMT_VERSION<<"\n";

    std::cout << "SPDLOG LIB VERSION :";
    std::cout << SPDLOG_VER_MAJOR << "."<<SPDLOG_VER_MINOR << "."<<SPDLOG_VER_PATCH<<"\n";
}

unsigned int Math::Factorial( unsigned int number ) {
    return number <= 1 ? 1 : Factorial(number-1)*number;
}

/**
 * @brief function that adds two integers.
 *
 * @param a The first integer to add
 * @param b The second integer to add
 *
 * @return The sum of the two integers
 *
 * @throws None
 */
int Math::Add(int a, int b)
{
    return a + b;
}

float Math::Add(float a, float b)
{
    return a + b;
}

double Math::Add(double a, double b)
{
    return a + b;
}

int Math::Subtract(int a, int b)
{
    return a - b;
}

float Math::Subtract(float a, float b)
{
    return a - b;
}

double Math::Subtract(double a, double b)
{
    return a - b;
}

int Math::Multiply(int a, int b)
{
    return a * b;
}

float Math::Multiply(float a, float b)
{
    return a * b;
}

double Math::Multiply(double a, double b)
{
    return a * b;
}

int Math::Divide(int a, int b)
{
    return a / b;
}

float Math::Divide(float a, float b)
{
    return a / b;
}

double Math::Divide(double a, double b)
{
    return a / b;
}
