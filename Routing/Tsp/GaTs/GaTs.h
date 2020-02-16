//
// Created by adolfoschneider on 16/02/2020.
//

#ifndef METAHEURISTICS_GATS_H
#define METAHEURISTICS_GATS_H

#include "../Solution/Solution.h"

class GaTs{
private :
    int size_population;
    int iterations; // Number of iterations
    int n_crossovers; // Number of crossovers
    int n_mutations; // Number of mutations
    int tabu_list_size;
    int tabu_iterations;
    int tabu_size_neighborhood;
    vector<Solution> population;
    vector<Solution> new_gen; // New generation
    Tsp & tsp; // Problem instance

    // Make a crossover of x with y
    Solution crossover(Solution & x, Solution & y);

    // Mutate a solution x
    Solution mutation(Solution & x);

    // Make crossovers in the population
    void perform_crossovers();

    // Make mutations in the population
    void perform_mutations();

    // Select the best solutions from the past population to fulfill the new generation
    void perform_elitism();

public:

    // Constructor
    GaTs(int size_population, int iterations, int n_crossovers, int n_mutations,
         int tabu_list_size, int tabu_iterations, int tabu_size_neighborhood, Tsp & tsp);

    // Execute the Genetic algorithm and return the best solution found
    Solution run();
};


#endif //METAHEURISTICS_GATS_H
