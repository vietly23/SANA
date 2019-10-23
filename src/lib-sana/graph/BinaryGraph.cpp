#include "AdjacencyMatrixIterator.hpp"
#include "BinaryGraph.hpp"
#include <algorithm>

// TODO: Keep edge property *NOT* in the adjmatrix. A graph could represent an edge with false value, but in this case we will take the edge to be true
// WARNING: Setting an edge to false effectively erases it
void BinaryGraph::AddEdge(const unsigned int &source, const unsigned int &target, 
        const unsigned bool& value) {
    adjacencyMatrix.setEdgeValue(source, target, weight);
}

void BinaryGraph::RemoveEdge(const unsigned int &source, const unsigned int &target) {
    adjacencyMatrix.setEdgeValue(source, target, false);
}

void BinaryGraph::AddVertex() {
    adjacencyMatrix.resize(numNodes * 2);
}

void BinaryGraph::ClearGraph() {
    adjacencyMatrix.clear();
}
unsigned int BinaryGraph::GetNumNodes() const {
   return numNodes; 
}
unsigned int BinaryGraph::GetNumEdges() const {
   return numEdges;
}

