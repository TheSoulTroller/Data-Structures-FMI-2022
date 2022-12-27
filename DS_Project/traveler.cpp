#include "Interpretator.h"

int main()
{
    Graph graph("graph.txt");
    // cout << "Printing graph:\n";
    // graph.printGraph();
    graph.antColonyOptimization();

    // std::string command;
    // do
    // {
    //     std::cout << ">";
    //     std::cin >> command;
    // }
    // while(Interpretator::interpretate(command));

    // return 0;
}

int FindDistance(const Node& a, const Node& b) {
  for (size_t i = 0; i < a.neighbors.size(); ++i) {
    if (a.neighbors[i]->name == b.name) {
      return a.length[i];
    }
  }
  return -1;
}

int TourLength(const std::vector<Node>& tour) {
  int length = 0;
  for (size_t i = 1; i < tour.size(); ++i) {
    length += FindDistance(tour[i - 1], tour[i]);
  }
  length += FindDistance(tour.back(), tour.front());
  return length;
}

void TSP_FarthestInsertion(const std::vector<Node>& nodes,
                                        const Node& start_node) {
  std::vector<Node> tour{start_node};
  std::unordered_set<Node*> unvisited_nodes(nodes.begin(), nodes.end());
  unvisited_nodes.erase(&start_node);

  while (!unvisited_nodes.empty()) {
    Node* farthest_node = nullptr;
    int farthest_distance = 0;
    for (Node* node : unvisited_nodes) {
      int distance = std::numeric_limits<int>::max();
      for (const Node& tour_node : tour) {
        distance = std::min(distance, FindDistance(*node, tour_node));
      }
      if (distance > farthest_distance) {
        farthest_node = node;
        farthest_distance = distance;
      }
    }

    int closest_distance = std::numeric_limits<int>::max();
    size_t insert_before = 0;
    for (size_t i = 1; i < tour.size(); ++i) {
      int distance = FindDistance(tour[i - 1], *farthest_node) +
                     FindDistance(*farthest_node, tour[i]) -
                     FindDistance(tour[i - 1], tour[i]);
      if (distance < closest_distance) {
        closest_distance = distance;
        insert_before = i;
      }
    }

    tour.insert(tour.begin() + insert_before, *farthest_node);
    unvisited_nodes.erase(farthest_node);
  }

    //printing tour :
    
  return ;
}
