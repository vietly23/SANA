#ifndef COMPUTEGRAPHLETS_HPP
#define COMPUTEGRAPHLETS_HPP

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>

namespace computeGraphletsSource {

std::vector<std::vector<uint>> computeGraphlets(int maxGraphletSize, FILE *fp);

}

#endif /* COMPUTEGRAPHLETS_HPP */
