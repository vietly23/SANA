#ifndef ADJ_MATRIX
#define ADJ_MATRIX

#include <tuple>
#include <vector>
#include <stdexcept>

#include "Edge.hpp"

namespace sana::detail {
    unsigned int translateVertex(const unsigned int &source, const unsigned int &target) {
        unsigned int row = std::max(source, target);
        unsigned int col = std::min(source, target);
        return row * (row + 1) / 2 + col;
    }

    unsigned int requiredSpace(const unsigned int &numVertices) {
        return numVertices * (numVertices + 1) / 2;
    }

    class AdjMatrixIterator {
    public:
        typedef Edge<bool> edge;
        typedef const std::vector<bool>* container;

        AdjMatrixIterator(container adjMatrix, unsigned int start, 
                unsigned int offset, unsigned int end,  unsigned int size):
            adjMatrix(adjMatrix), start(start), offset(offset), end(end), size(size) {}

        AdjMatrixIterator& operator=(const AdjMatrixIterator& other) {
            adjMatrix = other.adjMatrix;
            start = other.start;
            offset = other.offset;
            end = other.end;
            size = other.size;
            return *this;
        }


        bool hasNext() {
            return start != end;
        }

        edge next() { 
            if (not this->hasNext()) {
                throw std::out_of_range("AdjMatrixIterator::next() : index is out of range");
            }
            while (start < end and not
                    adjMatrix->at(translateVertex(start, offset))) {
                increment();
            }
            unsigned int source = start;
            unsigned int target = increment();
            return edge(source, target, true);
        }

    private:
        unsigned int increment() {
            unsigned int tempValue = offset;
            ++offset;
            if (offset == size) {
                offset = 0;
                start++;
            }
            return tempValue;
        }

        unsigned int start;
        unsigned int end;
        unsigned int offset;
        unsigned int size;
        container adjMatrix;
    };

    /*
     * Assumes that this is an undirected graph.
     * Makes the following assumptions
     * 1) Not thread-safe
     * 2) Assumes false => no edge, true => edge
     */
    class AdjacencyMatrix {
    public:
        void resize(unsigned int numVertices) {
            adjacencyMatrix.resize(requiredSpace(numVertices));
            size = numVertices;
        }
        bool edgeValue(unsigned int source, unsigned int target) {
            return adjacencyMatrix.at(translateVertex(source, target));
        }
        void setEdgeValue(unsigned int source, unsigned int target, bool value) {
            adjacencyMatrix[translateVertex(source, target)] = value;
        }
        AdjMatrixIterator edges(unsigned int source) {
            return AdjMatrixIterator(&adjacencyMatrix, source, 0, source + 1, size);
        }
        void clear() {
            adjacencyMatrix.clear();
        }
    private:
        std::vector<bool> adjacencyMatrix;
        unsigned int size = 0;
    };

}
#endif
