#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <array>
#include <utility>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <random>
#include "utils/utils.hpp"
#include "utils/Timer.hpp"
#include "utils/computeGraphlets.hpp"
#include "utils/Matrix.hpp"

//EDGE_T: macro specifying the type of the edge weights
#ifdef MULTI_PAIRWISE
  #ifdef FLOAT_WEIGHTS
    #define EDGE_T float
    #error currently, multi_pairwise is not designed for float edges
  #else
    #define EDGE_T unsigned char //change to unsigned short for >256 networks
  #endif
#else
  #ifdef FLOAT_WEIGHTS
    #define EDGE_T float
  #else
    #define EDGE_T bool //unweighted graphs -- the normal/traditional setting
  #endif
#endif
namespace sana {
    union EdgeType {
        bool edgeExists;
        unsigned char numberWeight;
        float floatWeight;
    };
    struct Source {
        uint value;
        constexpr operator uint() {return value;};
    };
    struct Destination {
        uint value;
        constexpr operator uint() {return value;};
    };
    struct Edge {
        Edge(Source s, Destination d);
        Edge(const Edge& other);
        uint source;
        uint destination;
        static bool compare(const Edge& a, const Edge& b);
    };
    struct GraphData {
        GraphData(std::vector<std::string> nodeNames, std::vector<Edge> edgeList) : NodeNames(nodeNames), EdgeList(edgeList) {};
        const std::vector<std::string> NodeNames;
        const std::vector<Edge> EdgeList;
    };
}

class Graph {
public:
    typedef std::vector<std::string> NodeNames;
    typedef std::vector<EDGE_T> EdgeWeights;
    typedef std::vector<std::array<std::string, 2>> NodeColors;
    typedef std::vector<std::array<uint, 2>> EdgeList;
    /* All-purpose constructor
    - optionalFilePath can be left empty if not relevant
    - self-loops are allowed in the edge list
    - the edge list should not contain repeated entries
    - if optionalNodeNames is empty, the number of nodes is deduced from
      the edge list and name "i" is given to the i-th node
      the name list should not contain repeated names
    - if optionalEdgeWeights is empty, all nodes get weight 1 (i.e., unweighted graph).
      Otherwise, edgeWeights should have the same size as edgeList.
      Edges with weight 0 are not supported and will end in runtime_error
    - partialNodeColorPairs is a list of node/color name pairs.
      Any node not in any pair gets a special default color */
    Graph(const std::string& name,
          const std::string& optionalFilePath,
          const std::vector<std::array<uint, 2>>& edgeList,
          const std::vector<std::string>& optionalNodeNames,
          const std::vector<EDGE_T>& optionalEdgeWeights,
          const std::vector<std::array<std::string, 2>>& partialNodeColorPairs);

    //there is no default constructor intentionally to disable the option of
    //creating empty graphs and populating the data structures directly.

    //calling this function is the same as passing the parameter directly to the constructor,
    //which is recommended. This function only exists in case you need to construct the (rest 
    //of the) graph before you can compute the colors (e.g., if the colors depend on the node names)
    void initColorDataStructs(const std::vector<std::array<std::string, 2>>& partialNodeColorPairs);

    //derived graphs: they all call the same constructor above, ensuring internal consistency.
    //prefer this "functional" way of creating new graphs rather than modifying the current graph
    //do not add I/O functions to the Graph class. Use GraphLoader.
    Graph nodeInducedSubgraph(const std::vector<uint>& nodes) const;
    Graph randomNodeInducedSubgraph(uint numNodes) const;
    Graph shuffledGraph(std::vector<uint>& newToOldMap) const; //the parameter is a return value
    Graph graphPower(uint power) const; //graph obtained by multiplying the adj matrix by itself 'power' times
    Graph graphWithAddedRandomEdges(double addedEdgesProportion) const;
    Graph graphWithRemovedRandomEdges(double removedEdgesProportion) const;
    Graph graphWithRewiredRandomEdges(double rewiredEdgesProportion) const;
    //keeps only the edges that are also in other. the result is unweighted
    Graph graphIntersection(const Graph& other, const std::vector<uint>& thisToOtherNodeMap) const;

    //O(1) getters (defined in header for efficiency -- allows inlining)
    std::string getName() const { return name; }
    std::string getFilePath() const { return filePath; }
    uint getNumNodes() const { return adjLists.size(); }
    uint getNumEdges() const { return edgeList.size(); }
    //note: edges with weight 0 are not supported
    bool hasEdge(uint node1, uint node2) const { return adjMatrix.get(node1, node2) != 0; }
    //returns 0 if there is no edge; the order of the arguments is irrelevant
    EDGE_T getEdgeWeight(uint node1, uint node2) const { return adjMatrix.get(node1, node2); }
    bool hasNodeName(const std::string& nodeName) const { return nodeNameToIndexMap.count(nodeName); }
    std::string getNodeName(uint node) const { return nodeNames.at(node); }
    uint getNameIndex(const std::string& nodeName) const { return nodeNameToIndexMap.at(nodeName); } //reverse of getNodeName
    uint getNumNbrs(uint node) const { return adjLists[node].size(); }
    double getTotalEdgeWeight() const { return totalEdgeWeight; }
    bool hasSelfLoop(uint node) const { return adjMatrix.get(node, node) != 0; }
    
    //large data structures are returned as const pointers
    //recommendation: use the getters above instead, when possible
    const std::vector<uint>* getAdjList(uint node) const { return &adjLists.at(node); }
    const std::vector<std::vector<uint>>* getAdjLists() const { return &adjLists; }
    const std::vector<std::array<uint, 2>>* getEdgeList() const { return &edgeList; }
    const Matrix<EDGE_T>* getAdjMatrix() const { return &adjMatrix; }
    const std::vector<std::string>* getNodeNames() const { return &nodeNames; }
    const std::unordered_map<std::string,uint>* getNodeNameToIndexMap() const { return &nodeNameToIndexMap; }
    // Viet - Also not sure if we need this? Again, this is just to verify compile
    std::unordered_map<uint,std::string> getIndexToNodeNameMap() const;

    //things that are computed when called
    uint randomNode() const;
    uint maxDegree() const;
    std::vector<uint> degreeDistribution() const;
    std::vector<std::vector<uint>> connectedComponents() const; //nodes grouped by CCs, sorted from larger to smaller
    uint numEdgesInNodeInducedSubgraph(const std::vector<uint>& subgraphNodes) const;
    std::vector<uint> numEdgesAroundByLayers(uint node, uint maxDist) const;
    std::vector<uint> numNodesAroundByLayers(uint node, uint maxDist) const;
    std::vector<uint> nodesAround(uint node, uint maxDist) const;
    bool hasSameNodeNamesAs(const Graph& other) const;
    std::vector<std::string> commonNodeNames(const Graph& other) const;
    
    // COLOR SYSTEM
    //colors have arbitrary strings as names. internally, they also have a numeric
    //id starting from 0, used as index for data structures
    //transform back and forth between ids and names:
    uint getColorId(std::string colorName) const;
    std::string getColorName(uint colorId) const;
    const std::vector<std::string>* getColorNames() const; //all names sorted by id

    //we say the graph "has" a color if there is at least one node with that color.
    //getColorId assumes that the graph has the passed color
    //if that assumption is not certain, it should be checked first:
    bool hasColor(std::string colorName) const;
    uint getNodeColor(uint node) const;
    uint numColors() const;
    
    //functions that is part of SANA's main loop. Defined here to allow inlining
    uint numNodesWithColor(uint colorId) const { return nodeGroupsByColor.at(colorId).size(); }
    const std::vector<uint>* getNodesWithColor(uint colorId) const { return &nodeGroupsByColor.at(colorId); }
    static const std::string DEFAULT_COLOR_NAME;

    //color ids are internal to each graph (i.e., color i in G1 may not have the same name as color i in G2)
    //this maps the color ids of this graph to the color ids of the other graph with the
    //same name (or to the special value INVALID_COLOR_ID if the other graph has no color with that name)
    std::vector<uint> myColorIdsToOtherGraphColorIds(const Graph& other) const;
    static const uint INVALID_COLOR_ID;

    //useful when creating a derived graph with the same nodes and colors
    //creates the vector of pairs that the constructor needs
    std::vector<std::array<std::string, 2>> colorsAsNodeColorNamePairs() const;

    //check for internal consistency. good practice to keep it in an "assert"
    //after constructing or modifying a graph
    bool isWellDefined() const;
    void debugPrint() const; //print info about the internal state of graph

private:
    std::string name, filePath;

    //main data structures
    std::vector<std::array<uint, 2>> edgeList; //edges in no particular order, no repetitions
    std::vector<std::string> nodeNames;
    std::vector<std::vector<uint>> adjLists; //neighbors in no particular order, no repetitions
    Matrix<EDGE_T> adjMatrix;
    std::unordered_map<std::string, uint> nodeNameToIndexMap; //reverse of nodeNames

    //each edge has a weight in the range of type EDGE_T, but their sum may be beyond that range
    //double can contain the sum of EDGE_T values for any EDGE_T.
    double totalEdgeWeight;

    //data structures for the color system
    std::vector<uint> nodeColors; //node index to color index
    std::vector<std::string> colorNames; //color index to color name
    std::unordered_map<std::string, uint> colorNameToId; //color name to color index
    std::vector<std::vector<uint>> nodeGroupsByColor; //color index to list of node indices
    
    friend class SANA; //for convenience and speed(maybe?)
}; 

#endif /* GRAPH_H */