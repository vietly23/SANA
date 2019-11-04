#include <algorithm>

#include <graph/BinaryGraph.hpp>
#include <graph/detail/AdjacencyMatrix.hpp>

using edgeType = BinaryGraph::edgeType;
// TODO: Keep edge property *NOT* in the adjmatrix. A graph could represent an edge with false value, but in this case we will take the edge to be true
void BinaryGraph::AddEdge(const unsigned int &source, const unsigned int &target, 
        const edgeType& value) {
    adjacencyMatrix.setEdgeValue(source, target, value);
    numEdges++;
}

void BinaryGraph::RemoveEdge(const unsigned int &source, const unsigned int &target) {
    adjacencyMatrix.setEdgeValue(source, target, false);
    numEdges--;
}

void BinaryGraph::AddVertex() {
    if (numNodes == capacity) {
        capacity = numNodes * 2;
        adjacencyMatrix.resize(capacity);
    }
    numNodes++;
}

void BinaryGraph::ClearGraph() {
    adjacencyMatrix.clear();
    numEdges = 0;
    numNodes = 0;
}

unsigned int BinaryGraph::GetNumVertices() const {
   return numNodes; 
}

unsigned int BinaryGraph::GetNumEdges() const {
   return numEdges;
}

