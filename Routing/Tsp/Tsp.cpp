//
// Created by adolfoschneider on 16/02/2020.
//

#include <iostream>
#include "Tsp.h"

Tsp::Tsp(int n, vector<Point> &pts, vector<int> opt_tour):
    n(n), points(pts), graph(n, vector<double>(n)), opt_tour(opt_tour) {
    // Build the adjacency matrix
    Point x, y;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            x = points[i], y = points[j];
            graph[i][j] = graph[j][i] = x.dist(y);
        }
    }
}

Tsp Tsp::read(istream & in) {
    int n, id;
    double x, y;
    vector<Point> points;
    in>>n;
    // Read the points
    for(int i = 0; i < n; i++){
        in>>id>>x>>y;
        points.emplace_back(x, y);
    }

    int aux;
    vector<int> opt_tour;
    for(int i = 0; i < n; i++){
        // If there is no opt, opt_tour will be empty
        if(in>>aux){
            opt_tour.push_back(aux-1);
        }
    }
    return Tsp(n, points, opt_tour);
}
