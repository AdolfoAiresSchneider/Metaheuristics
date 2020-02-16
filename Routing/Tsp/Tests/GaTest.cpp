//
// Created by adolfoschneider on 16/02/2020.
//

#include <iostream>
#include "../Tsp.h"
#include "../Solution/Solution.h"
#include "../Ga/Ga.h"

using namespace std;

void set_rand_env() {
    srand(unsigned(time(0)));
}

int main(){
    set_rand_env();
    freopen("/home/adolfoschneider/Dropbox/IC20192020/IC_ADOLFO/Codigos/Metaheuristics/Routing/Tsp/Database/att48", "r", stdin);
    Tsp tsp = Tsp::read(cin);

    cout << "@@ OPT @@: "<<endl;
    Solution(tsp.opt_tour, tsp).print_sol(cout);

    int population = 100;
    int iterations = 10000;
    int crossover = 30;
    int mutation = 40;

    Ga ga(population, iterations, crossover, mutation, tsp);
    Solution x = ga.run();
    x.print_sol(cout);
}