#ifndef ITERATEDAMEUR_HPP
#define ITERATEDAMEUR_HPP

#include <vector>

#include "schedulemethods/Ameur.hpp"

using namespace std;

/* applies the method iteratively to converge to a better guess */
class IteratedAmeur : public Ameur {
public:
    IteratedAmeur() =default;

    static constexpr auto NAME = "iterated-ameur";
    string getName() override { return NAME; }

    double computeTempForPBad(double targetPBad, Resources maxRes) override;
    
};

#endif
