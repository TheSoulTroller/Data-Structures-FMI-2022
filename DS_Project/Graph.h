#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Node {
    std::string name;
    std::vector<Node*> neighbors;
    std::vector<int> length;
};

class Graph {
private:
    std::vector<Node*> nodes;
public:
    Graph(std::string filename){
        std::ifstream f(filename);
        std::string line;
        while (std::getline(f, line)) {
            if(line[line.length()-1] == ':'){
                Node* node = new Node;
                node->name = line.substr(0, line.length()-1);
                std::cout << node->name << std::endl;
                while(std::getline(f, line) && line[line.length()-1] != ':'){
                    Node* neighbor = new Node;
                    neighbor->name = line.substr(0, line.find(','));
                    node->neighbors.push_back(neighbor);
                    node->length.push_back(std::stoi(line));
                    neighbor->neighbors.push_back(node);
                    neighbor->length.push_back(std::stoi(line));
                }
            }
        }
    }
};