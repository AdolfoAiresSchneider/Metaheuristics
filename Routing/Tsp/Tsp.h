//
// Created by adolfoschneider on 16/02/2020.
//

#ifndef METAHEURISTICS_TSP_H
#define METAHEURISTICS_TSP_H

#include "../Point.h"
#include <vector>
#include <istream>

using namespace std;

class Tsp{

public :

    int n; // Number of vertices
    vector<Point> points; // List of points
    vector<vector<double>>  graph; // Adjacency list of the symmetric graph
    vector<int> opt_tour; // Optimum tour or best so far

    // Constructors : build the tsp instance
    Tsp() : n(-1) {}
    Tsp(int n, vector<Point> & pts, vector<int> opt_tour);

    // Reads and return a tsp instance
    static Tsp read(istream & in);
};

#endif //METAHEURISTICS_TSP_H