#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <utility>

class GraphInvalidIndexError : public std::exception {
    std::string reason;
public:
    GraphInvalidIndexError(const std::string &message): reason(message) {};
    virtual const char* what() const throw() {
        return reason.c_str();
    }
};

class Graph {
    unsigned int numNodes;
    unsigned int numEdges;
    std::vector<std::vector<unsigned int> > adjLists;
    std::vector<std::string> nodeNames;
    std::string name;
public:
    Graph(){};
    ~Graph(){};

    std::unordered_map<std::string, unsigned short> getNodeNameToIndexMap() const;
    std::unordered_map<unsigned short,std::string> getIndexToNodeNameMap() const;

    virtual void AddEdge(const unsigned int &node1, const unsigned int &node2, const unsigned int &weight);
    virtual void RemoveEdge(const unsigned int &node1, const unsigned int &node2);

    virtual void AddRandomEdge();
    virtual void RemoveRandomEdge();
    virtual int RandomNode();

    unsigned int GetNumNodes() const;
    unsigned int GetNumEdges() const;
    std::string GetName() const;

    virtual void SetNumNodes(const unsigned int &);
    void setName(std::string name);

    std::string GetNodeName(const unsigned int &nodeIndex) const;

    void SetNodeName(const unsigned int &nodeIndex, const std::string &name);
    virtual void ClearGraph();
};


#endif
