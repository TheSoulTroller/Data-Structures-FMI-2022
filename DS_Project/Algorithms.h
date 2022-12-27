#pragma once
#include <chrono>
#include "Graph.h"
#include "iostream"

using namespace std::chrono;
class Algorithms {
public:
    static void antAlgorithm(Graph& graph) {
        std::cout << "Ant Algorithm performing..." << std::endl;  
        std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
        graph.antColonyOptimization();
        std::chrono::high_resolution_clock::time_point end = high_resolution_clock::now();
        const long long duration = duration_cast<milliseconds>(end - start).count();
        std::cout << "Ant Algorithm finished in " << duration << " milliseconds" << std::endl;
    }

    static void aStarAlgorithm(Graph& graph) {
        std::cout << "A* Algorithm performing..." << std::endl;
        std::chrono::high_resolution_clock::time_point start = high_resolution_clock::now();
        graph.aStar();
        std::chrono::high_resolution_clock::time_point end = high_resolution_clock::now();
        const long long duration = duration_cast<milliseconds>(end - start).count();
        std::cout << "A* Algorithm finished in " << duration << " milliseconds" << std::endl;
    }

};