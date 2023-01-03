#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

string getOS() {
    #ifdef _WIN32
        return "Windows 32-bit";
    #elif _WIN64
        return "Windows 64-bit";
    #elif __APPLE__ || __MACH__
        return "Mac OSX";
    #elif __linux__
        return "Linux";
    #elif __FreeBSD__
        return "FreeBSD";
    #elif __unix || __unix__
        return "Unix";
    #else
        return "Other";
    #endif
}

void txtToBin(const string& file)
{
    // open the txt file
    ifstream txtFile(file);

    // create and open the binary file
    string newFileName = file.substr(0, file.find('.')) + ".bin";
    ofstream binFile(newFileName, ios::binary);

    // read the txt file line by line
    string line;

    // bassed on the OS we are running on, we need to add a carriage return
    // to the end of each line
    string cr = getOS() == "Windows 32-bit" || getOS() == "Windows 64-bit" ? "\r\n" : "\n";

    while (!txtFile.eof())
    {
        getline(txtFile, line);
        line += cr;
        binFile.write(line.c_str(), line.size());
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