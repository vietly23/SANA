#include "schedulemethods/LinearRegressionModern.hpp"

#include <iostream>
#include "spdlog/spdlog.h"
#include "utils/LinearRegression.hpp"

using namespace std;

LinearRegressionModern::LinearRegressionModern():
    ScheduleMethod(), alreadyComputed(false) {}

void LinearRegressionModern::setTargetInitialPBad(double pBad) {
    ScheduleMethod::setTargetInitialPBad(pBad);
    alreadyComputed = false;
}
void LinearRegressionModern::setTargetFinalPBad(double pBad) {
    ScheduleMethod::setTargetFinalPBad(pBad);
    alreadyComputed = false;
}

void LinearRegressionModern::vComputeTInitial(ScheduleMethod::Resources maxRes) {
    if (alreadyComputed) return;
    computeBoth(maxRes); 
    alreadyComputed = true;  
}

void LinearRegressionModern::vComputeTFinal(ScheduleMethod::Resources maxRes) {
    if (alreadyComputed) return;
    computeBoth(maxRes); 
    alreadyComputed = true;  
}

void LinearRegressionModern::computeBoth(ScheduleMethod::Resources maxRes) {
    Timer T; 
    T.start();
    int startSamples = tempToPBad.size();

    spdlog::debug("Populating PBad curve");
    populatePBadCurve();

    int remainingSamples = maxRes.numSamples-(tempToPBad.size()-startSamples);
    ScheduleMethod::Resources remRes(remainingSamples, maxRes.runtime - T.elapsed());
    ScheduleMethod::Resources halfRemRes(remRes.numSamples/2, remRes.runtime/2);

    spdlog::debug("Increasing density near TInitial");
    pBadBinarySearch(targetInitialPBad, halfRemRes);

    remRes.numSamples = maxRes.numSamples-(tempToPBad.size()-startSamples);
    remRes.runtime = maxRes.runtime - T.elapsed();
    spdlog::debug("Increasing density near TFinal");
    pBadBinarySearch(targetFinalPBad, remRes);  

    auto model = LinearRegression::bestFit(tempToPBad);
    spdlog::debug("Linear Regression Model: {}", "TO BE DETERMINED");
//    cout << "*** Linear Regression Model: " << endl;
//    model.print();

    TInitial = tempWithBestLRFit(targetInitialPBad);
    TFinal = tempWithBestLRFit(targetFinalPBad);
}