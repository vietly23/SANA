#ifndef ADJ_MATRIX
#define ADJ_MATRIX

#include <tuple>
#include <vector>
#include <stdexcept>

#include "Edge.hpp"

namespace sana::detail {
    // TODO: Make unit-tests for following cases:
    // translateVertex(0, 0) == 0
    // translateVertex(3, 2) == 8
    // translateVertex(2, 3) == 8
    // translateVertex(1, 1) == 2
    // translateVertex(1, 0) == 1
    unsigned int translateVertex(const unsigned int &source, const unsigned int &target) {
        unsigned int row = std::max(source, target);
        unsigned int col = std::min(source, target);
        return row * (row + 1) / 2 + col;
    }

    unsigned int requiredSpace(const unsigned int &numVertices) {
        return numVertices * (numVertices + 1) / 2;
    }

    /*
     * Assumes that this is an undirected graph.
     * Makes the following assumptions
     * 1) Not thread-safe
     * 2) Assumes false => no edge, true => edge
     */
    class UndirectedAdjacencyMatrix {
    public:
        void resize(unsigned int numVertices) {
            adjacencyMatrix.resize(requiredSpace(numVertices));
        }
        bool edgeValue(unsigned int source, unsigned int target) {
            return adjacencyMatrix.at(translateVertex(source, target));
        }
        void setEdgeValue(unsigned int source, unsigned int target, bool value) {
            adjacencyMatrix[translateVertex(source, target)] = value;
        }
    private:
        std::vector<bool> adjacencyMatrix;
        // Utility methods for address translation
    };

    class AdjMatrixIterator {
    public:
        typedef Edge<bool> edge;
        typedef const std::vector<bool>* const container;
        AdjMatrixIterator(container adjMatrix, unsigned int startVertex, unsigned int offset, 
            unsigned int numVertices): adjMatrix(adjMatrix), startVertex(startVertex), offset(offset),
            numVertices(numVertices) {}; 

        bool hasNext() {
            return startVertex != numVertices;
        }

        edge next() { 
            if (not this->hasNext()) {
                throw std::out_of_range("AdjMatrixIterator::next() : index is out of range");
            }
            while (startVertex < numVertices and 
                    adjMatrix->at(translateVertex(startVertex, offset))) {
                ++offset;
                if (offset >= numVertices) {
                    offset = 0;
                    startVertex++;
                }
            }
            return edge(startVertex, offset, true);
        }
    private:
        unsigned int startVertex;
        unsigned int numVertices;
        unsigned int offset;
        container adjMatrix;
    };
}
#endif
