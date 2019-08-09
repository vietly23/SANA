#ifndef BINARYGRAPH_HPP
#define BINARYGRAPH_HPP
#include "Graph.hpp"
#include <vector>

class BinaryGraph : public Graph {

    std::vector<std::vector<bool> > adjacencyMatrix;

public:

    BinaryGraph(){};
    ~BinaryGraph(){};

    virtual void AddEdge(const unsigned int &node1, const unsigned int &node2, const unsigned int &weight = 1);
    virtual void RemoveEdge(const unsigned int &node1, const unsigned int &node2);

    virtual void SetNumNodes(const unsigned int &numNodes);
    
    virtual void ClearGraph();
};

#endif
