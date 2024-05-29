#include<iostream>
#include "my_mathlib.h"

int main()
{
    // std::cout << project_name << std::endl;
    // std::cout << project_version << std::endl;
    int x[2];
    x[0] = 1328;
    x[1] = 1228;
    std::cout << x[0] << x[1];
    // std::cout << "Json Lib Version : " << NLOHMANN_JSON_VERSION_MAJOR << NLOHMANN_JSON_VERSION_MINOR << NLOHMANN_JSON_VERSION_PATCH << std::endl;
    Math::PrintInfo();
    std::cout << Math::Add(2,3) << std::endl;
    std::cout << Math::Add(2.0f,3.0f) << std::endl;
    std::cout << Math::Add(2.0,3.0) << std::endl;

    std::cout << Math::Subtract(10,5) << std::endl;;
    std::cout << Math::Subtract(10.0f,5.0f) << std::endl;;
    std::cout << Math::Subtract(10.0,5.0) << std::endl;;

    std::cout << Math::Multiply(5,5) << std::endl;;
    std::cout << Math::Multiply(5.0f,5.0f) << std::endl;;
    std::cout << Math::Multiply(5.0,5.0) << std::endl;;

    std::cout << Math::Divide(50,5) << std::endl;;
    std::cout << Math::Divide(50.0f,5.0f) << std::endl;;
    std::cout << Math::Divide(50.0,5.0) << std::endl;;



    return 0;
}
