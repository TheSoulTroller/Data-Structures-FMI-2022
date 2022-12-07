#include "Interpretator.h"

int main()
{
    std::string command;
    do
    {
        std::cout << ">";
        std::cin >> command;
    }
    while(Interpretator::interpretate(command);

    return 0;
}
