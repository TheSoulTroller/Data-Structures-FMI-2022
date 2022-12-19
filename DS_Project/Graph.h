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

    std::string strToName(const std::string& line) {
        if(line[line.length()-1] == '{') return line.substr(0, line.length()-2);
        return line.substr(firstLetter(line), line.find(',') - firstLetter(line));
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
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].name == line) return nodes[i];
        }
        return nodes[0];
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
    }

    void printGraph() {
        for(int i = 0; i < nodes.size(); i++) {
            cout << "Current city: " << nodes[i].name << " -> ";
            for(int j = 0; j < nodes[i].neighbors.size(); j++) {
                cout << nodes[i].neighbors[j]->name << " " << nodes[i].length[j] << " -> ";
            }
            cout << "nullptr" << endl;
        }    
    }
};