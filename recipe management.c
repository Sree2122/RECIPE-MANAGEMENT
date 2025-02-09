#include "recipe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECIPES 100

Recipe recipes[MAX_RECIPES];
int num_recipes = 0;

void add_recipe(int id, const char *name, const char ingredients[][MAX_NAME_LENGTH], int num_ingredients, const char *instructions);
void list_recipes();
Recipe* find_recipe(int id); // Helper function
// ... other recipe management functions (save, load)