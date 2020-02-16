//
// Created by adolfoschneider on 16/02/2020.
//

#ifndef METAHEURISTICS_GA_H
#define METAHEURISTICS_GA_H


#include "../Tsp.h"
#include "../Solution/Solution.h"

using namespace std;

class Ga{
    private :
        int size_population;
        int iterations; // Number of iterations
        int n_crossovers; // Number of crossovers
        int n_mutations; // Number of mutations
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

        // Select the best individuos from the past population
        // to fulfill the new generation
        void perform_eletism();

    public:

        // Constructor
        Ga(int size_population, int iterations, int n_crossovers, int n_mutations, Tsp & tsp);

        // Execute the Genetic algorithm and return the best solution found
        Solution run();
};



#endif //METAHEURISTICS_GA_H
