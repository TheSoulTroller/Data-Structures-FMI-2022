#pragma once
#include "Graph.h"
#include "Algorithms.h"
#include <iostream>
#include <string>

class Interpretator {
    Graph graph;
public:
    static bool interpretate(const std::string& command,const Graph& graph) {
        if(command == "exit") return false;
        if(command.substr(0, 4) == "load")
        {
            // graph = Graph(command.substr(5, command.length() - 5));
        }
        if (command == "print") {
            // graph.print();
            return true;
        }
        if (command == "Ant Algorithm") {
            // Node* begin = graph.chooseBegining();
            // Algorithms::antAlgorithm(graph,begin);
            return true;
        }
        return true;
    }
private:

};
