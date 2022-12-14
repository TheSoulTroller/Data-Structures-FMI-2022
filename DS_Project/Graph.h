#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <functional>
#include <fstream>
#include <cassert>

using namespace std;
struct Node
{
    std::string name;
    std::vector<Node *> neighbors;
    std::vector<int> length;

    // Node() : name(""), neighbors(), length() {}
    Node(const std::string &name) : name(name), neighbors(), length() {}
};

struct NodeHash {
  size_t operator()(const Node& node) const {
    return std::hash<std::string>()(node.name);
  }

  size_t operator()(const Node* node) const {
    return std::hash<std::string>{}(node->name);
  }
};

// Custom equal function for the Node type.
struct NodeEqual {
  bool operator()(const Node& lhs, const Node& rhs) const {
    return lhs.name == rhs.name;
  }
  bool operator()(const Node* lhs, const Node* rhs) const {
    return lhs->name == rhs->name;
  }
};

class Graph
{
private:
    Node *start;
    std::vector<Node> nodes;

    std::vector<std::string> generateAllEdges(std::string &line) {
        std::vector<std::string> edges;
        std::string edge;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ',')
            {
                edges.push_back(edge);
                edge = "";
                i++; // to skip the space after the comma
            }
            else
            {
                edge += line[i];
            }
        }
        edges.push_back(edge);

        return edges;
    }

    std::string strToName(const std::string &line) {
        if (line[line.length() - 1] == '{')
            return line.substr(0, line.length() - 2);
        // cout << firstLetterIndex(line) << " " << line.substr(firstLetterIndex(line), line.find(',') ) << endl;
        return line.substr(firstLetterIndex(line), line.find(',') - 1);
    }

    Node &findNode(const std::string &line) {
        // cout << "findNode line = " << line << endl;
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].name == line)
            {
                // cout << "Found: " << nodes[i].name << endl;
                return nodes[i];
            }
        }
        // cout << line << " Not Found!!!" << endl;
        return nodes[0];
    }

    bool isBeginingOfList(const std::string &line) {
        return line[line.length() - 1] == '{';
    }

    bool isVisited(const std::string &city, const std::vector<std::string> &list) const {
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i] == city)
                return true;
        }
        return false;
    }

    int strToLength(const std::string &line) {
        return stoi(line.substr(line.find(',') + 1, line.length()));
    }

    int firstLetterIndex(const std::string &line) const {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ' ' && line[i] != '\t')
                return i;
        }
        return -1;
    }

    int tourLength(const std::vector<Node*> &tour) const {
        int length = 0;
        assert(tour[0]->neighbors.size() > 0);
        for (int i = 0; i < tour.size() - 1; ++i)
        {
            //cout << "dis: " << tour[i]->name << " " << tour[i+1]->name << " -> " << distanceBetween(*tour[i], *tour[i + 1]) << endl;
            length += distanceBetween(*tour[i], *tour[i + 1]);
        }
        //cout << distanceBetween(*tour.back(), *tour.front()) << endl;
        length += distanceBetween(*tour.back(), *tour.front());
        assert(length > 0);
        return length;
    }

    int distanceBetween(const Node &a, const Node &b) const {
        assert(&a != &b);
        for (int i = 0; i < a.neighbors.size(); ++i)
        {
            //cout << a.neighbors[i]->name << endl;
            if (a.neighbors[i]->name == b.name)
            {
                //cout << a.neighbors.size() << " " << a.name << " " << b.name << endl;
                return a.length[i];
            }
        }
        cout << a.neighbors.size() << " " << a.name << " " << b.name << endl;
        return INT32_MIN;
    }

    int distanceBetween(const std::string &city1, const std::string &city2) const {
        assert(city1 != city2);
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].name == city1)
            {
                for (int j = 0; j < nodes[i].neighbors.size(); j++)
                {
                    if (nodes[i].neighbors[j]->name == city2)
                    {
                        return nodes[i].length[j];
                    }
                }
            }
        }
        // cout << "City1: " << city1 << " , " << "City2: " << city2 << endl;
        return INT32_MIN;
    }

    int evaluatePath(const std::vector<Node*> &path) {
        int pathLength = 0;
        for (int i = 0; i < path.size() - 1; i++)
        {
            pathLength += distanceBetween(*path[i], *path[i + 1]);
        }
        pathLength += distanceBetween(*path[path.size() - 1], *path[0]);
        return pathLength;
    }

    void validateDistance(int &distance) {
        cin >> distance;
        while (distance < 0)
        {
            cout << "Distance can NOT be negative! Enter a distance: ";
            cin >> distance;
        }
    }

    void getAllNeighbors(Node &mainNode, std::ifstream &readFile) {
        std::string line;
        while  (getline(readFile, line))
        {
            if (line == "}")
                return;
            Node *neighbor = &findNode(strToName(line));
            mainNode.neighbors.push_back(neighbor);
            mainNode.length.push_back(strToLength(line));
        }
    }

    void findClosestNeighbour(Node *&current, const std::vector<std::string> &visited, int &pathLength) {
        int minLength = INT32_MAX;
        Node *newCity = nullptr;
        assert(current->length.size() == current->neighbors.size());
        for (int i = 0; i < current->length.size(); i++)
        {
            // cout << current->neighbors[i]->name << " " << current->length[i] << endl;
            if (!isVisited(current->neighbors[i]->name, visited) && minLength > current->length[i])
            {
                minLength = current->length[i];
                newCity = &findNode(current->neighbors[i]->name);
            }
        }
        assert(newCity != nullptr);
        pathLength += minLength;
        current = newCity;
    }

    void print(std::vector<Node> nodes) const {
        cout << "-----------------------\n";
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i].name << " ";
        }
        cout << "\n-----------------------\n";
    }

    void generatePathsUtil(std::vector<Node> nodes, std::vector<Node> path, std::vector<bool> visited, std::vector<std::vector<Node>> &allPaths, int size) {
        // if all the nodes are visited, then add the path to the list of all paths
        if (path.size() == size)
        {
            allPaths.push_back(path);
            return;
        }

        // for each node, if it is not visited, then add it to the path and mark it as visited
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                path.push_back(nodes[i]);
                generatePathsUtil(nodes, path, visited, allPaths, size);
                visited[i] = false;
                path.pop_back();
            }
        }
    }

    void generatePaths(std::vector<Node*> nodes, int size, vector<int>& results) {
        if (size == 1)
        {
            results.push_back(evaluatePath(nodes));
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                generatePaths(nodes, size - 1, results);
                int swapIndex = (size % 2 == 0) ? i : 0;
                std::swap(nodes[swapIndex], nodes[size - 1]);
            }
        }
    }

public:
    Graph(const std::string &filename) {
        // cheking filename validity
        assert(filename.size() > 0);
        assert(filename.find(".txt") != std::string::npos);

        std::ifstream readFile(filename);
        if(!readFile.is_open())
        {
            cout << "File not found!\n";
            return;
        }
        if(readFile.peek() == std::ifstream::traits_type::eof())
        {
            cout << "File is empty!\n";
            return;
        }
        if(!readFile.good())
        {
            cout << "File is corrupted!\n";
            return;
        }
        std::string line;

        // the first line has all the cities
        getline(readFile, line);
        std::vector<std::string> cities = generateAllEdges(line);

        // assigning all the cities to the nodes
        for (int i = 0; i < cities.size(); i++)
        {
            Node node(cities[i]);
            nodes.push_back(node);
        }

        for(Node& node: nodes)
        {
            cout << node.name << "|";
        }
        cout << endl;

        // the rest of the file has the connections between the cities an their length
        while (readFile)
        {
            getline(readFile, line);
            if (isBeginingOfList(line))
            {
                // find the current city
                Node &currentNode = findNode(strToName(line));
                // cout << "Current city for getAllNeighbors: " << currentNode.name << "\n";

                // get all the neighbors of the current city
                getAllNeighbors(currentNode, readFile);
            }
        }

        // by default the first city will be the starting city
        this->start = &nodes[0];

        readFile.close();

        //assert(nodes.size() >= 3);
    }

    void chooseCity(const std::string &cityName) {
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].name == cityName)
            {
                this->start = &nodes[i];
                return;
            }
        }
        cout << cityName << " was not found in the current graph." << endl;
    }

    void addCity(const std::string &cityName) {
        Node newCity(cityName);
        nodes.push_back(newCity);
        for (int i = 0; i < nodes.size() - 1; i++)
        {
            cout << "Enter distance from " << nodes[i].name << " to " << cityName << endl;
            int distance;
            validateDistance(distance);

            Node *ptrToOldCity = &findNode(nodes[i].name);
            newCity.neighbors.push_back(ptrToOldCity);
            newCity.length.push_back(distance);

            Node *ptrToNewCity = &findNode(cityName);
            newCity.neighbors.push_back(ptrToNewCity);
            newCity.length.push_back(distance);
        }
    }

    void printGraph() const {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << "Current city: " << nodes[i].name << " -> ";
            for (int j = 0; j < nodes[i].neighbors.size(); j++)
            {
                cout << nodes[i].neighbors[j]->name << " " << nodes[i].length[j] << " -> ";
            }
            cout << "nullptr" << endl;
        }
    }

    void findShortestPath() {
        vector<Node*> path;
        path.resize(nodes.size());
        for (int i = 0; i < nodes.size(); ++i) {
            path[i] = &nodes[i];
        }
        std::swap(path[0], path[path.size() - 1]);
        vector<int> results;
        generatePaths(path, path.size() - 1, results);
        cout << *min_element(results.begin(), results.end()) << endl;
    }

    void farthestInsertion() {
        cout << start->name << endl;
        std::vector<Node*> tour {start};
        std::unordered_set<Node*, NodeHash, NodeEqual> unvisitedNodes;
        for (Node& node : nodes) {
          unvisitedNodes.insert(&node);
        }
        unvisitedNodes.erase(start);

        while (!unvisitedNodes.empty())
        {
            Node* farthestNode = nullptr;
            int farthestDistance = 0;
            for (Node* node : unvisitedNodes)
            {
                int distance = INT32_MAX;
                for (Node* tour_node : tour)
                {
                    distance = std::min(distance, distanceBetween(*node, *tour_node));
                }
                if (distance > farthestDistance)
                {
                    farthestNode = node;
                    farthestDistance = distance;
                }
            }

            int closestDistance = INT32_MAX;
            int insertIndex = 0;
            for (int i = 1; i < tour.size(); ++i)
            {
                int distance = distanceBetween(*tour[i - 1], *farthestNode) +
                               distanceBetween(*farthestNode, *tour[i]) -
                               distanceBetween(*tour[i - 1], *tour[i]);
                
                if (distance < closestDistance)
                {
                    closestDistance = distance;
                    insertIndex = i;
                }
            }

            tour.insert(tour.begin() + insertIndex, farthestNode);
            unvisitedNodes.erase(farthestNode);
        }
        
        for (Node* n : tour) {
            cout << n->name << " -> ";
        }
        cout << "End" << endl
             << "Distance: " << tourLength(tour) << " km.\n";
    }

    void nearestNeighbour() {
        std::vector<std::string> path;
        int pathLength = 0;
        path.push_back(start->name);
        while (path.size() != nodes.size())
        {
            findClosestNeighbour(start, path, pathLength);
            path.push_back(start->name);
        }
        path.push_back(path[0]);

        pathLength += distanceBetween(path[path.size() - 1], path[path.size() - 2]);

        // print path
        for(string city : path)
        {
            cout << city << " -> ";
        }
        cout << "End" << endl
             << "Distance: " << pathLength << " km.\n";

        // set start to point at the right city
        this->start = &findNode(path[0]);
    }

    void saveToFile(const string& fileName) const {
        // check if the string has the .txt extension
        string file = fileName;
        if (fileName.find(".txt") == string::npos)
        {
            file += ".txt";
        }
        ofstream write(file);
        if (!write)
        {
            cout << "Error opening file " << file << endl;
            return;
        }
        for(int i = 0; i < nodes.size() - 1; i++)
        {
            write << nodes[i].name << ", ";
        }
        write << nodes[nodes.size() - 1].name << "\n";
        for (Node node : nodes)
        {
            write << node.name << " {\n";
            for (int i = 0; i < node.neighbors.size(); i++)
            {
                write << "\t" << node.neighbors[i]->name << "," << node.length[i] << "\n";
            }
            write << "}\n";
        }

        write.close();
    }
};