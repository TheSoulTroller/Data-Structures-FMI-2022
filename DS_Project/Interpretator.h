#pragma once
#include "Graph.h"
#include "Algorithms.h"
#include <iostream>
#include <string>

class Interpretator {
public:
    static bool interpretate(const std::string& command,Graph& graph) {
        if(command == "exit") return false;
        if(command.substr(0, 4) == "load")
        {
            graph = Graph(command.substr(5, command.length() - 5));
        }
        if (command == "print") {
            graph.printGraph();
            return true;
        }
        if (command == "Ant Algorithm") {

            cout << "Choose a city to start from: ";
            std::string city;
            cin >> city;

            graph.chooseCity(city);

            Algorithms::antAlgorithm(graph);

            return true;
        }
        if(command == "A* Algorithm") {
            cout << "Choose a city to start from: ";
            std::string city;
            cin >> city;

            graph.chooseCity(city);

            Algorithms::aStarAlgorithm(graph);

            return true;
        }
        if(command == "help")
        {
            std::cout << "load <filename> - loads a graph from a file" << std::endl;
            std::cout << "print - prints the graph" << std::endl;
            std::cout << "Ant Algorithm - runs the Ant Algorithm" << std::endl;
            std::cout << "exit - exits the program" << std::endl;
            return true;
        }
        std::cout << "Invalid command! Type 'help' for a list of commands." << std::endl;
        return true;
    }
private:

};
