//
// Created by adolfoschneider on 16/02/2020.
//

#include <algorithm>
#include "Solution.h"
#include <set>


Solution::Solution(vector<int> & tour, Tsp & tsp, double fitness )
        : tour(tour),
          tsp(tsp),
          fitness(fitness){
    if(fitness < 0){
        calc_fitness();
    }
}

Solution::Solution(Tsp & tsp) : tsp(tsp){
    for(int i = 0; i < tsp.n; i++){
        tour.push_back(i);
    }
    random_shuffle (tour.begin(), tour.end());
    calc_fitness();
}

Solution Solution::crossover(Solution & other){
    vector<int> child = tour;
    int a = (rand() % tsp.n);
    int b = (rand() % tsp.n);
    if(b < a) swap(a, b);
    set<int> vis;
    for(int i = a; i <= b; i++){
        vis.insert(child[i]);
    }
    int j = 0;
    for(int i = 0; i < tsp.n; i++){
        if(j == a) j = b + 1;
        if(vis.count(other.tour[i])) continue;
        child[j++] = other.tour[i];
    }
    return Solution(child, tsp);
}

void Solution::calc_fitness(){
    fitness = tsp.points[0].dist(tsp.points[tsp.n-1]);
    Point x, y;
    for(int i = 0; i < tsp.n; i++){
        x = tsp.points[tour[i]];
        y = (i ? tsp.points[tour[i-1]] : tsp.points[tour[tsp.n-1]]);
        fitness +=  x.dist(y);
    }
}

bool Solution::isValid(){
    set<int> citys;
    for(int x : tour){
        citys.insert(x);
    }
    /* Checks if there is no vertice
    that apears twice in the tour */
    return citys.size() == tour.size();
}

pair<Solution, Move> Solution::neighbor(){
    vector<int> tmp = tour;
    int n = int(tmp.size());
    int a = (rand() % n);
    int b = (rand() % n);
    if(b < a) swap(a, b);
    if(a == b) b = (b+1)%n;
    double new_fit = fitness;
    new_fit -= tsp.graph[tour[a]][tour[(a-1 + n)%n]];
    new_fit -= tsp.graph[tour[b]][tour[(b+1)%n]];
    reverse(tmp.begin()+a, tmp.begin()+b+1);
    new_fit += tsp.graph[tmp[a]][tmp[(a-1 + n)%n]];
    new_fit += tsp.graph[tmp[b]][tmp[(b+1)%n]];
    return pair<Solution, Move>(Solution(tmp, tsp, new_fit), Move(a, b));
}

bool  Solution::operator < (Solution const & other) const{
    return fitness < other.fitness;
}

Solution & Solution::operator = (const Solution& other){
    tour = other.tour;
    fitness = other.fitness;
    return *this;
}

void Solution::print_sol(ostream & out){
    out<<"  Cost : "<<fitness<<endl;
    out<<"  Tour : ";
    for(int city : tour){
        out<<city<<' ';
    }
    out<<endl;
}