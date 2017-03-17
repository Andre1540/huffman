#include "huffman.hpp"
#include <iostream>

using namespace std;

const string comp = "-c";
const string decomp = "-u";
const string f = "-f";
const string o = "-o";
const string f1 = "--file";
const string o1 = "--output";

int main(int argc, char ** arg)
{

    char * file_nameIN = nullptr;
    char * file_nameOUT = nullptr;


    if (argc == 1)
    {
        cerr << "Program is run with no arguments.";
        return 1;
    }

    if (arg[1] != comp && arg[1] != decomp)
    {
        std::cerr << "Unknown operation \"" << arg[1] << "\"" << endl;
        return 1;
    }
    else if (arg[1] == comp)
    {
        if (arg[2] != f && arg[2] != f1)
        {
            std::cerr << "Type flag \"-f\" or \"--file\" instead of \"" << arg[2] << "\" before the name of a file you want to compress!" << endl;
            return 1;
        }
        file_nameIN = arg[3];
        if (arg[4] != o && arg[4] != o1)
        {
            std::cerr << "Type flag \"-o\" or \"--output\" instead of \"" << arg[4] << "\" before the file you want to save the result in!" << endl;
            return 1;
        }
        file_nameOUT = arg[5];
    }
    else if (arg[1] == decomp)
    {
        if (arg[2] != f && arg[2] != f1)
        {
            std::cerr << "Type flag \"-f\" or \"--file\" instead of \"" << arg[2] << "\" before the file you want to decompress!" << endl;
            return 1;
        }
        file_nameIN = arg[3];
        if (arg[4] != o && arg[4] != o1)
        {
            std::cerr << "Type flag \"-o\" or \"--output\" instead of \"" << arg[4] << "\" before the file you want to save the result in!" << endl;
            return 1;
        }
        file_nameOUT = arg[5];
    }

    if (arg[1] == comp)
    {
        if (compress(file_nameIN, file_nameOUT))
        {
            return 1;
        }
    }

    if (arg[1] == decomp)

    {
        if (decompress(file_nameIN, file_nameOUT))
        {
            return 1;
        }
    }

    return 0;
}
