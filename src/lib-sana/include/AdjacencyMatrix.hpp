#ifndef ADJ_MATRIX
#define ADJ_MATRIX

#include <tuple>
#include <vector>
#include <memory>

/*
 * Bare iterator over STL container. Not ideal, but will suffice for now.
 * Assumes that this is an undirected graph.
 */

namespace sana::detail {
    // TODO: Make unit-tests for following cases:
    // translateVertex(0, 0) == 0
    // translateVertex(3, 2) == 8
    // translateVertex(2, 3) == 8
    // translateVertex(1, 1) == 2
    // translateVertex(1, 0) == 1
    class UndirectedAdjacencyMatrix {
    public:
        public void resize(unsigned int numVertices) {
            adjacencyMatrix.resize(requiredSpace(numVertices));
        }
    private:
        std::vector<bool> adjacencyMatrix;
    }
    class AdjMatrixIterator {
    public:
        typedef std::tuple<unsigned int, unsigned int> Edge;
        using iterator_category = std::forward_iterator_tag;
        using value_type = Edge;
        using difference_type = std::ptrdiff_t;
        using pointer = Edge*;
        using reference = value_type;
        AdjMatrixIterator(unsigned int startVertex, unsigned int offset, 
                unsigned int numVertices): startVertex(startVertex), offset(offset), 
                                            numVertices(numVertices) {};

        bool operator==(const AdjMatrixIterator &i) {
            return &i.adjMatrix == &adjMatrix && i.startVertex == startVertex && i.offset == offset;
        }

        bool operator!=(const AdjMatrixIterator &i) {
            return !(*this == i); 
        }

        AdjMatrixIterator operator++() { 
            do {
                ++offset; 
                if (offset >= numVertices) {
                    offset = 0;
                    startVertex++;
                }
            } while (startVertex < numVertices && !adjacencyMatrix[translateVertex(startVertex, offset)]);

            return *this;
        }

        AdjMatrixIterator operator++(int) { 
            auto t = *this; 
            ++off; 
            return t; 
        }

        reference operator*() const { 
            return Edge(startVertex, offset); 
        }
    private:
        unsigned int startVertex;
        unsigned int numVertices;
        unsigned int offset;
        const std::vector<bool>* const adjMatrix;
    }

    // Utility methods for address translation
    unsigned int translateVertex(const unsigned int &source, const unsigned int &target) {
        unsigned int row = std::max(source, target);
        unsigned int col = std::min(source, target);
        return row * (row + 1) / 2 + col;
    }

    unsigned int requiredSpace(const unsigned int &numVertices) {
        return numVertices * (numVertices + 1) / 2;
    }
}
#endif
