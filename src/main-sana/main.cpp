#include "SANA.hpp"
#include "SANAResult.hpp"
#include "SANAConfiguration.hpp"
#include "Graph.hpp"
#include "Utility.hpp"
#include <vector>
#include <iostream>

int main(int argc, char **argv) {
    /*
    if (argc < 3) {
        cerr << "Input must include two or more LEDA Graph file\n";
        return 1;
    }
    */
    // std::vector <Graph> networkList;
    /*
    if (config is weighted) {
    } else {
        for (int i = 1; i < argc; i++) {
            networkList.push_back(Utility::LoadBinaryGraphFromLEDAFile(argv[i]));
            //networkList.push_back(Utility::LoadBinaryGraphFromEdgeList(argv[i]));
        }
    }
    */

    /*
    SANAConfiguration sanaConfig;
    SANA sana(sanaConfig);
    SANAResult results = sana.StartAligner(networkList);
    */

    // step 1: parse args
    //      1a: optionally, parse config file
    // step 2: parse network files
    // step 3: with a specified aligner, pass in the network files and align
    // step 4: aligner will output to report
}
