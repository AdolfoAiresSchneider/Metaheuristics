//
// Created by adolfoschneider on 16/02/2020.
//

#include <algorithm>
#include "Ga.h"

Ga::Ga(int size_population, int iterations, int n_crossovers, int n_mutations, Tsp & tsp) :
        size_population(size_population),
        iterations(iterations),
        n_crossovers(n_crossovers),
        n_mutations(n_mutations),
        tsp(tsp){
    if(n_crossovers + n_mutations > size_population){
        throw "The sum of crossovers and mutationsmust be less or equal then size_population.";
    }
    for(int i = 0; i < size_population; i++){
        population.push_back(Solution(tsp));
    }
}

Solution Ga::crossover(Solution & x, Solution & y){
    return x.crossover(y);
}

Solution Ga::mutation(Solution & x){
    return x.neighbor().first;
}

void Ga::perform_crossovers(){
    for(int i = 0; i < n_crossovers; i++){
        int x = int(rand())%size_population;
        int y = int(rand())%size_population;
        if(y < x) swap(x, y);
        if(x == y) y = (y+1)%size_population;
        Solution child = crossover(population[x], population[y]);
        new_gen.push_back(child);
    }
}

void Ga::perform_mutations(){
    for(int i = 0; i < n_mutations; i++){
        int x = int(rand())%size_population;
        new_gen.push_back(mutation(population[x]));
    }
}

void Ga::perform_eletism(){
    for(int i = 0; (int)new_gen.size() < size_population ; i++){
        new_gen.push_back(population[i]);
    }
    population = new_gen;
    sort(population.begin(), population.end());
    new_gen.clear();
}

Solution Ga::run(){
    Solution best_sol(tsp);
    while(iterations--){
        perform_crossovers();
        perform_mutations();
        perform_eletism();
        best_sol = min(best_sol, population[0]);
    }
    return best_sol;
}