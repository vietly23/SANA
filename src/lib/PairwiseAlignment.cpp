#include <unordered_map>

#include <sana/PairwiseAlignment.hpp>
#include <sana/Graph.hpp>
#include <sana/Utils.hpp>

//Default Constructor and Destructor Already Defined
PairwiseAlignment::PairwiseAlignment(const PairwiseAlignment &rhs) : A(rhs.A) {}

bool PairwiseAlignment::printDefinitionErrors(const Graph &G1, const Graph &G2) {
    unsigned int n1 = G1.GetNumNodes();
    unsigned int n2 = G2.GetNumNodes();
    std::unordered_map<unsigned short, std::string> G1Names = G1.getIndexToNodeNameMap();
    std::unordered_map<unsigned short, std::string> G2Names = G2.getIndexToNodeNameMap();

    std::vector<bool> G2AssignedNodes(n2, false);
    int count = 0;
    if (A.size() != n1) {
        std::cout << "Incorrect size: " << A.size() << ", should be " << n1 << std::endl;
    }
    for (uint i = 0; i < n1; i++) {
        if (A[i] < 0 or A[i] >= n2) {
            std::cout << count <<": node " << i << " (" << G1Names[i] << ") maps to ";
            std::cout << A[i] << ", which is not in range 0..n2 (" << n2 << ")";
            std::cout << std::endl;
            count++;
        }
        if (G2AssignedNodes[A[i]]) {
            std::cout << count << ": node " << i <<" (" << G1Names[i] << ") maps to ";
            std::cout << A[i] << " (" << G2Names[A[i]];
            std::cout << "), which is also mapped to by a previous node" << std::endl;
            count++;
        }
        G2AssignedNodes[A[i]] = true;
    }
    return count > 0;
}
