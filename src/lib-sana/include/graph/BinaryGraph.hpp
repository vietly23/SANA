#ifndef BINARYGRAPH_HPP
#define BINARYGRAPH_HPP

#include <vector>
#include <graph/detail/AdjacencyMatrix.hpp>
#include <graph/Graph.hpp>

class BinaryGraph : public Graph<bool> {

public:
    using edgeType = bool;
    // WARNING: Setting an edge to false effectively erases it and will incorrectly increment the edge value
    virtual void AddEdge(const unsigned int &source, const unsigned int &target, 
            const edgeType &weight) override;
    virtual void RemoveEdge(const unsigned int &source, const unsigned int &target) override;
    // TODO: Change to use EdgeProperty
    virtual edgeType GetEdgeValue(const unsigned int &source, const unsigned int &target) override;
    // TODO: Change to use VertexProperty.
    virtual void AddVertex() override;
    virtual unsigned int GetNumVertices() const override;
    virtual unsigned int GetNumEdges() const override;
    virtual void ClearGraph() override;

private:
    unsigned int capacity;
    unsigned int numEdges;
    unsigned int numNodes;
    sana::detail::AdjacencyMatrix adjacencyMatrix;
};

#endif
