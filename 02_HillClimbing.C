#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define your objective function here
int objective_function(int *solution, int size) {
    int value = 0;
    for (int i = 0; i < size; i++) {
        value += solution[i];
    }
    return value;
}

// Generate a neighboring solution by making a small change to the current solution
void generate_neighbor(int *current_solution, int size) {
    int index = rand() % size;
    current_solution[index] = 1 - current_solution[index]; // Flip the value at the selected index
}

// Hill Climbing algorithm
void hill_climbing(int *initial_solution, int size) {
    int *current_solution = malloc(size * sizeof(int));
    int *best_solution = malloc(size * sizeof(int));

    // Initialize current and best solutions
    for (int i = 0; i < size; i++) {
        current_solution[i] = initial_solution[i];
        best_solution[i] = initial_solution[i];
    }

    int current_fitness = objective_function(current_solution, size);
    int best_fitness = current_fitness;

    // Iterative process
    while (true) {
        // Generate a neighboring solution
        generate_neighbor(current_solution, size);

        // Evaluate the neighbor
        int neighbor_fitness = objective_function(current_solution, size);

        // Comparison
        if (neighbor_fitness >= current_fitness) {
            // Move to the neighbor
            current_fitness = neighbor_fitness;
        } else {
            // Terminate if no better neighbor is found
            break;
        }
    }

    // Print the best solution and fitness
    printf("Best Solution: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", best_solution[i]);
    }
    printf("\nBest Fitness: %d\n", best_fitness);

    // Free allocated memory
    free(current_solution);
    free(best_solution);
}

int main() {
    // Define the initial solution
    int initial_solution[] = {0, 1, 0, 1, 1}; // Example initial solution
    int size = sizeof(initial_solution) / sizeof(initial_solution[0]);

    // Perform Hill Climbing search
    hill_climbing(initial_solution, size);

    return 0;
}
