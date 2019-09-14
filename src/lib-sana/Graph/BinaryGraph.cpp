#include "AdjacencyMatrixIterator.hpp"
#include "BinaryGraph.hpp"
#include <algorithm>

namespace {
}
// TODO: Keep edge property *NOT* in the adjmatrix. A graph could represent an edge with false value, but in this case we will take the edge to be true
void BinaryGraph::AddEdge(const unsigned int &node1, const unsigned int &node2, const unsigned bool& weight) {
}

void BinaryGraph::RemoveEdge(const unsigned int &node1, const unsigned int &node2) {
    adjacencyMatrix[node1][node2] = adjacencyMatrix[node2][node1] = false;
}

void BinaryGraph::AddVertex() {
    adjacencyMatrix.resize(requiredSpace(++numNodes));
}

void BinaryGraph::ClearGraph() {
    adjacencyMatrix.clear();
}

