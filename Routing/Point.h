//
// Created by adolfoschneider on 16/02/2020.
//

#ifndef METAHEURISTICS_POINT_H
#define METAHEURISTICS_POINT_H

#include <cmath>

struct Point {
    double x;
    double y;

    // Constructor: Builds a point given its x, y coordinates
    Point(double _x = 0, double _y = 0) : x(_x),y(_y){}

    // Euclid's distance
    double dist(const Point & point) const {
        return hypot(x - point.x, y - point.y);
    }
};

#endif //METAHEURISTICS_POINT_H
