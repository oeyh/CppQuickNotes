/********************** Read a File Line by Line ***********************/
// use ifstream (input file stream) class
#include <iostream>
#include <fstream> // for std::ifstream
#include <string> // for std::string and std::getline

int main() {
    std::ifstream infile("Notes-1.cpp");
    // check if open is success
    if (!infile) {
        std::cout << "Cannot open file." << std::endl;
        return 1;
    }

    // read line by line
    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }

    infile.close();
    return 0;
}
