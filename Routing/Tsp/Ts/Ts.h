//
// Created by adolfoschneider on 16/02/2020.
//

#ifndef METAHEURISTICS_TS_H
#define METAHEURISTICS_TS_H

#include "../Solution/Solution.h"
#include <set>
#include <deque>
using namespace std;

class Ts{

    private:

        Solution cur_sol; // Current Solution
        Solution best_sol; // Best solution found
        int size_tList; // Size of the tabu list
        int iterations; // Number of iterations
        int size_neighborhood; //
        deque<Move> tabu_list; //
        set<Move> tabu_set; // Tree structure to fast check the in the tabu list

        // Checks if a movement is forbidden by the tabu list
        bool isForbidden(pair<Solution, Move> & x);

    public :

        // Constructor :
        Ts(Solution & cur_sol, int size_tList, int iterations, int size_neighborhood);

        // Run the tabu search and return the best found solution
        Solution run();
};


#endif //METAHEURISTICS_TS_H
