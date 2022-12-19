# Recipe-App
A header-only library that defines a class that can hold recipes and a class that represents a simple recipe app.

Here is an example of using the Recipe class:


  Recipe r("Microwave Popcorn", 3);
  
  r.AddIngredient("1/2 cup unpopped popcorn");
  
  r.AddIngredient("1 teaspoon vegetable oil");
  
  r.AddIngredient("1/2 teaspoon salt");
  
  r.SetInstructions(
  
      R"***(In a cup or small bowl, mix together the unpopped popcorn and oil. 
      
  Pour the coated corn into a brown paper lunch sack, and sprinkle in the salt. 
  
    Fold the top of the bag over twice to seal in the ingredients. 
    

  Cook in the microwave at full power for 2 1/2 to 3 minutes, 
  
   or until you hear pauses of about 2 seconds between pops. 

  Carefully open the bag to avoid steam, and pour into a serving bowl. 
  
  From: https://www.allrecipes.com/recipe/87305/microwave-popcorn/
  
  )***");
  
Output:

Serves 3
Ingredients:
1/2 cup unpopped popcorn
1 teaspoon vegetable oil
1/2 teaspoon salt

Instructions:
In a cup or small bowl, mix together the unpopped popcorn and oil.
Pour the coated corn into a brown paper lunch sack, and sprinkle in the salt.
Fold the top of the bag over twice to seal in the ingredients.
Cook in the microwave at full power for 2 1/2 to 3 minutes,
or until you hear pauses of about 2 seconds between pops.
Carefully open the bag to avoid steam, and pour into a serving bowl.
From: https://www.allrecipes.com/recipe/87305/microwave-popcorn/

)***";
