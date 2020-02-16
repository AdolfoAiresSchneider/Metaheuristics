//
// Created by adolfoschneider on 16/02/2020.
//

#include <algorithm>
#include "GaTs.h"
#include "../Ts/Ts.h"

GaTs::GaTs(int size_population, int iterations, int n_crossovers, int n_mutations,
           int tabu_list_size, int tabu_iterations, int tabu_size_neighborhood, Tsp & tsp) :
        size_population(size_population),
        iterations(iterations),
        n_crossovers(n_crossovers),
        n_mutations(n_mutations),
        tabu_list_size(tabu_list_size),
        tabu_iterations(tabu_iterations),
        tabu_size_neighborhood(tabu_size_neighborhood),
        tsp(tsp){
    if(n_crossovers + n_mutations > size_population){
        throw "The sum of crossovers and mutation's must be less or equal then size_population.";
    }
    for(int i = 0; i < size_population; i++){
        population.push_back(Solution(tsp));
    }
}

Solution GaTs::crossover(Solution & x, Solution & y){
    return x.crossover(y);
}

Solution GaTs::mutation(Solution & x){
    return x.neighbor().first;
}

void GaTs::perform_crossovers(){
    for(int i = 0; i < n_crossovers; i++){
        int x = int(rand())%size_population;
        int y = int(rand())%size_population;
        if(y < x) swap(x, y);
        if(x == y) y = (y+1)%size_population;
        Solution child = crossover(population[x], population[y]);
        new_gen.push_back(Ts(child, tabu_list_size, tabu_iterations, tabu_size_neighborhood).run());
    }
}

void GaTs::perform_mutations(){
    for(int i = 0; i < n_mutations; i++){
        int x = int(rand())%size_population;
        new_gen.push_back(mutation(population[x]));
    }
}

void GaTs::perform_elitism(){
    for(int i = 0; (int)new_gen.size() < size_population ; i++){
        new_gen.push_back(population[i]);
    }
    population = new_gen;
    sort(population.begin(), population.end());
    new_gen.clear();
}

Solution GaTs::run(){
    Solution best_sol(tsp);
    while(iterations--){
        perform_crossovers();
        perform_mutations();
        perform_elitism();
        best_sol = min(best_sol, population[0]);
    }
    return Ts(best_sol, tabu_list_size, tabu_iterations, tabu_size_neighborhood).run();
}