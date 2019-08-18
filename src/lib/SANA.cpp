#include <vector>
#include <iostream>

#include <sana/SANA.hpp>
#include <sana/Graph.hpp>
#include <sana/SANAResult.hpp>
#include <sana/PairwiseNetPile.hpp>
#include <sana/TemperatureSchedule.hpp>

typedef sana::config::SANAConfiguration SANAConfiguration;

SANA::SANA() {

}

SANA::SANA(const SANAConfiguration &sanaConfig): config(sanaConfig) {

}

SANAResult SANA::StartAligner(const std::vector<Graph> &networkList) {
    std::cout << networkList.size() << std::endl; // TOOD, just dummy print for now
}
