#pragma once
#include <chrono>
#include "Graph.h"
#include "iostream"

using namespace std::chrono;
class Algorithms {
public:
    static void nearestNeighbour(Graph& graph) {
        cout << "Nearest Neighbour Algorithm performing..." << endl;  
        std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
        graph.nearestNeighbour();
        std::chrono::high_resolution_clock::time_point end = high_resolution_clock::now();
        const long long duration = duration_cast<milliseconds>(end - start).count();
        cout << "Nearest Neighbour Algorithm finished in " << duration << " milliseconds" << endl;
    }

    static void farthestInsertion(Graph& graph) {
        cout << "Farthest Insertion Algorithm performing..." << endl;
        std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
        graph.farthestInsertion();
        std::chrono::high_resolution_clock::time_point end = high_resolution_clock::now();
        const long long duration = duration_cast<milliseconds>(end - start).count();
        cout << "Farthest Insertion Algorithm finished in " << duration << " milliseconds" << endl;
    }

};