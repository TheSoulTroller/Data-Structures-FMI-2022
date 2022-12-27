#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

// define a function that takes a txt file and converts it to a binary file
void txtToBin(const std::string& file)
{
    // open the txt file
    std::ifstream txtFile(file);
    // open the binary file
    std::string newFileName = file.substr(0, file.find('.')) + ".bin";
    std::ofstream binFile(newFileName, std::ios::binary);

    // read the txt file line by line
    std::string line;

    while (!txtFile.eof())
    {
        std::getline(txtFile, line);
        cout << line << endl;
        binFile.write(line.c_str(), line.size());
        binFile.write("\n",1);
    }

    // close the files
    txtFile.close();
    binFile.close();
}

int main()
{
    txtToBin("graph.txt");
    return 0;
}