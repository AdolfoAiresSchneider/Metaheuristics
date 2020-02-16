//
// Created by adolfoschneider on 16/02/2020.
//
#include <iostream>
#include "../Tsp.h"
#include "../Solution/Solution.h"
#include "../Ts/Ts.h"

using namespace std;

/*
int main(){
    set_rand_env();
    freopen("/home/adolfoschneider/Dropbox/IC20192020/IC_ADOLFO/Codigos/Metaheuristics/Routing/Tsp/Database/att48", "r", stdin);

    Tsp tsp = Tsp::read(cin);

    int size_tabu_list = 10;
    int iterations = 1000000;
    int size_neighborhood = 50;

    cout << "@@ OPT @@: "<<endl;
    Solution(tsp.opt_tour, tsp, -1).print_sol(cout);

    cout << "@@ Initial @@: "<<endl;
    Solution init(tsp);
    init.print_sol(cout);

    Ts tabu_search = Ts(init, size_tabu_list,
                        iterations, size_neighborhood);

    Solution bfs = tabu_search.run();
    cout << "@@ Best found @@: "<<endl;
    bfs.print_sol(cout);
}*/