#ifndef BINARYGRAPH_HPP
#define BINARYGRAPH_HPP

#include <vector>
#include "AdjacencyMatrix.hpp"
#include "Graph.hpp"

class BinaryGraph : public Graph<bool> {
// WARNING: Setting an edge to false effectively erases it and will incorrectly increment the edge value
    virtual void AddEdge(const unsigned int &source, const unsigned int &target, 
            const EdgeProperty &weight);
    virtual void RemoveEdge(const unsigned int &source, const unsigned int &target);
    virtual EdgeProperty GetEdgeValue(const unsigned int &source, const unsigned int &target);
    // TODO: Change to use VertexProperty.
    virtual void AddVertex();
    virtual unsigned int GetNumVertices() const;
    virtual unsigned int GetNumEdges() const;
    virtual void ClearGraph();

private:
    unsigned int capacity;
    unsigned int numEdges;
    unsigned int numNodes;
        
};

#endif
