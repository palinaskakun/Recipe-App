#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include "utility.h"

class Recipe {
private:
    
    std::vector <std::string> ingredients_;
    std::string instructions_;
    std::string recipe_name_;
    int num_of_servings_;
    friend class RecipeApp;

public:
    Recipe (std::string const & name, int const& servings)
    {
        recipe_name_= name;
        num_of_servings_ = servings;
    }
   friend std::ostream & operator << (std::ostream &out, const Recipe &c);

    void AddIngredient (std::string ingredient)
    {
        ingredient=trim(ingredient);
        ingredient.erase(remove(ingredient.begin(), ingredient.end(), '\t'), ingredient.end());
        std::string value = GetElementFromStream (ingredient);
        CheckFraction(value, num_of_servings_);
        ingredients_.push_back(value+ingredient.substr(ingredient.find(" ")));
    }

    void SetInstructions (std::string instructions)
    {
        std::string return_string, word, line, edited_line="";
        std::istringstream iss(instructions);
        while(std::getline(iss,line))
        {
            if(line.size() == 0)
            {
                continue;
            }
            std::istringstream iss2(line);
            while (iss2>>word)
            {
                edited_line+=word+" ";
            }
            edited_line=edited_line.substr(0,edited_line.length()-1);
            edited_line+="\n";
        }

        instructions_=edited_line;
    }
    
    std::string IngredientInOneServing (std::string single_ingr)
    {
        std::string fraction;
        for (auto ingredient: ingredients_)
        {
            if (ingredient.find(single_ingr)!=std::string::npos)
            {
                fraction = GetElementFromStream (ingredient);
                for (char c: fraction)
                {
                    ingredient.erase(remove(ingredient.begin(), ingredient.end(), c), ingredient.end());
                }
                if (num_of_servings_==1)
                {
                    return fraction+" "+GetElementFromStream(ingredient)+" "+single_ingr;;
                }
                
                
                if (fraction.find("/")==std::string::npos)
                {
                    fraction+="/1";
                }
                CheckFraction(fraction, num_of_servings_, "division");

                return fraction+" "+GetElementFromStream(ingredient)+" "+single_ingr;
            }
        }   
        throw std::invalid_argument("");
    }

    void ChangeServings (int servings)
{
    for (std::string &ingr: ingredients_)
    {
        std::string single_ingr = ingr;
        std::string fraction = GetElementFromStream(single_ingr);
        for (char c: fraction)
        {
            single_ingr.erase(remove(single_ingr.begin(), single_ingr.end(), c), single_ingr.end());
        }
        single_ingr=single_ingr.substr(single_ingr.find(" ")+1);
        single_ingr=single_ingr.substr(single_ingr.find(" ")+1);
        ingr = IngredientInOneServing(single_ingr);
        int tempp = num_of_servings_;
        num_of_servings_=servings;
        fraction = GetElementFromStream(ingr);
        CheckFraction(fraction, num_of_servings_, "multiplication");
        for (char c: GetElementFromStream(ingr))
        {
            ingr.erase(remove(ingr.begin(), ingr.end(), c), ingr.end());
        }
        std::string temp = fraction + ingr;
        ingr =temp;
        num_of_servings_=tempp;
    }
    num_of_servings_=servings;
}
};

std::ostream & operator << (std::ostream &out, const Recipe &c)
{
    out <<"Recipe for: "<<c.recipe_name_<<"\n" <<
        "Serves "<<c.num_of_servings_<<"\n" << "Ingredients:"<<"\n";
    auto my_ingredients =c.ingredients_;
    for (auto ingr: my_ingredients)
    {
        out <<ingr<<"\n";
    }
    out<<"\n"<<"Instructions:"<<"\n"<<c.instructions_<<"\n";
    
    return out;
}
