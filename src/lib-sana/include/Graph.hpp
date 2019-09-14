#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>

template <class EdgeProperty>
class Graph {
public:
    Graph(std::string name): name(name) {};

    virtual void AddEdge(const unsigned int &source, const unsigned int &target, 
            const EdgeProperty &weight) ;
    virtual void RemoveEdge(const unsigned int &source, const unsigned int &target);
    virtual EdgeProperty GetEdgeValue(const unsigned int &source, const unsigned int &target);
    // TODO: Change to use VertexProperty.
    virtual void AddVertex();
    unsigned int GetNumVertices() const;
    unsigned int GetNumEdges() const;
    virtual void ClearGraph();

    std::string GetName() const {
        return name;
    };
    void SetName(const string& name) {
        this->name.assign(name);
    };
private:
    std::string name;
};


#endif
