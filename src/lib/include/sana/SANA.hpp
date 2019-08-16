#ifndef SANA_H
#define SANA_H

#include <vector>

#include <sana/SANAConfiguration.hpp>
#include <sana/SANAResult.hpp>
#include <sana/Graph.hpp>

class SANA {
public:
    SANA ();
    SANA (const sana::config::SANAConfiguration &);
    SANAResult StartAligner(const std::vector<Graph> &networkList);
private:
    sana::config::SANAConfiguration config;
};

#endif
