#include <cstdlib>
#include <string>
#include <iostream>
#include "KMPBase.h"
#include "KMPQuery.h"

const char patternFile[] = "pattern.txt";
const char arrayFile[] = "array.txt";

void invalid_arg()
{
    std::cout << "Invalid argument." << std::endl;
    std::cout << "Usage: main <query number>" << std::endl;
    exit(0);
}

// Modify the code to accept command-line arguments
int main(int argc, char **argv)
{
	// Code for command-line arguments ...
    int queryNum;
    // std::stoi doesn't work with MinGW
    if (argc != 2 || (queryNum = strtol(argv[1], NULL, 10)) <= 0)
        invalid_arg();
	
    KMPQuery query(patternFile, arrayFile, queryNum);

    // The following code should NOT be changed.
    query.match();
    query.printMatches();

    return 0;
}
