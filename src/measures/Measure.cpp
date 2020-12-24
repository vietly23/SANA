#include "measures/Measure.hpp"

#include <string>

Measure::Measure(const Graph* G1, const Graph* G2, const string& name): G1(G1), G2(G2), name(name) {};
Measure::~Measure() {}
string Measure::getName() { return name; }
bool Measure::isLocal() { return false; }
double Measure::balanceWeight() { return 0; }
