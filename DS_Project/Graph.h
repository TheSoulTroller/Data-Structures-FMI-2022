#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
struct Node {
    std::string name;
    std::vector<Node*> neighbors;
    std::vector<int> length;

    // Node() : name(""), neighbors(), length() {}
    Node(const std::string& name) : name(name), neighbors(), length() {}

};

class Graph {
private:
    Node* start;
    std::vector<Node> nodes;

    std::vector<std::string> generateAllEdges(std::string& line) {
        std::vector<std::string> edges;
        std::string edge;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                edges.push_back(edge);
                edge = "";
                i++; //to skip the space after the comma
            }
            else {
                edge += line[i];
            }
        }
        edges.push_back(edge);

        return edges;
    }

    bool isBeginingOfList(const std::string& line) {
        return line[line.length()-1] == '{';
    }

    int strToLength(const std::string& line) {
        return stoi(line.substr(line.find(',')+1, line.length()));
    }

    int firstLetter(const std::string& line) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != ' ') return i;
        }
        return 0;
    }

    int lastDistance(const std::string& city1, const std::string& city2) {
        // cout << "City1: " << city1 << " , " << "City2: " << city2 << endl;
        for(int i = 0; i < nodes.size(); i++) {
            if(nodes[i].name == city1)
            {
               for(int j = 0; j < nodes[i].neighbors.size(); j++) {
                    if(nodes[i].neighbors[j]->name == city2)
                    {
                        return nodes[i].length[j];
                    }
               }
            }
        }
        return (-1 * INT32_MAX);
    }

    std::string strToName(const std::string& line) {
        if(line[line.length()-1] == '{') return line.substr(0, line.length()-2);
        return line.substr(firstLetter(line), line.find(',') - firstLetter(line));
    }

    void validateDistance(int& distance) {
        cin >> distance;
        while (distance < 0) { 
            cout << "Distance can NOT be negative! Enter a distance: ";
            cin >> distance;
        }
    }

    void getAllNeighbors(Node& mainNode, std::ifstream& readFile) {
        std::string line;
        while (getline(readFile, line)) {
            if(line == "}") return;
            Node* neighbor = &findNode(strToName(line));
            mainNode.neighbors.push_back(neighbor);
            mainNode.length.push_back(strToLength(line));
        }
    }

    Node& findNode(const std::string& line) {
        // cout << "findNode line = " << line << endl;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].name == line)
            {
                // cout << "Found: " << nodes[i].name << endl;
                return nodes[i];
            } 
        }
        cout << line << " Not Found!!!" << endl;
        return nodes[0];
    }

    bool isVisited(const std::string& city, const std::vector<std::string>& list) {
        for(int i = 0; i < list.size(); i++)
        {
            if(list[i] == city) return true;
        }
        return false;
    }

    void findClosestNeighbour(Node*& current, const std::vector<std::string>& visited, int& pathLength) {
        int minLength = INT32_MAX;
        Node* newCity = nullptr;
        assert(current->length.size() != current->neighbors.size());
        for(int i = 0; i < current->length.size(); i++)
        {
            // cout << current->neighbors[i]->name << " " << current->length[i] << endl;
            if(!isVisited(current->neighbors[i]->name, visited) && minLength > current->length[i])
            {
                minLength = current->length[i];
                newCity = &findNode(current->neighbors[i]->name);
            }
        }
        assert(newCity != nullptr);
        pathLength += minLength;
        current = newCity;
    }

public:
    Graph(const std::string& filename){
        std::ifstream readFile(filename, std::ios::in);
        std::string line;

        // the first line has all the cities
        getline(readFile, line);
        std::vector<std::string> cities = generateAllEdges(line);

        // assigning all the cities to the nodes
        for (int i = 0; i < cities.size(); i++) {
            Node node(cities[i]);
            nodes.push_back(node);
        }

        // the rest of the file has the connections between the cities an their length
        while(readFile) {
            getline(readFile, line);
            if(isBeginingOfList(line))
            {
                // find the current city
                Node& currentNode = findNode(strToName(line));

                // get all the neighbors of the current city
                getAllNeighbors(currentNode, readFile);
                
            }
        }

        // by default the first city will be the starting city
        this->start = &nodes[0];

        readFile.close();
    }

    void chooseCity(const std::string& cityName) {
        for(int i = 0; i < nodes.size(); i++) {
            if(nodes[i].name == cityName) {
                this->start = &nodes[i];
                return;
            }
        }
        cout << cityName << " was not found in the current graph." << endl;
    }

    void addCity(const std::string& cityName)
    {
        Node newCity(cityName);
        nodes.push_back(newCity);
        for(int i = 0; i < nodes.size() - 1; i++) {
            cout << "Enter distance from " << nodes[i].name << " to " << cityName << endl;
            int distance;
            validateDistance(distance);

            Node* ptrToOldCity = &findNode(nodes[i].name);
            newCity.neighbors.push_back(ptrToOldCity);
            newCity.length.push_back(distance);

            Node* ptrToNewCity = &findNode(cityName);
            newCity.neighbors.push_back(ptrToNewCity);
            newCity.length.push_back(distance);
        }
        
    }

    void printGraph() const {
        for(int i = 0; i < nodes.size(); i++) {
            cout << "Current city: " << nodes[i].name << " -> ";
            for(int j = 0; j < nodes[i].neighbors.size(); j++) {
                cout << nodes[i].neighbors[j]->name << " " << nodes[i].length[j] << " -> ";
            }
            cout << "nullptr" << endl;
        }    
    }

    void findShortestPath() {
        // callculate all possible paths and choose the shortest
        // (n-1)!/2                
    }

    void aStar() {
        // TO DO:

    }

    void antColonyOptimization() {
        std::vector<std::string> path;
        int pathLength = 0;
        path.push_back(start->name);
        while(path.size() != nodes.size())
        {
            findClosestNeighbour(start,path,pathLength);
            path.push_back(start->name);
        }
        path.push_back(path[0]);

        pathLength += lastDistance(path[path.size() - 1], path[path.size() - 2]);

        // print path
        for(int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " -> ";
        }
        cout << "End" << endl << "Distance: " << pathLength << " km.\n";

        // set start to point at the right city
        this->start = &findNode(path[0]);
    }
};