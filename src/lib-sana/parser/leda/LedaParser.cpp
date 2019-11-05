#include <parser/leda/LedaParser.hpp>

// parse header section
// parse nodes section
// parse edges section
BinaryGraph LedaParser::parse(std::istream inputstream) {
    BinaryGraph bin;

    // verifyHeader
    stringstream errorMsg;
    istream infile(&sbuf);
    string line;

    //ignore header
    for (int i = 0; i < 4; ++i)
        getline(infile, line);
    return bin;
}

void Graph::loadGwFile(const string& fileName) {
    // this function could be improved to deal with blank lines and comments

    stdiobuf sbuf = readFileAsStreamBuffer(fileName);
    //read number of nodes
    int n;
    if(line == "-2") {
        getline(infile, line);
        istringstream iss2(line);
        (iss2 >> n);
    } else {
        n = stoi(line);
    }
    if (n <= 0) {
        errorMsg << "Failed to read node number: " << line << " read as " << n;
        throw runtime_error(errorMsg.str().c_str());
    }
    //read (and ditch) nodes
    string node;
    for (int i = 0; i < n; ++i) {
        getline(infile, line);
        istringstream iss(line);
        if (!(iss >> node)) {
            errorMsg << "Failed to read node " << i << " of " << n << ": " << line << " (" << node << ")";
            throw runtime_error(errorMsg.str().c_str());
        }
    }
    //read number of edges
    int m;
    getline(infile, line);
    istringstream iss2(line);
    if (!(iss2 >> m)) {
        errorMsg << "Failed to read edge number: " << line;
        throw runtime_error(errorMsg.str().c_str());
    }

    adjLists = vector<vector<uint> > (n, vector<uint>(0));
    matrix = Matrix<MATRIX_UNIT>(n);
#ifdef MULTI_PAIRWISE
    char dump;
    uint edgeValue;
#endif
    edgeList = vector<vector<uint> > (m, vector<uint>(2));
    lockedList = vector<bool> (n, false);
    lockedTo = vector<string> (n, "");
    nodeTypes = vector<int> (n, -1);

    geneCount = miRNACount = 0;

    //read edges
    uint node1;
    uint node2;

    for (int i = 0; i < m; ++i) {
        getline(infile, line);
        istringstream iss(line);
#ifdef MULTI_PAIRWISE
        if (!(iss >> node1 >> node2 >> dump >> dump >> dump)) {
#else
            if (!(iss >> node1 >> node2)) {
#endif
                errorMsg << "Failed to read edge: " << line;
                throw runtime_error(errorMsg.str().c_str());
            }

#ifdef MULTI_PAIRWISE
            if (!(iss >> edgeValue)) {
                errorMsg << "No edge value: " << line;
                edgeValue = 1;
            }
#endif
            node1--; node2--; //-1 because of remapping

            if(matrix[node1][node2] || matrix[node2][node1]){
                errorMsg << "duplicate edges not allowed (in either direction), node numbers are " << node1+1 << " " << node2+1 << '\n';
                //errorMsg << "In graph [" << graphName << "]: duplicate edges not allowed (in either direction), node names are " << nodeName2IndexMap[node1+1] << " " << nodeName2IndexMap[node2+1] << '\n';
                throw runtime_error(errorMsg.str().c_str());
            }
            if(node1 == node2) {
                errorMsg << "self-loops not allowed, node number " << node1+1 << '\n';
                throw runtime_error(errorMsg.str().c_str());
            }
            edgeList[i][0] = node1;
            edgeList[i][1] = node2;

#ifdef MULTI_PAIRWISE
            matrix[node1][node2] = matrix[node2][node1] = edgeValue;
#else
            matrix[node1][node2] = matrix[node2][node1] = true;
#endif
            adjLists[node1].push_back(node2);
            adjLists[node2].push_back(node1);
        }
        initConnectedComponents();
    }


