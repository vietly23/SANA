#include "methods/Method.hpp"

#include <cassert>
#include <string>

Method::Method(const Graph* G1, const Graph* G2, std::string name): G1(G1), G2(G2), name(name) {};
Method::~Method() {
    // cerr<<"in Method base destructor"<<endl;
}
std::string Method::getName() const { return name; }
double Method::getExecTime() const { return execTime; }

Alignment Method::runAndPrintTime() {
    std::cout << "Start execution of " << name << std::endl;
    Timer T;
    T.start();
    Alignment A = run();
    execTime = T.elapsed();
    std::cout << "Executed " << name << " in " << T.elapsedString() << std::endl;
    return A;
}


