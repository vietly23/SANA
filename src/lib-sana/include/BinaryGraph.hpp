#ifndef BINARYGRAPH_HPP
#define BINARYGRAPH_HPP

#include <vector>
#include "AdjacencyMatrixIterator.hpp"
#include "Graph.hpp"

class BinaryGraph : public Graph<bool> {
public:
    typedef AdjacencyMatrixIterator<bool> edge_iterator;

    virtual void AddEdge(const unsigned int &source, const unsigned int &target, const bool &weight);
    virtual void RemoveEdge(const unsigned int &source, const unsigned int &target);

    unsigned int GetNumNodes() const;
    unsigned int GetNumEdges() const;
    virtual bool GetEdgeValue(const unsigned int &source, const unsigned int &target);
    virtual edge_iterator GetNeighbors(const unsigned int &source);
    // TODO: keep node names as internal mapping
    virtual void AddVertex();
    virtual void RemoveVertex(const unsigned int &vertex);
    virtual void ClearGraph();

private:
    unsigned int numNodes;
    unsigned int numEdges;
};

#endif
