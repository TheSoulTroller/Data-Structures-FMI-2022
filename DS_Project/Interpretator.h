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
            graph = Graph(command.substr(5, command.length()));
            return true;
        }
        if(command == "print") {
            graph.printGraph();
            return true;
        }
        if(command.substr(0,4) == "save") {
            graph.saveToFile(command.substr(5, command.length()));
            return true;
        }
        if (command == "nn" || command == "Nearest Neighbor" || command == "nearest neighbour") {

            cout << "Choose a city to start from: ";
            std::string city;
            cin >> city;

            graph.chooseCity(city);

            Algorithms::nearestNeighbour(graph);

            return true;
        }
        if(command == "Farthest Insertion" || command == "farthest insertion" || command == "fi") {
            cout << "Choose a city to start from: ";
            std::string city;
            cin >> city;

            graph.chooseCity(city);

            Algorithms::farthestInsertion(graph);

            return true;
        }
        if(command == "help")
        {
            cout << "load <filename> - loads a graph from a file" << endl;
            cout << "print - prints the graph" << endl;
            cout << "Nearest Neighbour Algorithm" << endl;
            cout << "Farthest Insertion Algorithm" << endl;
            cout << "exit - exits the program" << endl;
            return true;
        }
        cout << "Invalid command! Type 'help' for a list of commands." << endl;
        return true;
    }
private:

};
