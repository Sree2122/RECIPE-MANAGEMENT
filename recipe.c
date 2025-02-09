#ifndef RECIPE_H
#define RECIPE_H

#define MAX_NAME_LENGTH 50
#define MAX_INGREDIENTS 100
#define MAX_INSTRUCTION_LENGTH 200

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char ingredients[MAX_INGREDIENTS][MAX_NAME_LENGTH];
    int num_ingredients;
    char instructions[MAX_INSTRUCTION_LENGTH];
} Recipe;

#endif