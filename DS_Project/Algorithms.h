#pragma once
#include <chrono>
#include "Graph.h"
#include "Timer.h"
#include "MemoryTracker.h"
class Algorithms {
public:
    static void nearestNeighbour(Graph& graph) {
        cout << "Nearest Neighbour Algorithm performing..." << endl;  
        Timer();
        MemoryTracker* ptr = new MemoryTracker();
        graph.nearestNeighbour();
        delete ptr;
        Timer().stop("Nearest Neighbour Algorithm");
    }

    static void farthestInsertion(Graph& graph) {
        cout << "Farthest Insertion Algorithm performing..." << endl;
        Timer();
        MemoryTracker* ptr = new MemoryTracker();
        graph.farthestInsertion();
        delete ptr;
        Timer().stop("Farthest Insertion Algorithm");
    }

};