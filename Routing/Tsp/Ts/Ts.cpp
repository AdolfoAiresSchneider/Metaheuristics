//
// Created by adolfoschneider on 16/02/2020.
//

#include <algorithm>
#include "Ts.h"

Ts::Ts(Solution & cur_sol, int size_tList, int iterations, int size_neighborhood):
        cur_sol(cur_sol),
        best_sol(cur_sol),
        size_tList(size_tList),
        iterations(iterations),
        size_neighborhood(size_neighborhood){}

inline bool Ts::isForbidden(pair<Solution, Move> & x){
    // Checks if the Move is in the tabu list or the sol it is better find so far
    return !(tabu_set.count(x.second) == 0 || x.first < best_sol);
}

Solution Ts::run(){
    vector<pair<Solution, Move>> neighbors;
    while(iterations--){

        neighbors.clear();
        for(int i = 0; i < size_neighborhood; i++){
            neighbors.push_back(cur_sol.neighbor());
            // assert(neighbors.back().first.is_valid() == true);
        }

        sort(neighbors.begin(), neighbors.end());
        for(auto x : neighbors){
            if(isForbidden(x) == false){
                Move mov = x.second;
                if(tabu_set.count(mov) == 0){
                    tabu_list.push_back(mov);
                    tabu_set.insert(mov);
                }
                cur_sol = x.first;
                break;

            }
        }

        // Remove the oldest movement from the tabu list
        if((int)tabu_list.size() > size_tList){
            tabu_set.erase(tabu_list.front());
            tabu_list.pop_front();
        }

        if(cur_sol < best_sol)
            best_sol = cur_sol;
    }
    return best_sol;
}