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
