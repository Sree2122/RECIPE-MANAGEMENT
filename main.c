#include <stdio.h>
#include "recipe.h"

int main() {
    int choice;

    // Load data (if implemented)

    do {
        printf("\nRecipe Management System\n");
        printf("1. Add Recipe\n");
        printf("2. List Recipes\n");
        printf("3. Find Recipe\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id, num_ingredients = 0;
                char name[MAX_NAME_LENGTH];
                char ingredients[MAX_INGREDIENTS][MAX_NAME_LENGTH];
                char instructions[MAX_INSTRUCTION_LENGTH];

                printf("Enter recipe ID: ");
                scanf("%d", &id);
                printf("Enter recipe name: ");
                scanf(" %[^\n]s", name);

                printf("Enter ingredients (one per line, end with 'done'):\n");
                char ingredient[MAX_NAME_LENGTH];
                while (fgets(ingredient, MAX_NAME_LENGTH, stdin) != NULL) {
                    // Remove trailing newline if present
                    ingredient[strcspn(ingredient, "\n")] = 0;
                    if (strcmp(ingredient, "done") == 0) break;
                    strcpy(ingredients[num_ingredients++], ingredient);
                }

                printf("Enter instructions:\n");
                // Consume any leftover newline from ingredient input
                getchar(); // Important!
                fgets(instructions, MAX_INSTRUCTION_LENGTH, stdin);
                instructions[strcspn(instructions, "\n")] = 0; // Remove trailing newline

                add_recipe(id, name, ingredients, num_ingredients, instructions);
                break;
            }
            case 2:
                list_recipes();
                break;
            case 3: {
                int id;
                printf("Enter recipe ID to find: ");
                scanf("%d", &id);
                find_recipe(id);
                break;
            }
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 0);

    // Save data (if implemented)
    return 0;
}