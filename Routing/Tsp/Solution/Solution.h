//
// Created by adolfoschneider on 16/02/2020.
//

#ifndef METAHEURISTICS_SOLUTION_H
#define METAHEURISTICS_SOLUTION_H

#include <vector>
#include "../Tsp.h"

using namespace std;

typedef pair<int,int> Move;
// Class that model a solution of Tsp and Cvrp
class Solution{

    private:

        vector<int> tour;// Represents the solution
        Tsp & tsp; // Problem instance
        double fitness{}; // Quality of the solution

    public:

        // Constructor: Build a solution based on the passed tour
        Solution(vector<int> & tour, Tsp & tsp, double fitness = -1.0);

        // Constructor: Build a random solution for the tsp instance
        explicit Solution(Tsp & tsp);

        // Calculate the quality if this solution
        void calc_fitness();

        // Checks if this solution is valid
        bool isValid();

        // Returns a possible neighbor solution and the moviment to generate it
        pair<Solution, Move> neighbor();

        Solution crossover(Solution & other);

        // Print the solution
        void print_sol(ostream & out);

        bool operator < (Solution const & other) const;
        Solution & operator = (const Solution& other);
};


#endif //METAHEURISTICS_SOLUTION_H
