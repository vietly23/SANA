#include <string>
#include <iostream>
#include <set>
#include <sstream>
#include "graphLoader.hpp"
#include "../utils/Timer.hpp"

using namespace std;

/*
The program requires that there exist the network files in GW format
in networks/g1name/g1name.gw and networks/g1name/g2name.gw.

The -g1 and -g2 arguments allow you to specify g1name and g2name directly.
These arguments assume that the files already exist.

The -fg1 and -fg2 arguments allow you to specify external files containing
the graph definitions (in either GW or edge list format). If these
arguments are used, -g1 and -g2 are ignored. g1Name and g2Name are deduced
from the file names (by removing the path and the extension). Then,
the network definitions are parsed and the necessary network files are created.

 */
void initGraphs(Graph& G1, Graph& G2, ArgumentParser& args) {
    cerr << "Initializing graphs... " << endl;
    Timer T;
    T.start();
    string fg1 = args.strings["-fg1"], fg2 = args.strings["-fg2"], path1 = args.strings["-pathmap1"], path2 = args.strings["-pathmap2"];
    createFolder("networks");
    string g1Name, g2Name;
    uint p1 = 1, p2 = 1;
    if (fg1 != "") {
        g1Name = extractFileNameNoExtension(fg1);
    } else {
        g1Name = args.strings["-g1"];
    }
    if (fg2 != "") {
        g2Name = extractFileNameNoExtension(fg2);
    } else {
        g2Name = args.strings["-g2"];
    }

    if (path1 != "") {
        p1 = atoi(path1.c_str());
    }

    if (path2 != "") {
        p2 = atoi(path2.c_str());
    }

    string g1Folder, g2Folder;
    g1Folder = "networks/"+g1Name;
    g2Folder = "networks/"+g2Name;
    // createFolder(g1Folder);
    // createFolder(g2Folder);
    // createFolder(g1Folder+"/autogenerated");
    // createFolder(g2Folder+"/autogenerated");

    string g1GWFile, g2GWFile;
    g1GWFile = g1Folder+"/"+g1Name+".gw";
    // if (fileExists(g1GWFile) and fg1 != "") {
    //     cerr << "Warning: argument of -fg1 (" << fg1 <<
    //             ") ignored because there already exists a network named " << g1Name << endl;
    // }
    g2GWFile = g2Folder+"/"+g2Name+".gw";
    // if (fileExists(g2GWFile) and fg2 != "") {
    //     cerr << "Warning: argument of -fg2 (" << fg2 <<
    //             ") ignored because there already exists a network named " << g2Name << endl;
    // }

    if (not fileExists(g1GWFile)) {
        if (fg1 != "") {
            // if (fileExists(fg1)) {
            //     if (fg1.size() > 3 and fg1.substr(fg1.size()-3) == ".gw") {
            //         exec("cp "+fg1+" "+g1GWFile);
            //     } else {
            //         Timer tConvert;
            //         tConvert.start();
            //         cerr << "Converting g1 to .gw (";
            //         Graph::edgeList2gw(fg1, g1GWFile);
            //         cerr << tConvert.elapsedString() << "s)" << endl;
            //     }
            // } else {
            //     throw runtime_error("File not found: "+fg1);
            // }
        } else {
            throw runtime_error("File not found: " + g1GWFile);
        }
    }
    if (not fileExists(g2GWFile)) {
        if (fg2 != "") {
            // if (fileExists(fg2)) {
            //     if (fg2.size() > 3 and fg2.substr(fg2.size()-3) == ".gw") {
            //         exec("cp "+fg2+" "+g2GWFile);
            //     } else {
            //         Timer tConvert;
            //         tConvert.start();
            //         cerr << "Converting g2 to .gw (";
            //         Graph::edgeList2gw(fg2, g2GWFile);
            //         cerr << tConvert.elapsedString() << "s)" << endl;
            //     }
            // } else {
            //     throw runtime_error("File not found: "+fg2);
            // }
        } else {
            throw runtime_error("File not found: " + g2GWFile);
        }
    }

    // Reading the locked nodes
    vector<string> column1;
    vector<string> column2;

    string lockFile = args.strings["-lock"];
    if(lockFile != ""){
        if(fileExists(lockFile)){
            checkFileExists(lockFile);
            cerr << "Locking the nodes in " << lockFile << endl;
            ifstream ifs(lockFile.c_str());
            string node;
            while(ifs >> node){
                column1.push_back(node);
                ifs >> node;
                column2.push_back(node);
            }
        }
        else{
            cerr << "Lock file (" << lockFile << ") does not exist!" << endl;
            throw runtime_error("Lock file not found: " + lockFile);
        }
    }

    //
    Timer tLoad;
    tLoad.start();
    if (p1 == 1 && p2 == 1){
        cerr << "Load graphs using Graph::loadGraph(";

        if(fg1 == ""){
            G1 = Graph::loadGraph(g1Name);
        }
        else{
            Graph::loadFromEdgeListFile(fg1, g1Name, G1);
        }

        if(fg2 == ""){
            G2 = Graph::loadGraph(g2Name);
        }
        else {
            Graph::loadFromEdgeListFile(fg2, g2Name, G2);
        }

        //G1.maxsize = 4;
        //G2.maxsize = 4;
    }
    else{
        cerr << "Load graphs using Graph::multGraph(";
        G1 = Graph::multGraph(g1Name, p1);
        G2 = Graph::multGraph(g2Name, p2);
    }
    cerr << tLoad.elapsedString() << "s)" << endl;

    if (G1.getNumNodes() > G2.getNumNodes()) {
        Timer tSwap;
        tSwap.start();
        Graph G3;
        G3 = G1;
        G1 = G2;
        G2 = G3;
        cerr << "Switching G1 and G2 because G1 has more nodes than G2. (" << tSwap.elapsedString() << "s)" << endl;
    }

    Timer T2;
    T2.start();

    double maxGraphletSize = args.doubles["-maxGraphletSize"];
    if (maxGraphletSize){
        G1.setMaxGraphletSize(maxGraphletSize);
        G2.setMaxGraphletSize(maxGraphletSize);
        //std::cout<<"\nSetting max graphlet size to: "<<maxGraphletSize<<endl;
        if (maxGraphletSize == 5 || maxGraphletSize == 4)
            std::cerr<<"Setting maximum graphlet size to "<<maxGraphletSize<<". . ."<<endl;
        else{
            std::cerr<<"ERROR: Invalid graphlet size: "<<maxGraphletSize<<"\nShould be 4 or 5\n";
            exit(0);
        }
    }


    // For "-nodes-have-types"
    if(args.bools["-nodes-have-types"]){
        cerr << "Initializing the node types" << endl;
//         if(!fileExists(fg1)){
//             cerr << "fg1 (" << fg1 << ") file does not exists!" << endl;
//             throw runtime_error("fg1 (" + fg1 + ") file does not exists!");
//         }
//         if(!fileExists(fg1)){
//             cerr << "fg2 (" << fg2 << ") file does not exists!" << endl;
//             throw runtime_error("fg1 (" + fg2 + ") file does not exists!");
//         }
//
//         set<string> genesG1, genesG2;
//         set<string> miRNAsG1, miRNAsG2;
//
//         ifstream ifs1(fg1.c_str());
//         string node;
//         // We have edgelists, first column gene, second is miRNA
//         // GENE miRNA
// #ifdef WEIGHTED
//         while (getline(ifs1,node)) {
//                 istringstream m_iss(node);
//                 m_iss >> node;
//             genesG1.insert(node);
//             m_iss >> node;
//             miRNAsG1.insert(node);
//         }
// #else
//         while(ifs1 >> node){
//             genesG1.insert(node);
//             ifs1 >> node;
//             miRNAsG1.insert(node);
//         }
// #endif
//         // Same for fg2
//         ifstream ifs2(fg2.c_str());
// #ifdef WEIGHTED
//         // Same for fg2
//         while (getline(ifs2,node)) {
//                 istringstream m_iss(node);
//                 m_iss >> node;
//             genesG1.insert(node);
//             m_iss >> node;
//             miRNAsG1.insert(node);
//         }
// #else
//         while(ifs2 >> node){
//             genesG2.insert(node);
//             ifs2 >> node;
//             miRNAsG2.insert(node);
//         }
// #endif

        // G1.setNodeTypes(genesG1, miRNAsG1);
        // G2.setNodeTypes(genesG2, miRNAsG2);

        // Currently we have these constraints
        // if(not (genesG1.size() < genesG2.size())){
        if(not (G1.geneCount < G2.geneCount)){
            cerr << "g1 should have less genes  than g2 " << endl;
            cerr << "! " <<  G1.geneCount << " < " << G2.geneCount << endl;
            throw runtime_error("g1 should have less genes than g2 \n ");
        }
        // if(not (miRNAsG1.size() < miRNAsG2.size())){
        if(not (G1.miRNACount < G2.miRNACount)){
            cerr << "g1 should have less miRNAs than g2 " << endl;
            cerr << "! " <<  G1.miRNACount << " < " << G2.miRNACount << endl;
            throw runtime_error("g1 should have less miRNAs than g2\n ");
        }

    }


    // Getting Valid locks
    if(lockFile != ""){
        cerr << "Initializing locking... with lock file " + lockFile << endl;

        vector<string> validLocksG1;
        vector<string> validLocksG2;
        unordered_map<string,ushort> mapG1 = G1.getNodeNameToIndexMap();
        unordered_map<string,ushort> mapG2 = G2.getNodeNameToIndexMap();

        for(uint i = 0; i < column1.size(); i++){
            bool validLock = true;
            string nodeG1 = column1[i];
            string nodeG2 = column2[i];

            if(mapG1.find(nodeG1) == mapG1.end())
                validLock = false;
            if (mapG2.find(nodeG2) == mapG2.end())
                validLock = false;
            if(validLock){
                validLocksG1.push_back(nodeG1);
                validLocksG2.push_back(nodeG2);
            }
        }


        // Setting the locks
        G1.setLockedList(validLocksG1, validLocksG2);
        G2.setLockedList(validLocksG2, validLocksG1);

        if(column1.size() > 0 && column1.size() != validLocksG1.size()){
            cerr << "Warning: Out of " << column1.size() << " locks only ";
            cerr << validLocksG1.size() << " were valid locks. [Invalid locks are ignored]" << endl;
        }

    }
    cerr << "locking initialization done (" << T2.elapsedString() << ")" << endl;

    // Method #3 of locking
    Timer tReIndex;
    tReIndex.start();
    if(args.bools["-nodes-have-types"]){
        G1.reIndexGraph(G1.getNodeTypes_ReIndexMap());
    }
    else if(lockFile != ""){
        G1.reIndexGraph(G1.getLocking_ReIndexMap());
    }
    cerr << "done reIndexGraph G1 (" << tReIndex.elapsedString() << "s)" << endl;
    /*double maxSize = args.doubles["-maxGraphletSize"];
    //int maxSize2;
    //stringstream convert(maxS
    if(maxSize){
        std::cout<<"MAXGRAPHLET SIZE IS _____________"<<maxSize<<endl;
        //G1.computeGraphletDegreeVectors(maxSize);

    }*/
    double rewiredFraction = args.doubles["-rewire"];
    if (rewiredFraction > 0) {
        if (rewiredFraction > 1) {
            throw runtime_error("Cannot rewire more than 100% of the edges");
        }
        G2.rewireRandomEdges(rewiredFraction);
    }

    /*if (G1.getNumNodes() > G2.getNumNodes()) {
        throw runtime_error("G2 has less nodes than G1");
    }*/
    if (G1.getNumEdges() == 0 or G2.getNumEdges() == 0) {
        throw runtime_error("One of the networks has 0 edges");
    }

    cerr << "Total time for loading graphs (" << T.elapsedString() << "s)" << endl;
}
