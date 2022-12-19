#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include "utility.h"

// found this function here
// https://stackoverflow.com/questions/5690663/c-fractions-class
void SimplifyFraction (int &numerator, int &denominator)
{
    for (int i = numerator; i > 1; i--)
    {
        if (numerator % i == 0 && denominator % i == 0)
        {
            numerator = numerator / i;
            denominator = denominator / i;
        }
    }
}

void FractionDivision (int &num, int &denom, int &fraction_int, int servings_num)
{
    num+=fraction_int*denom;
    denom*=servings_num;
    fraction_int =0;
}
void FractionMult (int &num, int &denom, int &fraction_int, int servings_num)
{
    num=(num+(fraction_int*denom))*servings_num;
    fraction_int =0;
}

void MakeFractionString (std::string &fraction, int num,
        int denom, int fraction_int)
{
    if (num>denom)
        {
            fraction_int+=num/denom;
            num=num%denom;
            if (num==denom)
            {
                fraction=std::to_string(fraction_int+1);
            }
            else {
                fraction = std::to_string(fraction_int)+"-"+
            std::to_string(num)+ "/"+std::to_string(denom);
            }
        }
    else if (fraction_int)
    {
        if (num==denom)
        {
            fraction=std::to_string(fraction_int+1);
        }
        else {
            fraction = std::to_string(fraction_int)+"-"+
        std::to_string(num)+ "/"+std::to_string(denom);
        }
    }
    else{
        fraction =std::to_string(num)+ "/"+std::to_string(denom);
    }
}

std::string GetElementFromStream (std::string const &str)
{
    std::istringstream iss(str);
    std::string value;
    iss>>value;
    return value;
}
//took the series of trim funcs from here
// https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \n\r\t\f\v");
    return (start == std::string::npos) ? "" : s.substr(start);
}
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(" \n\r\t\f\v");
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}
void CheckFraction (std::string &fraction, int num_serves, std::string operation="none")
{
    
    int fraction_int =0;
    if (fraction.find("/")!=std::string::npos)
    {
        if (fraction.find("-")!=std::string::npos)
        {
            fraction_int = std::stoi (fraction.substr(0,fraction.find("-")));
            fraction = fraction.substr(fraction.find("-")+1);
        }
        int num = std::stoi (fraction.substr(0,fraction.find("/")));
        int denom = std::stoi (fraction.substr(fraction.find("/")+1));
        if (operation =="division")
        {
            FractionDivision(num,denom,fraction_int, num_serves);
        }
        else if (operation=="multiplication")
        {
            FractionMult(num,denom,fraction_int, num_serves);
        }
        SimplifyFraction(num, denom);
        MakeFractionString(fraction, num, denom, fraction_int);
    }
}
