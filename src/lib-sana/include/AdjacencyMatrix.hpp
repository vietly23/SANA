#ifndef ADJ_MATRIX
#define ADJ_MATRIX

#include <tuple>
#include <vector>
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
        using reference = Edge&;
        AdjMatrixIterator(unsigned int startVertex, unsigned int offset, 
                unsigned int numVertices): startVertex(startVertex), offset(offset), 
                                            numVertices(numVertices) {};
        bool operator==(const AdjMatrixIterator &i) {
            return &i.adjMatrix == &adjMatrix && i.startVertex == startVertex;
        }
        bool operator!=(const AdjMatrixIterator &i) {
            return !(*this == i); 
        }
        AdjMatrixIterator operator++() { 
            ++offset; 
            if (offset >= numVertices) {
                offset = 0;
                startVertex++;
            }
            return *this;
        }
        AdjMatrixIterator operator++(int) { 
            auto t = *this; 
            ++off; 
            return t; 
        }
        reference operator*() const { return buf[off % Capacity]; }
        pointer operator->() const { return buf[off % Capacity]; }
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
    /*
RingIter(T *buf, std::size_t offset)
: buf(buf), off(offset)
{}
bool operator!=(const RingIter &i) {
return !(*this == i);
}
RingIter & operator++()    { ++off; return *this; }
RingIter operator++(int) { auto t = *this; ++off; return t; }
RingIter & operator--()    { --off; return *this; }
RingIter operator--(int) { auto t = *this; --off; return t; }
std::ptrdiff_t operator-(RingIter const& sibling) const { return off - sibling.off; }
RingIter & operator+=(int amount) { off += amount; return *this; }
RingIter & operator-=(int amount) { off -= amount; return *this; }
bool operator<(RingIter const&sibling) const { return off < sibling.off;}
bool operator<=(RingIter const&sibling) const { return off <= sibling.off; }
bool operator>(RingIter const&sibling) const { return off > sibling.off; }
bool operator>=(RingIter const&sibling) const { return off >= sibling.off; }
T& operator[](int index) const { return *(*this + index); }
T& operator*() const { return buf[off % Capacity]; }
}; 
*/
}
#endif
