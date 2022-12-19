#pragma once
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include "recipe.h"
#include "utility.h"

class RecipeApp {

private:
    std::vector <Recipe> recipe_book_;
    std::vector <std::string> pantry_;
    
public:
    
    // Getter
    std::vector <Recipe> GetRecipeBook() {
      return recipe_book_;
    }
    // Getter
    std::vector <std::string> GetPantry() {
      return pantry_;
    }

    RecipeApp(){};
    void AddRecipe (const Recipe &c)
    {
        recipe_book_.push_back(c);
        std::sort(recipe_book_.begin(), recipe_book_.end(),
        [](Recipe &x, Recipe &y)
        {
            return x.recipe_name_ < y.recipe_name_;
        });
    }
    void AddIngredientToPantry(std::string ingredient)
    {
        pantry_.push_back(ingredient);
        std::sort(pantry_.begin(), pantry_.end(),
        [](auto x, auto y)
        {
            std::istringstream iss(x);
            std::istringstream iss2(y);
            std::string temp, word1, word2;
            for (int i=0; i<3; ++i)
            {
                iss>>word1;
                iss2>>word2;
            }
            return word1 < word2;
    });
    }
    friend std::ostream & operator << (std::ostream &out, RecipeApp &c);
};

std::ostream & operator << (std::ostream &out, RecipeApp &c)
{
    out << "Recipes in the app (ordered by name):" <<"\n";
    for (auto rec: c.GetRecipeBook())
    {
        out <<rec;
    }
    out << "Ingredients in pantry (ordered by name):"<<"\n";
    for (auto ingr: c.GetPantry())
    {
        out <<ingr<<"\n";
    }
    return out;
}

