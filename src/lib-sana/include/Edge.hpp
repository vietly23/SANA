#ifndef SANA_EDGE
#define SANA_EDGE

template<typename T>
struct Edge {
    const unsigned int sourceVertex;
    const unsigned int targetVertex;
    const T value;

    Edge(unsigned int sourceVertex, unsigned int targetVertex, T value): 
        sourceVertex(sourceVertex), targetVertex(targetVertex), value(value) {};
};
#endif
