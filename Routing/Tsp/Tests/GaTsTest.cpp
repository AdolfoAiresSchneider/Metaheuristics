//
// Created by adolfoschneider on 16/02/2020.
//


#include <iostream>
#include "../Tsp.h"
#include "../Solution/Solution.h"
#include "../GaTs/GaTs.h"

using namespace std;

/*
int main(){
    set_rand_env();
    freopen("/home/adolfoschneider/Dropbox/IC20192020/IC_ADOLFO/Codigos/Metaheuristics/Routing/Tsp/Database/att48", "r", stdin);

    Tsp tsp = Tsp::read(cin);

    cout << "@@ OPT @@: "<<endl;
    Solution(tsp.opt_tour, tsp).print_sol(cout);

    int population = 100;
    int iterations = 10000;
    int crossover = 20;
    int mutation = 30;
    int tabu_list_size = 10;
    int tabu_iterations = 40;
    int tabu_size_neighborhood = 10;

    GaTs gats(population, iterations, crossover, mutation,
              tabu_list_size, tabu_iterations, tabu_size_neighborhood, tsp);

    Solution x = gats.run();
    x.print_sol(cout);
}*/
