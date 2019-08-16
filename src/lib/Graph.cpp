#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <unordered_set>
#include <utility>
#include <sstream>

#include <sana/Graph.hpp>
#include <sana/Utils.hpp>

using namespace std;

std::string Graph::GetName() const {
    return name;
}

void Graph::setName(std::string name) {
    this -> name = name;
}

unsigned int Graph::GetNumNodes() const {
	return numNodes;
}

unsigned int Graph::GetNumEdges() const {
    return numEdges;
}

int Graph::RandomNode() {
    // TODO change this later so its uses a non-static function
    return Utils::RandInt(0, GetNumNodes()-1);
}

void Graph::AddEdge(const unsigned int &node1, const unsigned int &node2, const unsigned int &weight = 1) {
    if (node1 >= numNodes || node2 >= numNodes)
        throw GraphInvalidIndexError("Invalid node index passed into AddEdge");
    if (node1 > node2) {
        if (adjLists[node2][node1] == 0) {
           adjLists[node2].push_back(node1);
        }
    } else {
        adjLists[node1].push_back(node2);
    }
    ++numEdges;  // Either way we iterate the edge count
}

void Graph::RemoveEdge(const unsigned int &node1, const unsigned int &node2) {
    if (node1 >= numNodes || node2 >= numNodes)
        throw GraphInvalidIndexError("Invalid node index passed into RemoveEdge");

    //update adjacency lists
    for (unsigned int i = 0; i < adjLists[node1].size(); i++) {
        if (adjLists[node1][i] == node2) {
            unsigned int lastNeighbor = adjLists[node1][adjLists[node1].size()-1];
            adjLists[node1][i] = lastNeighbor;
            adjLists[node1].pop_back();
            break;
        }
    }
    for (unsigned int i = 0; i < adjLists[node2].size(); i++) {
        if (adjLists[node2][i] == node1) {
            unsigned int lastNeighbor = adjLists[node2][adjLists[node2].size()-1];
            adjLists[node2][i] = lastNeighbor;
            adjLists[node2].pop_back();
            break;
        }
    }
}


void Graph::AddRandomEdge() {
    int node1 = 0, node2 = 0;
    while(node1 == node2 or adjLists[node1][node2]) {
        node1 = RandomNode();
        node2 = RandomNode();
    }
    AddEdge(node1,node2);
}

void Graph::RemoveRandomEdge() {
    int node1 = 0, node2 = 0;
    while(node1 == node2 or adjLists[node1][node2]) {
        node1 = RandomNode();
        node2 = RandomNode();
    }
    RemoveEdge(node1,node2);
}

void Graph::SetNumNodes(const unsigned int &numNodes) {
    adjLists.resize(numNodes);
    nodeNames.resize(numNodes);
}

void Graph::SetNodeName(const unsigned int &nodeIndex, const std::string &name) {
    if (nodeIndex >= numNodes)
        throw GraphInvalidIndexError("Invalid node index passed into SetNodeName");
    nodeNames[nodeIndex] = name;
}

std::string Graph::GetNodeName(const unsigned int &nodeIndex) const {
     if (nodeIndex >= numNodes)
         throw GraphInvalidIndexError("Invalid node index passed into GetNodeName");
     return nodeNames[nodeIndex];
}

void Graph::ClearGraph() {
    adjLists.clear();
    numNodes = numEdges = 0;
}

std::unordered_map<std::string, unsigned short> Graph::getNodeNameToIndexMap() const {
    std::unordered_map<std::string,unsigned short> res;
    for(size_t i = 0; i < GetNumNodes(); ++i) { //Get the number of nodes in the graph
        res[this->GetNodeName(i)] = i; //At that node position, map the name to the number
    }
    return res;
}

std::unordered_map<unsigned short, std::string> Graph::getIndexToNodeNameMap() const {
    std::unordered_map<std::string, unsigned short> reverse = getNodeNameToIndexMap();
    std::unordered_map<unsigned short ,std::string> res;
    for (const auto &nameIndexPair : reverse ) {
        res[nameIndexPair.second] = nameIndexPair.first;
    }
    return res;
}


