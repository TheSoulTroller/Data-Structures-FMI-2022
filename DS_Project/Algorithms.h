#pragma once
#include "Graph.h"
#include "iostream"

class Algorithms {
public:
// define functions for finding shortest path going through all nodes back to start without repeating nodes
    static void TSP(Graph graph, int start, int end){

    }

    static void Dijkstra(Graph graph,Node* start){
        // initialize all nodes to infinity
        for (int i = 0; i < graph.nodes.size(); i++){
            graph.nodes[i].distance = INT_MAX;
        }
        // set start node to 0
        graph.nodes[start].distance = 0;
        // create a queue of nodes
        std::vector<Node> queue;
        // add all nodes to queue
        for (int i = 0; i < graph.nodes.size(); i++){
            queue.push_back(graph.nodes[i]);
        }
        // while queue is not empty
        while (!queue.empty()){
            // find node with smallest distance
            int smallest = 0;
            for (int i = 0; i < queue.size(); i++){
                if (queue[i].distance < queue[smallest].distance){
                    smallest = i;
                }
            }
            // remove node from queue
            Node node = queue[smallest];
            queue.erase(queue.begin() + smallest);
            // for each neighbor of node
            for (int i = 0; i < node.neighbors.size(); i++){
                // if distance to neighbor is greater than distance to node + weight of edge
                if (node.neighbors[i].node->distance > node.distance + node.neighbors[i].weight){
                    // set distance to neighbor to distance to node + weight of edge
                    node.neighbors[i].node->distance = node.distance + node.neighbors[i].weight;
                }
            }
        }
        // print distances
        for (int i = 0; i < graph.nodes.size(); i++){
            std::cout << graph.nodes[i].distance << std::endl;
        }
    }
    static void BellmanFord(Graph graph, int start){
        // initialize all nodes to infinity
        for (int i = 0; i < graph.nodes.size(); i++){
            graph.nodes[i].distance = INT_MAX;
        }
        // set start node to 0
        graph.nodes[start].distance = 0;
        // for each node
        for (int i = 0; i < graph.nodes.size(); i++){
            // for each edge
            for (int j = 0; j < graph.edges.size(); j++){
                // if distance to neighbor is greater than distance to node + weight of edge
                if (graph.edges[j].node1->distance > graph.edges[j].node2->distance + graph.edges[j].weight){
                    // set distance to neighbor to distance to node + weight of edge
                    graph.edges[j].node1->distance = graph.edges[j].node2->distance + graph.edges[j].weight;
                }
            }
        }
        // print distances
        for (int i = 0; i < graph.nodes.size(); i++){
            std::cout << graph.nodes[i].distance << std::endl;
        }
    }
    static void FloydWarshall(Graph graph, int start){
        // initialize all nodes to infinity
        for (int i = 0; i < graph.nodes.size(); i++){
            for (int j = 0; j < graph.nodes.size(); j++){
                graph.nodes[i].distance = INT_MAX;
            }
        }
        // set start node to 0
        graph.nodes[start].distance = 0;
        // for each node
        for (int i = 0; i < graph.nodes.size(); i++){
            // for each edge
            for (int j = 0; j < graph.edges.size(); j++){
                // if distance to neighbor is greater than distance to node + weight of edge
                if (graph.edges[j].node1->distance > graph.edges[j].node2->distance + graph.edges[j].weight){
                    // set distance to neighbor to distance to node + weight of edge
                    graph.edges[j].node1->distance = graph.edges[j].node2->distance + graph.edges[j].weight;
                }
            }
        }
        // print distances
        for (int i = 0; i < graph.nodes.size(); i++){
            std::cout << graph.nodes[i].distance << std::endl;
        }
    }
    static void AStar(Graph graph, int start){
        // initialize all nodes to infinity
        for (int i = 0; i < graph.nodes.size(); i++){
            graph.nodes[i].distance = INT_MAX;
        }
        // set start node to 0
        graph.nodes[start].distance = 0;
        // create a queue of nodes
        std::vector<Node> queue;
        // add all nodes to queue
        for (int i = 0; i < graph.nodes.size(); i++){
            queue.push_back(graph.nodes[i]);
        }
        // while queue is not empty
        while (!queue.empty()){
            // find node with smallest distance
            int smallest = 0;
            for (int i = 0; i < queue.size(); i++){
                if (queue[i].distance < queue[smallest].distance){
                    smallest = i;
                }
            }
            // remove node from queue
            Node node = queue[smallest];
            queue.erase(queue.begin() + smallest);
            // for each neighbor of node
            for (int i = 0; i < node.neighbors.size(); i++){
                // if distance to neighbor is greater than distance to node + weight of edge
                if (node.neighbors[i].node->distance > node.distance + node.neighbors[i].weight){
                    // set distance to neighbor to distance to node + weight of edge
                    node.neighbors[i].node->distance = node.distance + node.neighbors[i].weight;
                }
            }
        }
        // print distances
        for (int i = 0; i < graph.nodes.size(); i++){
            std::cout << graph.nodes[i].distance << std::endl;
        }
    }
    static void Prim(Graph graph, int start){
        // initialize all nodes to infinity
        for (int i = 0; i < graph.nodes.size(); i++){
            graph.nodes[i].distance = INT_MAX;
        }
        // set start node to 0
        graph.nodes[start].distance = 0;
        // create a queue of nodes
        std::vector<Node> queue;
        // add all nodes to queue
        for (int i = 0; i < graph.nodes.size(); i++){
            queue.push_back(graph.nodes[i]);
        }
        // while queue is not empty
        while (!queue.empty()){
            // find node with smallest distance
            int smallest = 0;
            for (int i = 0; i < queue.size(); i++){
                if (queue[i].distance < queue[smallest].distance){
                    smallest = i;
                }
            }
            // remove node from queue
            Node node = queue[smallest];
            queue.erase(queue.begin() + smallest);
            // for each neighbor of node
            for (int i = 0; i < node.neighbors.size(); i++){
                // if distance to neighbor is greater than distance to node + weight of edge
                if (node.neighbors[i].node->distance > node.distance + node.neighbors[i].weight){
                    // set distance to neighbor to distance to node + weight of edge
                    node.neighbors[i].node->distance = node.distance + node.neighbors[i].weight;
                }
            }
        }
        // print distances
        for (int i = 0; i < graph.nodes.size(); i++){
            std::cout << graph.nodes[i].distance << std::endl;
        }
    }
    static void Kruskal(Graph graph, int start){
        // initialize all nodes to infinity
        for (int i = 0; i < graph.nodes.size(); i++){
            graph.nodes[i].distance = INT_MAX;
        }
        // set start node to 0
        graph.nodes[start].distance = 0;
        // create a queue of nodes
        std::vector<Node> queue;
        // add all nodes to queue
        for (int i = 0; i < graph.nodes.size(); i++){
            queue.push_back(graph.nodes[i]);
        }
        // while queue is not empty
        while (!queue.empty()){
            // find node with smallest distance
            int smallest = 0;
            for (int i = 0; i < queue.size(); i++){
                if (queue[i].distance < queue[smallest].distance){
                    smallest = i;
                }
            }
            // remove node from queue
            Node node = queue[smallest];
            queue.erase(queue.begin() + smallest);
            // for each neighbor of node
            for (int i = 0; i < node.neighbors.size(); i++){
                // if distance to neighbor is greater than distance to node + weight of edge
                if (node.neighbors[i].node->distance > node.distance + node.neighbors[i].weight){
                    // set distance to neighbor to distance to node + weight of edge
                    node.neighbors[i].node->distance = node.distance + node.neighbors[i].weight;
                }
            }
        }
        // print distances
        for (int i = 0; i < graph.nodes.size(); i++){
            std::cout << graph.nodes[i].distance << std::endl;
        }
    }
    static void Johnson(Graph graph, int start){
        // initialize all nodes to infinity
        for (int i = 0; i < graph.nodes.size(); i++){
            graph.nodes[i].distance = INT_MAX;
        }
        // set start node to 0
        graph.nodes[start].distance = 0;
        // create a queue of nodes
        std::vector<Node> queue;
        // add all nodes to queue
        for (int i = 0; i < graph.nodes.size(); i++){
            queue.push_back(graph.nodes[i]);
        }
        // while queue is not empty
        while (!queue.empty()){
            // find node with smallest distance
            int smallest = 0;
            for (int i = 0; i < queue.size(); i++){
                if (queue[i].distance < queue[smallest].distance){
                    smallest = i;
                }
            }
            // remove node from queue
            Node node = queue[smallest];
            queue.erase(queue.begin() + smallest);
            // for each neighbor of node
            for (int i = 0; i < node.neighbors.size(); i++){
                // if distance to neighbor is greater than distance to node + weight of edge
                if (node.neighbors[i].node->distance > node.distance + node.neighbors[i].weight){
                    // set distance to neighbor to distance to node + weight of edge
                    node.neighbors[i].node->distance = node.distance + node.neighbors[i].weight;
                }
            }
        }
        // print distances
        for (int i = 0; i < graph.nodes.size(); i++){
            std::cout << graph.nodes[i].distance << std::endl;
        }
    }
    static void EdmondsKarp(Graph graph, int start);
    static void FordFulkerson(Graph graph, int start);

};