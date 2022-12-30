#include "Interpretator.h"

int main()
{
    Graph graph("graph2.txt");
    // cout << "Printing graph:\n";
    // graph.printGraph();
    // graph.nearestNeighbour();
    graph.farthestInsertion();

    // std::string command;
    // do
    // {
    //     std::cout << ">";
    //     std::cin >> command;
    // }
    // while(Interpretator::interpretate(command));

    // return 0;
}