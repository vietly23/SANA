#include "SanaMode.hpp"

#include <cmath>

#include "spdlog/spdlog.h"

#include "schedulemethods/ScheduleMethod.hpp"
#include "schedulemethods/LinearRegressionModern.hpp"
#include "temperature/TemperatureSchedule.hpp"


//const ScheduleMethod::Resources RESOURCE{60, 200.0};
//// local functions for convenience - may refactor out to other parts when necessary
//using sana::TemperatureSchedule;
//
//struct InitialTemperatureSettings {
//    InitialTemperatureSettings(double initialTemp, double temperatureDecay): initialTemp(initialTemp),
//    temperatureDecay(temperatureDecay) {};
//    double initialTemp;
//    double temperatureDecay;
//};
//
//InitialTemperatureSettings determineTemperatureSettings(const sana::Configuration &configuration) {
//    // FOR NOW ALWAYS COMPUTE initialTemp and temperatureDecay
//    LinearRegressionModern m;
//
//    auto initialTemp = m.computeTInitial(RESOURCE);
//    auto finalTemp = m.computeTFinal(RESOURCE);
//    auto decayTemp = -(log(finalTemp) - log(initialTemp));
//    return InitialTemperatureSettings(initialTemp, decayTemp);
//}
//
//std::unique_ptr<TemperatureSchedule> selectTemperatureSchedule(const sana::Configuration& config) {
//    std::string temperatureScheduleType = config.getValue(sana::StringConfig("schedule.type"), "linear");
//    InitialTemperatureSettings initTemp = determineTemperatureSettings(config);
//    TemperatureSchedule* t;
//    /*
//     * TODO: Is this really necessary? To have different schedule types based on iteration/time? Might be better to have
//     * one singular schedule that takes the max of the iteration/time... something similar to the dynamic? But don't
//     * really understand that one either.
//     */
//    if (temperatureScheduleType == "linear") {
//        auto iterationConfig = config.getValue(sana::LongLongConfig("schedule.maxIterations"));
//        if (iterationConfig.has_value()) {
//            t = new sana::IterationSchedule(initTemp.initialTemp, initTemp.temperatureDecay, iterationConfig.value());
//        } else {
//            long long maxIterations = config.getValue(sana::LongLongConfig("schedule.maxTime"), 10000);
//            t = new sana::TimeSchedule(initTemp.initialTemp, initTemp.temperatureDecay, maxIterations);
//        }
//    } else {
//        t = new sana::ConstantSchedule(initTemp.initialTemp, initTemp.temperatureDecay);
//    }
//    return std::unique_ptr<TemperatureSchedule>(t);
//}
//
//sana::SanaMode::SanaMode(sana::Configuration config) : Mode(std::move(config)) {
//}
//
//void sana::SanaMode::run() {
//    spdlog::debug("Initializing run");
//    std::unique_ptr<TemperatureSchedule> schedule = selectTemperatureSchedule(config);
//    spdlog::info("Starting run");
//    // Load graphs
//    // load measures
//    //    initDataStructures();
//    //
//    //#ifndef MULTI_PAIRWISE
//    //    getIterPerSecond(); // this takes several seconds of CPU time; don't do it during multi-only-iterations.
//    //#endif
//    //    long long int maxIters = useIterations ? maxIterations
//    //                                           : (long long int) (getIterPerSecond()*maxSeconds);
//    //    double leeway = 2;
//    //    double maxSecondsWithLeeway = maxSeconds * leeway;
//    //
//    //    long long int iter;
//    //    for (iter = 0; iter <= maxIters; iter++) {
//    //        Temperature = temperatureFunction(iter, TInitial, TDecay);
//    //        SANAIteration();
//    //        if (iter%iterationsPerStep == 0) {
//    //            trackProgress(iter, maxIters);
//    //            if (not useIterations and timer.elapsed() > maxSecondsWithLeeway
//    //                and currentScore-previousScore < 0.005) break;
//    //            previousScore = currentScore;
//    //        }
//    //    }
//    //    trackProgress(iter, maxIters);
//    //    cout<<"Performed "<<iter<<" total iterations\n";
//    //
//    //
//    //    return A;
//    spdlog::info("Finished run");
//}

//void SANA::SANAIteration() {
//    ++iterationsPerformed;
//    uint actColId = randActiveColorIdWeightedByNumNbrs();
//    double p = randomReal(gen);
//    if (p < actColToChangeProb[actColId]) {
//        performChange(actColId);
//    } else {
//        performSwap(actColId);
//    }
//}
//

//void SANA::performChange(uint actColId) {
//    uint source = randomG1NodeWithActiveColor(actColId);
//    uint oldTarget = A[source];
//    uint numUnassigWithCol = actColToUnassignedG2Nodes[actColId].size();
//    uint unassignedVecIndex = randInt(0, numUnassigWithCol-1);
//    uint newTarget = actColToUnassignedG2Nodes[actColId][unassignedVecIndex];
//
//    assert(numUnassigWithCol > 0);
//    assert(oldTarget != newTarget);
//    // assert(G1->getColorName(G1->getNodeColor(source)) == G2->getColorName(G2->getNodeColor(oldTarget)));
//    // assert(G2->getNodeColor(newTarget) == G2->getNodeColor(oldTarget));
//
//    //added this dummy initialization to shut compiler warning -Nil
//    unsigned oldOldTargetDeg = 0, oldNewTargetDeg = 0, oldMs3Denom = 0, oldMs3Numer =0;
//
//    if (needMS3) {
//        oldOldTargetDeg = MultiS3::shadowDegree[oldTarget];
//        oldNewTargetDeg = MultiS3::shadowDegree[newTarget];
//        oldMs3Denom = MultiS3::denom;
//        oldMs3Numer = MultiS3::numer;
//    }
//    int newAligEdges           = (needAligEdges or needSec) ? aligEdges + aligEdgesIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newEdSum            = needEd ? edSum + edgeDifferenceIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newErSum            = needEr ? erSum + edgeRatioIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newSquaredAligEdges = needSquaredAligEdges ? squaredAligEdges + squaredAligEdgesIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newExposedEdgesNumer= needExposedEdges ? EdgeExposure::numer + exposedEdgesIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newMS3Numer         = needMS3 ? MultiS3::numer + MS3IncChangeOp(source, oldTarget, newTarget) : -1;
//    int newInducedEdges        = needInducedEdges ? inducedEdges + inducedEdgesIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newLocalScoreSum    = needLocal ? localScoreSum + localScoreSumIncChangeOp(sims, source, oldTarget, newTarget) : -1;
//    double newWecSum           = needWec ? wecSum + WECIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newJsSum            = needJs ? jsSum + JSIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newEwecSum          = needEwec ? ewecSum + EWECIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newNcSum            = needNC ? ncSum + ncIncChangeOp(source, oldTarget, newTarget) : -1;
//
//    map<string, double> newLocalScoreSumMap;
//    if (needLocal) {
//        newLocalScoreSumMap = map<string, double>(localScoreSumMap);
//        for (auto &item : newLocalScoreSumMap)
//            item.second += localScoreSumIncChangeOp(localSimMatrixMap[item.first], source, oldTarget, newTarget);
//    }
//
//    double newCurrentScore = 0;
//    double pBad = scoreComparison(newAligEdges, newInducedEdges,
//            newLocalScoreSum, newWecSum, newJsSum, newNcSum, newCurrentScore, newEwecSum,
//            newSquaredAligEdges, newExposedEdgesNumer, newMS3Numer, newEdSum, newErSum);
//    bool makeChange = randomReal(gen) <= pBad;
//
//#ifdef CORES
//    // Statistics on the emerging core alignment.
//    // only update pBad if is nonzero; reuse previous nonzero pBad if the current one is zero.
//    uint betterHole = wasBadMove ? oldTarget : newTarget;
//
//    double meanPBad = incrementalMeanPBad(); // maybe we should use the *actual* pBad of *this* move?
//    if (meanPBad <= 0 || myNan(meanPBad)) meanPBad = LOW_PBAD_LIMIT_FOR_CORES;
//
//    coreScoreData.incChangeOp(source, betterHole, pBad, meanPBad);
//#endif
//
//    if (makeChange) {
//        A[source] = newTarget;
//        actColToUnassignedG2Nodes[actColId][unassignedVecIndex] = oldTarget;
//        assignedNodesG2[oldTarget] = false;
//        assignedNodesG2[newTarget] = true;
//        aligEdges                     = newAligEdges;
//        edSum                         = newEdSum;
//        erSum                         = newErSum;
//        inducedEdges                  = newInducedEdges;
//        localScoreSum                 = newLocalScoreSum;
//        wecSum                        = newWecSum;
//        ewecSum                       = newEwecSum;
//        ncSum                         = newNcSum;
//        if (needLocal) localScoreSumMap = newLocalScoreSumMap;
//        currentScore                  = newCurrentScore;
//        EdgeExposure::numer           = newExposedEdgesNumer;
//        squaredAligEdges              = newSquaredAligEdges;
//        MultiS3::numer                = newMS3Numer;
//    }
//    else if (needMS3) {
//        MultiS3::shadowDegree[oldTarget] = oldOldTargetDeg;
//        MultiS3::shadowDegree[newTarget] = oldNewTargetDeg;
//        MultiS3::denom = oldMs3Denom;
//        MultiS3::numer = oldMs3Numer;
//    }
//}
//
//void SANA::performSwap(uint actColId) {
//    uint source1 = randomG1NodeWithActiveColor(actColId);
//
//    uint source2;
//    for (uint i = 0; i < 100; i++) { //each attempt has >=50% chance of success
//        source2 = randomG1NodeWithActiveColor(actColId);
//        if (source1 != source2) break;
//    }
//
//    uint target1 = A[source1], target2 = A[source2];
//
//    assert(source1 != source2);
//    assert(target1 != target2);
//    // assert(G1->getNodeColor(source1) == G1->getNodeColor(source2));
//    // assert(G2->getNodeColor(target1) == G2->getNodeColor(target2));
//    // assert(G1->getColorName(G1->getNodeColor(source1)) == G2->getColorName(G2->getNodeColor(target1)));
//
//    //added this dummy initialization to shut compiler warning -Nil
//    unsigned oldTarget1Deg = 0, oldTarget2Deg = 0, oldMs3Denom = 0;
//
//    if (needMS3) {
//        oldTarget1Deg = MultiS3::shadowDegree[target1];
//        oldTarget2Deg = MultiS3::shadowDegree[target2];
//        oldMs3Denom = MultiS3::denom;
//    }
//
//    int newAligEdges           = (needAligEdges or needSec) ? aligEdges + aligEdgesIncSwapOp(source1, source2, target1, target2) : -1;
//    double newSquaredAligEdges = needSquaredAligEdges ? squaredAligEdges + squaredAligEdgesIncSwapOp(source1, source2, target1, target2) : -1;
//    double newExposedEdgesNumer= needExposedEdges ? EdgeExposure::numer + exposedEdgesIncSwapOp(source1, source2, target1, target2) : -1;
//    double newMS3Numer         = needMS3 ? MultiS3::numer + MS3IncSwapOp(source1, source2, target1, target2) : -1;
//    double newWecSum           = needWec ? wecSum + WECIncSwapOp(source1, source2, target1, target2) : -1;
//    double newJsSum            = needJs ? jsSum + JSIncSwapOp(source1, source2, target1, target2) : -1;
//    double newEwecSum          = needEwec ? ewecSum + EWECIncSwapOp(source1, source2, target1, target2) : -1;
//    double newNcSum            = needNC ? ncSum + ncIncSwapOp(source1, source2, target1, target2) : -1;
//    double newLocalScoreSum    = needLocal ? localScoreSum + localScoreSumIncSwapOp(sims, source1, source2, target1, target2) : -1;
//    double newEdSum            = needEd ? edSum + edgeDifferenceIncSwapOp(source1, source2, target1, target2) : -1;
//    double newErSum            = needEr ? erSum + edgeRatioIncSwapOp(source1, source2, target1, target2) : -1;
//
//    map<string, double> newLocalScoreSumMap;
//    if (needLocal) {
//        newLocalScoreSumMap = map<string, double>(localScoreSumMap);
//        for (auto &item : newLocalScoreSumMap)
//            item.second += localScoreSumIncSwapOp(localSimMatrixMap[item.first], source1, source2, target1, target2);
//    }
//
//    double newCurrentScore = 0;
//    double pBad = scoreComparison(newAligEdges, inducedEdges, newLocalScoreSum,
//            newWecSum, newJsSum, newNcSum, newCurrentScore, newEwecSum, newSquaredAligEdges,
//            newExposedEdgesNumer, newMS3Numer, newEdSum, newErSum);
//    bool makeChange = randomReal(gen) <= pBad;
//
//#ifdef CORES
//    // Statistics on the emerging core alignment.
//        // only update pBad if it's nonzero; reuse previous nonzero pBad if the current one is zero.
//        double meanPBad = incrementalMeanPBad(); // maybe we should use the *actual* pBad of *this* move?
//        if (meanPBad <= 0 || myNan(meanPBad)) meanPBad = LOW_PBAD_LIMIT_FOR_CORES;
//
//        uint betterDest1 = wasBadMove ? target1 : target2;
//        uint betterDest2 = wasBadMove ? target2 : target1;
//
//        coreScoreData.incSwapOp(source1, source2, betterDest1, betterDest2, pBad, meanPBad);
//#endif
//
//    if (makeChange) {
//        A[source1]          = target2;
//        A[source2]          = target1;
//        aligEdges           = newAligEdges;
//        edSum               = newEdSum;
//        erSum               = newErSum;
//        localScoreSum       = newLocalScoreSum;
//        wecSum              = newWecSum;
//        ewecSum             = newEwecSum;
//        ncSum               = newNcSum;
//        currentScore        = newCurrentScore;
//        squaredAligEdges    = newSquaredAligEdges;
//        EdgeExposure::numer = newExposedEdgesNumer;
//        MultiS3::numer      = newMS3Numer;
//        if (needLocal) localScoreSumMap = newLocalScoreSumMap;
//    } else if (needMS3) {
//        MultiS3::shadowDegree[target1] = oldTarget1Deg;
//        MultiS3::shadowDegree[target2] = oldTarget2Deg;
//        MultiS3::denom = oldMs3Denom;
//    }
//}
////initialize data structures specific to the starting alignment
////everything that is alignment-independent should be initialized in the
////constructor instead
////even for data structures initialized here, any space allocation for them
////should be done in the constructor, not here, to avoid memory leaks
//void SANA::initDataStructures() {
//    iterationsPerformed = 0;
//    numPBadsInBuffer = pBadBufferSum = pBadBufferIndex = 0;
//    Alignment alig;
//    if (startA.size() != 0) alig = startA;
//    else alig = Alignment::randomColorRestrictedAlignment(*G1, *G2);
//
//    //initialize assignedNodesG2 (the size was already set in the constructor)
//    for (uint i = 0; i < n2; i++) assignedNodesG2[i] = false;
//    for (uint i = 0; i < n1; i++) assignedNodesG2[alig[i]] = true;
//    //initialize actColToUnassignedG2Nodes (the size was already set in the constructor)
//    for (uint i = 0; i < actColToUnassignedG2Nodes.size(); i++)
//        actColToUnassignedG2Nodes[i].clear();
//    for (uint g2Node = 0; g2Node < n2; g2Node++) {
//        if (assignedNodesG2[g2Node]) continue;
//        uint actColId = g2NodeToActColId[g2Node];
//        if (actColId != INVALID_ACTIVE_COLOR_ID) {
//            actColToUnassignedG2Nodes[actColId].push_back(g2Node);
//        }
//    }
//
//    if (needAligEdges or needSec) aligEdges = alig.numAlignedEdges(*G1, *G2);
//    if (needEd) edSum = EdgeDifference::getEdgeDifferenceSum(G1, G2, alig);
//    if (needEr) erSum = EdgeRatio::getEdgeRatioSum(G1, G2, alig);
//    currentScore = eval(alig);
//    A = alig.asVector();
//    timer.start();
//}
//
//Alignment SANA::run() {
//    initDataStructures();
//    setInterruptSignal();
//
//#ifndef MULTI_PAIRWISE
//    getIterPerSecond(); // this takes several seconds of CPU time; don't do it during multi-only-iterations.
//#endif
//    long long int maxIters = useIterations ? maxIterations
//                                           : (long long int) (getIterPerSecond()*maxSeconds);
//    double leeway = 2;
//    double maxSecondsWithLeeway = maxSeconds * leeway;
//
//    long long int iter;
//    for (iter = 0; iter <= maxIters; iter++) {
//        Temperature = temperatureFunction(iter, TInitial, TDecay);
//        SANAIteration();
//        if (saveAligAndExitOnInterruption) break;
//        if (saveAligAndContOnInterruption) printReportOnInterruption();
//        if (iter%iterationsPerStep == 0) {
//            trackProgress(iter, maxIters);
//            if (not useIterations and timer.elapsed() > maxSecondsWithLeeway
//                and currentScore-previousScore < 0.005) break;
//            previousScore = currentScore;
//        }
//    }
//    trackProgress(iter, maxIters);
//    cout<<"Performed "<<iter<<" total iterations\n";
//    if (addHillClimbing) performHillClimbing(10000000LL); //arbitrarily chosen, probably too big.
//
//#ifdef CORES
//    Report::saveCoreScore(*G1, *G2, A, this, coreScoreData, outputFileName);
//#endif
//
//    return A;
//}
//
//void SANA::performHillClimbing(long long int idleCountTarget) {
//    long long int iter = 0;
//    Temperature = 0;
//    numPBadsInBuffer = pBadBufferSum = pBadBufferIndex = 0;
//
//    cout << "Beginning Final Pure Hill Climbing Stage" << endl;
//    Timer T;
//    T.start();
//    uint idleCount = 0;
//    while(idleCount < idleCountTarget) {
//        if (iter%iterationsPerStep == 0) trackProgress(iter);
//        double oldScore = currentScore;
//        SANAIteration();
//        if (abs(oldScore-currentScore) < 0.00001) ++idleCount;
//        else idleCount = 0;
//        ++iter;
//    }
//    trackProgress(iter);
//    cout<<"Hill climbing took "<<T.elapsedString()<<"s"<<endl;
//}
//
//double SANA::temperatureFunction(long long int iter, double TInitial, double TDecay) {
//    if (constantTemp) return TInitial;
//    double fraction;
//    if (useIterations) fraction = iter / (double) maxIterations;
//    else fraction = iter / (maxSeconds * getIterPerSecond());
//    return TInitial * exp(-TDecay * fraction);
//}
//
//double SANA::acceptingProbability(double energyInc, double Temperature) {
//    return energyInc >= 0 ? 1 : exp(energyInc/Temperature);
//}
//
//double SANA::incrementalMeanPBad() {
//    return pBadBufferSum/(double) numPBadsInBuffer;
//}
//
//double SANA::slowMeanPBad() {
//    double sum = 0;
//    for (int i = 0; i < numPBadsInBuffer; i++) sum += pBadBuffer[i];
//    return sum/(double) numPBadsInBuffer;
//}
//
//double SANA::eval(const Alignment& Al) const { return MC->eval(Al); }
//
//void sigIntHandler(int s) {
//    string line;
//    int c = -1;
//    do {
//        cout<<"Select an option (0 - 3):"<<endl<<"  (0) Do nothing and continue"<<endl<<"  (1) Exit"<<endl
//            <<"  (2) Save Alignment and Exit"<<endl<<"  (3) Save Alignment and Continue"<<endl<<">> ";
//        cin >> c;
//        if (cin.eof()) exit(0);
//        if (cin.fail()) {
//            c = -1;
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        }
//        if      (c == 0) cout<<"Continuing..."<<endl;
//        else if (c == 1) exit(0);
//        else if (c == 2) SANA::saveAligAndExitOnInterruption = true;
//        else if (c == 3) SANA::saveAligAndContOnInterruption = true;
//    } while (c < 0 || c > 3);
//}
//
//void SANA::setInterruptSignal() {
//    saveAligAndExitOnInterruption = false;
//    struct sigaction sigInt;
//    sigInt.sa_handler = sigIntHandler;
//    sigemptyset(&sigInt.sa_mask);
//    sigInt.sa_flags = 0;
//    sigaction(SIGINT, &sigInt, NULL);
//}
//
//void SANA::printReportOnInterruption() {
//    saveAligAndContOnInterruption = false; //reset value
//    string timestamp = string(currentDateTime()); //necessary to make it not const
//    std::replace(timestamp.begin(), timestamp.end(), ' ', '_');
//    string outFile = outputFileName+"_"+timestamp;
//    string localFile = localScoresFileName+"_"+timestamp;
//    Report::saveReport(*G1, *G2, A, *MC, this, outFile, true);
//    Report::saveLocalMeasures(*G1, *G2, A, *MC, this, localFile);
//#ifdef CORES
//    Report::saveCoreScore(*G1, *G2, A, this, coreScoreData, outputFileName);
//#endif
//    cout << "Alignment saved. SANA will now continue." << endl;
//}
//
//void SANA::SANAIteration() {
//    ++iterationsPerformed;
//    uint actColId = randActiveColorIdWeightedByNumNbrs();
//    double p = randomReal(gen);
//    if (p < actColToChangeProb[actColId]) {
//        performChange(actColId);
//    } else {
//        performSwap(actColId);
//    }
//}
//
//uint SANA::numActiveColors() const {
//    return actColToChangeProb.size();
//}
//
//uint SANA::randActiveColorIdWeightedByNumNbrs() {
//    if (numActiveColors() == 1) return 0; //optimized special case: monochromatic graphs
//    double p = randomReal(gen);
//    if (numActiveColors() == 2) //optimized special case: bichromatic graphs
//        return (p < actColToAccumProbCutpoint[0] ? 0 : 1);
//
//    //general case: use binary search to optimizie for the case with many active colors
//    auto iter = lower_bound(actColToAccumProbCutpoint.begin(), actColToAccumProbCutpoint.end(), p);
//    assert(iter != actColToAccumProbCutpoint.end());
//    return iter - actColToAccumProbCutpoint.begin();
//}
//
//uint SANA::randomG1NodeWithActiveColor(uint actColId) const {
//    uint g1ColId = actColToG1ColId[actColId];
//    uint randIndex = randInt(0, G1->nodeGroupsByColor[g1ColId].size()-1);
//    return G1->nodeGroupsByColor[g1ColId][randIndex];
//}
//
//void SANA::performChange(uint actColId) {
//    uint source = randomG1NodeWithActiveColor(actColId);
//    uint oldTarget = A[source];
//    uint numUnassigWithCol = actColToUnassignedG2Nodes[actColId].size();
//    uint unassignedVecIndex = randInt(0, numUnassigWithCol-1);
//    uint newTarget = actColToUnassignedG2Nodes[actColId][unassignedVecIndex];
//
//    assert(numUnassigWithCol > 0);
//    assert(oldTarget != newTarget);
//    // assert(G1->getColorName(G1->getNodeColor(source)) == G2->getColorName(G2->getNodeColor(oldTarget)));
//    // assert(G2->getNodeColor(newTarget) == G2->getNodeColor(oldTarget));
//
//    //added this dummy initialization to shut compiler warning -Nil
//    unsigned oldOldTargetDeg = 0, oldNewTargetDeg = 0, oldMs3Denom = 0, oldMs3Numer =0;
//
//    if (needMS3) {
//        oldOldTargetDeg = MultiS3::shadowDegree[oldTarget];
//        oldNewTargetDeg = MultiS3::shadowDegree[newTarget];
//        oldMs3Denom = MultiS3::denom;
//        oldMs3Numer = MultiS3::numer;
//    }
//    int newAligEdges           = (needAligEdges or needSec) ? aligEdges + aligEdgesIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newEdSum            = needEd ? edSum + edgeDifferenceIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newErSum            = needEr ? erSum + edgeRatioIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newSquaredAligEdges = needSquaredAligEdges ? squaredAligEdges + squaredAligEdgesIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newExposedEdgesNumer= needExposedEdges ? EdgeExposure::numer + exposedEdgesIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newMS3Numer         = needMS3 ? MultiS3::numer + MS3IncChangeOp(source, oldTarget, newTarget) : -1;
//    int newInducedEdges        = needInducedEdges ? inducedEdges + inducedEdgesIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newLocalScoreSum    = needLocal ? localScoreSum + localScoreSumIncChangeOp(sims, source, oldTarget, newTarget) : -1;
//    double newWecSum           = needWec ? wecSum + WECIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newJsSum            = needJs ? jsSum + JSIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newEwecSum          = needEwec ? ewecSum + EWECIncChangeOp(source, oldTarget, newTarget) : -1;
//    double newNcSum            = needNC ? ncSum + ncIncChangeOp(source, oldTarget, newTarget) : -1;
//
//    map<string, double> newLocalScoreSumMap;
//    if (needLocal) {
//        newLocalScoreSumMap = map<string, double>(localScoreSumMap);
//        for (auto &item : newLocalScoreSumMap)
//            item.second += localScoreSumIncChangeOp(localSimMatrixMap[item.first], source, oldTarget, newTarget);
//    }
//
//    double newCurrentScore = 0;
//    double pBad = scoreComparison(newAligEdges, newInducedEdges,
//            newLocalScoreSum, newWecSum, newJsSum, newNcSum, newCurrentScore, newEwecSum,
//            newSquaredAligEdges, newExposedEdgesNumer, newMS3Numer, newEdSum, newErSum);
//    bool makeChange = randomReal(gen) <= pBad;
//
//#ifdef CORES
//    // Statistics on the emerging core alignment.
//    // only update pBad if is nonzero; reuse previous nonzero pBad if the current one is zero.
//    uint betterHole = wasBadMove ? oldTarget : newTarget;
//
//    double meanPBad = incrementalMeanPBad(); // maybe we should use the *actual* pBad of *this* move?
//    if (meanPBad <= 0 || myNan(meanPBad)) meanPBad = LOW_PBAD_LIMIT_FOR_CORES;
//
//    coreScoreData.incChangeOp(source, betterHole, pBad, meanPBad);
//#endif
//
//    if (makeChange) {
//        A[source] = newTarget;
//        actColToUnassignedG2Nodes[actColId][unassignedVecIndex] = oldTarget;
//        assignedNodesG2[oldTarget] = false;
//        assignedNodesG2[newTarget] = true;
//        aligEdges                     = newAligEdges;
//        edSum                         = newEdSum;
//        erSum                         = newErSum;
//        inducedEdges                  = newInducedEdges;
//        localScoreSum                 = newLocalScoreSum;
//        wecSum                        = newWecSum;
//        ewecSum                       = newEwecSum;
//        ncSum                         = newNcSum;
//        if (needLocal) localScoreSumMap = newLocalScoreSumMap;
//        currentScore                  = newCurrentScore;
//        EdgeExposure::numer           = newExposedEdgesNumer;
//        squaredAligEdges              = newSquaredAligEdges;
//        MultiS3::numer                = newMS3Numer;
//    }
//    else if (needMS3) {
//        MultiS3::shadowDegree[oldTarget] = oldOldTargetDeg;
//        MultiS3::shadowDegree[newTarget] = oldNewTargetDeg;
//        MultiS3::denom = oldMs3Denom;
//        MultiS3::numer = oldMs3Numer;
//    }
//}
//
//void SANA::performSwap(uint actColId) {
//    uint source1 = randomG1NodeWithActiveColor(actColId);
//
//    uint source2;
//    for (uint i = 0; i < 100; i++) { //each attempt has >=50% chance of success
//        source2 = randomG1NodeWithActiveColor(actColId);
//        if (source1 != source2) break;
//    }
//
//    uint target1 = A[source1], target2 = A[source2];
//
//    assert(source1 != source2);
//    assert(target1 != target2);
//    // assert(G1->getNodeColor(source1) == G1->getNodeColor(source2));
//    // assert(G2->getNodeColor(target1) == G2->getNodeColor(target2));
//    // assert(G1->getColorName(G1->getNodeColor(source1)) == G2->getColorName(G2->getNodeColor(target1)));
//
//    //added this dummy initialization to shut compiler warning -Nil
//    unsigned oldTarget1Deg = 0, oldTarget2Deg = 0, oldMs3Denom = 0;
//
//    if (needMS3) {
//        oldTarget1Deg = MultiS3::shadowDegree[target1];
//        oldTarget2Deg = MultiS3::shadowDegree[target2];
//        oldMs3Denom = MultiS3::denom;
//    }
//
//    int newAligEdges           = (needAligEdges or needSec) ? aligEdges + aligEdgesIncSwapOp(source1, source2, target1, target2) : -1;
//    double newSquaredAligEdges = needSquaredAligEdges ? squaredAligEdges + squaredAligEdgesIncSwapOp(source1, source2, target1, target2) : -1;
//    double newExposedEdgesNumer= needExposedEdges ? EdgeExposure::numer + exposedEdgesIncSwapOp(source1, source2, target1, target2) : -1;
//    double newMS3Numer         = needMS3 ? MultiS3::numer + MS3IncSwapOp(source1, source2, target1, target2) : -1;
//    double newWecSum           = needWec ? wecSum + WECIncSwapOp(source1, source2, target1, target2) : -1;
//    double newJsSum            = needJs ? jsSum + JSIncSwapOp(source1, source2, target1, target2) : -1;
//    double newEwecSum          = needEwec ? ewecSum + EWECIncSwapOp(source1, source2, target1, target2) : -1;
//    double newNcSum            = needNC ? ncSum + ncIncSwapOp(source1, source2, target1, target2) : -1;
//    double newLocalScoreSum    = needLocal ? localScoreSum + localScoreSumIncSwapOp(sims, source1, source2, target1, target2) : -1;
//    double newEdSum            = needEd ? edSum + edgeDifferenceIncSwapOp(source1, source2, target1, target2) : -1;
//    double newErSum            = needEr ? erSum + edgeRatioIncSwapOp(source1, source2, target1, target2) : -1;
//
//    map<string, double> newLocalScoreSumMap;
//    if (needLocal) {
//        newLocalScoreSumMap = map<string, double>(localScoreSumMap);
//        for (auto &item : newLocalScoreSumMap)
//            item.second += localScoreSumIncSwapOp(localSimMatrixMap[item.first], source1, source2, target1, target2);
//    }
//
//    double newCurrentScore = 0;
//    double pBad = scoreComparison(newAligEdges, inducedEdges, newLocalScoreSum,
//            newWecSum, newJsSum, newNcSum, newCurrentScore, newEwecSum, newSquaredAligEdges,
//            newExposedEdgesNumer, newMS3Numer, newEdSum, newErSum);
//    bool makeChange = randomReal(gen) <= pBad;
//
//#ifdef CORES
//    // Statistics on the emerging core alignment.
//        // only update pBad if it's nonzero; reuse previous nonzero pBad if the current one is zero.
//        double meanPBad = incrementalMeanPBad(); // maybe we should use the *actual* pBad of *this* move?
//        if (meanPBad <= 0 || myNan(meanPBad)) meanPBad = LOW_PBAD_LIMIT_FOR_CORES;
//
//        uint betterDest1 = wasBadMove ? target1 : target2;
//        uint betterDest2 = wasBadMove ? target2 : target1;
//
//        coreScoreData.incSwapOp(source1, source2, betterDest1, betterDest2, pBad, meanPBad);
//#endif
//
//    if (makeChange) {
//        A[source1]          = target2;
//        A[source2]          = target1;
//        aligEdges           = newAligEdges;
//        edSum               = newEdSum;
//        erSum               = newErSum;
//        localScoreSum       = newLocalScoreSum;
//        wecSum              = newWecSum;
//        ewecSum             = newEwecSum;
//        ncSum               = newNcSum;
//        currentScore        = newCurrentScore;
//        squaredAligEdges    = newSquaredAligEdges;
//        EdgeExposure::numer = newExposedEdgesNumer;
//        MultiS3::numer      = newMS3Numer;
//        if (needLocal) localScoreSumMap = newLocalScoreSumMap;
//    } else if (needMS3) {
//        MultiS3::shadowDegree[target1] = oldTarget1Deg;
//        MultiS3::shadowDegree[target2] = oldTarget2Deg;
//        MultiS3::denom = oldMs3Denom;
//    }
//}
//
//// returns pBad
//double SANA::scoreComparison(double newAligEdges, double newInducedEdges,
//        double newLocalScoreSum, double newWecSum, double newJsSum, double newNcSum, double& newCurrentScore,
//        double newEwecSum, double newSquaredAligEdges, double newExposedEdgesNumer, double newMS3Numer,
//        double newEdgeDifferenceSum, double newEdgeRatioSum) {
//    wasBadMove = false;
//    double pBad = 0;
//
//    switch (scoreAggr) {
//        case ScoreAggregation::sum:
//        {
//            newCurrentScore += ecWeight * (newAligEdges / g1Edges);
//            newCurrentScore += edWeight * EdgeDifference::adjustSumToTargetScore(newEdgeDifferenceSum, pairsCount);
//            newCurrentScore += erWeight * EdgeRatio::adjustSumToTargetScore(newEdgeRatioSum, pairsCount);
//            newCurrentScore += s3Weight * (newAligEdges / (g1Edges + newInducedEdges - newAligEdges));
//            newCurrentScore += icsWeight * (newAligEdges / newInducedEdges);
//            newCurrentScore += secWeight * (newAligEdges / g1Edges + newAligEdges / g2Edges)*0.5;
//            newCurrentScore += localWeight * (newLocalScoreSum / n1);
//            newCurrentScore += wecWeight * (newWecSum / (2 * g1Edges));
//            newCurrentScore += jsWeight * (newJsSum);
//            newCurrentScore += ewecWeight * (newEwecSum);
//            newCurrentScore += ncWeight * (newNcSum / trueAWithValidCountAppended.back());
//#ifdef MULTI_PAIRWISE
//            newCurrentScore += mecWeight * (newAligEdges / (g1WeightedEdges + g2WeightedEdges));
//        newCurrentScore += sesWeight * newSquaredAligEdges / (double)SquaredEdgeScore::getDenom();
//        newCurrentScore += eeWeight * (1 - (newExposedEdgesNumer / (double)EdgeExposure::denom));
//         if (MultiS3::denominator_type==MultiS3::ee_global) MultiS3::denom = newExposedEdgesNumer;
//        newCurrentScore += ms3Weight * (double)newMS3Numer / (double)MultiS3::denom / (double)MultiS3::Normalization_factor;//(double)NUM_GRAPHS;
//#endif
//            energyInc = newCurrentScore - currentScore;
//            wasBadMove = energyInc < 0;
//            //using max and min here because with extremely low temps I was seeing invalid probabilities
//            //note: I did not make this change for the other types of ScoreAggregation::  -Nil
//            if (energyInc >= 0) pBad = 1.0;
//            else pBad = max(0.0, min(1.0, exp(energyInc / Temperature)));
//            break;
//        }
//        case ScoreAggregation::product:
//        {
//            newCurrentScore = 1;
//            newCurrentScore *= ecWeight * (newAligEdges / g1Edges);
//            newCurrentScore *= s3Weight * (newAligEdges / (g1Edges + newInducedEdges - newAligEdges));
//            newCurrentScore *= icsWeight * (newAligEdges / newInducedEdges);
//            newCurrentScore *= localWeight * (newLocalScoreSum / n1);
//            newCurrentScore *= secWeight * (newAligEdges / g1Edges + newAligEdges / g2Edges)*0.5;
//            newCurrentScore *= wecWeight * (newWecSum / (2 * g1Edges));
//            newCurrentScore += jsWeight * (newJsSum);
//            newCurrentScore *= ncWeight * (newNcSum / trueAWithValidCountAppended.back());
//            energyInc = newCurrentScore - currentScore;
//            wasBadMove = energyInc < 0;
//            if (energyInc >= 0) pBad = 1;
//            else pBad = exp(energyInc / Temperature);
//            break;
//        }
//        case ScoreAggregation::max:
//        {
//            // this is a terrible way to compute the max; we should loop through all of them and figure out which is the biggest
//            // and in fact we haven't yet integrated icsWeight here yet, so assert so
//            assert(icsWeight == 0.0);
//            double deltaEnergy = max(ncWeight* (newNcSum / trueAWithValidCountAppended.back() - ncSum / trueAWithValidCountAppended.back()), max(max(ecWeight*(newAligEdges / g1Edges - aligEdges / g1Edges), max(
//                    s3Weight*((newAligEdges / (g1Edges + newInducedEdges - newAligEdges) - (aligEdges / (g1Edges + inducedEdges - aligEdges)))),
//                    secWeight*0.5*(newAligEdges / g1Edges - aligEdges / g1Edges + newAligEdges / g2Edges - aligEdges / g2Edges))),
//                    max(localWeight*((newLocalScoreSum / n1) - (localScoreSum)),
//                            max(wecWeight*(newWecSum / (2 * g1Edges) - wecSum / (2 * g1Edges)), jsWeight*(newJsSum - jsSum)))));
//
//            newCurrentScore += ecWeight * (newAligEdges / g1Edges);
//            newCurrentScore += secWeight * (newAligEdges / g1Edges + newAligEdges / g2Edges)*0.5;
//            newCurrentScore += s3Weight * (newAligEdges / (g1Edges + newInducedEdges - newAligEdges));
//            newCurrentScore += icsWeight * (newAligEdges / newInducedEdges);
//            newCurrentScore += localWeight * (newLocalScoreSum / n1);
//            newCurrentScore += wecWeight * (newWecSum / (2 * g1Edges));
//            newCurrentScore += jsWeight * (newJsSum);
//            newCurrentScore += ncWeight * (newNcSum / trueAWithValidCountAppended.back());
//
//            energyInc = newCurrentScore - currentScore;
//            wasBadMove = energyInc < 0;
//            if (deltaEnergy >= 0) pBad = 1;
//            else pBad = exp(energyInc / Temperature);
//            break;
//        }
//        case ScoreAggregation::min:
//        {
//            // see comment above in max
//            assert(icsWeight == 0.0);
//            double deltaEnergy = min(ncWeight* (newNcSum / trueAWithValidCountAppended.back() - ncSum / trueAWithValidCountAppended.back()), min(min(ecWeight*(newAligEdges / g1Edges - aligEdges / g1Edges), min(
//                    s3Weight*((newAligEdges / (g1Edges + newInducedEdges - newAligEdges) - (aligEdges / (g1Edges + inducedEdges - aligEdges)))),
//                    secWeight*0.5*(newAligEdges / g1Edges - aligEdges / g1Edges + newAligEdges / g2Edges - aligEdges / g2Edges))),
//                    min(localWeight*((newLocalScoreSum / n1) - (localScoreSum)),
//                            min(wecWeight*(newWecSum / (2 * g1Edges) - wecSum / (2 * g1Edges)), jsWeight*(newJsSum - jsSum)))));
//
//            newCurrentScore += ecWeight * (newAligEdges / g1Edges);
//            newCurrentScore += s3Weight * (newAligEdges / (g1Edges + newInducedEdges - newAligEdges));
//            newCurrentScore += icsWeight * (newAligEdges / newInducedEdges);
//            newCurrentScore += secWeight * (newAligEdges / g1Edges + newAligEdges / g2Edges)*0.5;
//            newCurrentScore += localWeight * (newLocalScoreSum / n1);
//            newCurrentScore += wecWeight * (newWecSum / (2 * g1Edges));
//            newCurrentScore += jsWeight * (newJsSum);
//            newCurrentScore += ncWeight * (newNcSum / trueAWithValidCountAppended.back());
//
//            energyInc = newCurrentScore - currentScore; //is this even used?
//            wasBadMove = deltaEnergy < 0;
//            if (deltaEnergy >= 0) pBad = 1;
//            else pBad = exp(energyInc / Temperature);
//            break;
//        }
//        case ScoreAggregation::inverse:
//        {
//            newCurrentScore += ecWeight / (newAligEdges / g1Edges);
//            newCurrentScore += secWeight * (newAligEdges / g1Edges + newAligEdges / g2Edges)*0.5;
//            newCurrentScore += s3Weight / (newAligEdges / (g1Edges + newInducedEdges - newAligEdges));
//            newCurrentScore += icsWeight / (newAligEdges / newInducedEdges);
//            newCurrentScore += localWeight / (newLocalScoreSum / n1);
//            newCurrentScore += wecWeight / (newWecSum / (2 * g1Edges));
//            newCurrentScore += jsWeight * (newJsSum);
//            newCurrentScore += ncWeight / (newNcSum / trueAWithValidCountAppended.back());
//
//            energyInc = newCurrentScore - currentScore;
//            wasBadMove = energyInc < 0;
//            if (energyInc >= 0) pBad = 1;
//            else pBad = exp(energyInc / Temperature);
//            break;
//        }
//        case ScoreAggregation::maxFactor:
//        {
//            assert(icsWeight == 0.0);
//            double maxScore = max(ncWeight*(newNcSum / trueAWithValidCountAppended.back() - ncSum / trueAWithValidCountAppended.back()), max(max(ecWeight*(newAligEdges / g1Edges - aligEdges / g1Edges), max(
//                    s3Weight*((newAligEdges / (g1Edges + newInducedEdges - newAligEdges) - (aligEdges / (g1Edges + inducedEdges - aligEdges)))),
//                    secWeight*0.5*(newAligEdges / g1Edges - aligEdges / g1Edges + newAligEdges / g2Edges - aligEdges / g2Edges))),
//                    max(localWeight*((newLocalScoreSum / n1) - (localScoreSum)),
//                            max(wecWeight*(newWecSum / (2 * g1Edges) - wecSum / (2 * g1Edges)), jsWeight*(newJsSum - jsSum)))));
//
//            double minScore = min(ncWeight*(newNcSum / trueAWithValidCountAppended.back() - ncSum / trueAWithValidCountAppended.back()), min(min(ecWeight*(newAligEdges / g1Edges - aligEdges / g1Edges), min(
//                    s3Weight*((newAligEdges / (g1Edges + newInducedEdges - newAligEdges) - (aligEdges / (g1Edges + inducedEdges - aligEdges)))),
//                    secWeight*0.5*(newAligEdges / g1Edges - aligEdges / g1Edges + newAligEdges / g2Edges - aligEdges / g2Edges))),
//                    min(localWeight*((newLocalScoreSum / n1) - (localScoreSum)),
//                            min(wecWeight*(newWecSum / (2 * g1Edges) - wecSum / (2 * g1Edges)), jsWeight*(newJsSum - jsSum)))));
//
//            newCurrentScore += ecWeight * (newAligEdges / g1Edges);
//            newCurrentScore += secWeight * (newAligEdges / g1Edges + newAligEdges / g2Edges)*0.5;
//            newCurrentScore += s3Weight * (newAligEdges / (g1Edges + newInducedEdges - newAligEdges));
//            newCurrentScore += icsWeight * (newAligEdges / newInducedEdges);
//            newCurrentScore += localWeight * (newLocalScoreSum / n1);
//            newCurrentScore += wecWeight * (newWecSum / (2 * g1Edges));
//            newCurrentScore += jsWeight * (newJsSum);
//            newCurrentScore += ncWeight * (newNcSum / trueAWithValidCountAppended.back());
//
//            energyInc = newCurrentScore - currentScore;
//            wasBadMove = maxScore < -1 * minScore;
//            if (maxScore >= -1 * minScore) pBad = 1;
//            else pBad = exp(energyInc / Temperature);
//            break;
//        }
//    }
//
//    //if (wasBadMove && (iterationsPerformed % 512 == 0 || (iterationsPerformed % 32 == 0)))
//    //the above will never be true in the case of iterationsPerformed never being changed so that it doesn't greatly
//    // slow down the program if for some reason iterationsPerformed doesn't need to be changed.
//    if (wasBadMove) { // I think Dillon was wrong above, just do it always - WH
//        if (numPBadsInBuffer == PBAD_CIRCULAR_BUFFER_SIZE) {
//            pBadBufferIndex = (pBadBufferIndex == PBAD_CIRCULAR_BUFFER_SIZE ? 0 : pBadBufferIndex);
//            pBadBufferSum -= pBadBuffer[pBadBufferIndex];
//            pBadBuffer[pBadBufferIndex] = pBad;
//        } else {
//            pBadBuffer[pBadBufferIndex] = pBad;
//            numPBadsInBuffer++;
//        }
//        pBadBufferSum += pBad;
//        pBadBufferIndex++;
//    }
//    return pBad;
//}
//
//
//static double getRatio(double w1, double w2) {
//    double r;
//    if (w1==0 && w2==0) r=1;
//    else if (abs(w1)<abs(w2)) r=w1/w2;
//    else r=w2/w1;
//    // At this point, r can be in [-1,1], but we want it [0,1], so add 1 and divide by 2
//    r = (r+1)/2;
//    assert(r>=0 && r<=1);
//    return r;
//}
//
//
//void SANA::trackProgress(long long int iter, long long int maxIters) {
//    if (!enableTrackProgress) return;
//    double fractionTime = maxIters == -1 ? 0 : iter/(double)maxIters;
//    double elapsedTime = timer.elapsed();
//    uint iterationsElapsed = iterationsPerformed-oldIterationsPerformed;
//    if (elapsedTime == 0) oldTimeElapsed = 0;
//    double ips = (iterationsElapsed/(elapsedTime-oldTimeElapsed));
//    oldTimeElapsed = elapsedTime;
//    oldIterationsPerformed = iterationsPerformed;
//    cout<<iter/iterationsPerStep<<" ("<<100*fractionTime<<"%,"<<elapsedTime<<"s): score = "<<currentScore;
//    cout<< " ips = "<<ips<<", P("<<Temperature<<") = "<<acceptingProbability(avgEnergyInc, Temperature);
//    cout<<", pBad = "<<incrementalMeanPBad()<<endl;
//
//    bool checkScores = true;
//    if (checkScores) {
//        double realScore = eval(A);
//        if (fabs(realScore-currentScore) > 0.00001) {
//            cerr<<"internal error: incrementally computed score ("<<currentScore;
//            cerr<<") is not correct ("<<realScore<<")"<<endl;
//            currentScore = realScore;
//        }
//    }
//
//    //code for estimating dynamic TDecay. The dynamic method uses linear interpolation to obtain an
//    //an "ideal" P(bad) as a basis for SANA runs. If the current P(bad) is significantly different from
//    //our "ideal" P(bad), then decay is either "sped up" or "slowed down"
//    if (dynamicTDecay) {
//        int NSteps = 100;
//        double fractionTime = (timer.elapsed()/maxSeconds);
//        double lowIndex = floor(NSteps*fractionTime);
//        double highIndex = ceil(NSteps*fractionTime);
//        double betweenFraction = NSteps*fractionTime - lowIndex;
//        double PLow = tau[lowIndex];
//        double PHigh = tau[highIndex];
//        double PBetween = PLow + betweenFraction * (PHigh - PLow);
//
//        // if the ratio if off by more than a few percent, adjust.
//        double ratio = acceptingProbability(avgEnergyInc, Temperature) / PBetween;
//
//        //dynamicTDecayTime is never initialized, so I don't think this works
//        if (abs(1-ratio) >= .01 and
//            (ratio < 1 or dynamicTDecayTime > .2)) { //don't speed it up too soon
//            double shouldBe = -log(avgEnergyInc/(TInitial*log(PBetween)))/(dynamicTDecayTime);
//            if (dynamicTDecayTime == 0 or shouldBe != shouldBe or shouldBe <= 0)
//                shouldBe = TDecay * (ratio >= 0 ? ratio*ratio : 0.5);
//            cout<<"TDecay "<<TDecay<<" too ";
//            cout<<(ratio < 1 ? "fast" : "slow")<<" shouldBe "<<shouldBe;
//            TDecay = sqrt(TDecay * shouldBe); //geometric mean
//            cout<<"; try "<<TDecay<<endl;
//        }
//    }
//}
//
//void SANA::setTInitial(double t) { TInitial = t; }
//void SANA::setTFinal(double t) { TFinal = t; }
//void SANA::setTDecayFromTempRange() { TDecay = -log(TFinal/TInitial); }
//void SANA::setDynamicTDecay() { dynamicTDecay = true; }
//
//double SANA::getIterPerSecond() {
//    if (not initializedIterPerSecond) initIterPerSecond();
//    return iterPerSecond;
//}
//
//void SANA::initIterPerSecond() {
//    initializedIterPerSecond = true;
//    cout << "Determining iteration speed...." << endl;
//    double totalIps = 0.0;
//    int ipsListSize = 0;
//    if (ipsList.size() != 0) {
//        for (pair<double,double> ipsPair : ipsList) {
//            if (TFinal <= ipsPair.first && ipsPair.first <= TInitial) {
//                totalIps+=ipsPair.second;
//                ipsListSize+=1;
//            }
//        }
//        totalIps = totalIps / (double) ipsListSize;
//    } else {
//        cout << "Since temperature schedule is provided, ips will be "
//             << "calculated using constantTempIterations" << endl;
//        long long int iter = 1E6;
//        constantTempIterations(iter - 1);
//        double res = iter/timer.elapsed();
//        totalIps = res;
//    }
//    cout << "SANA does " << long(totalIps) << " iterations per second on average" << endl;
//    iterPerSecond = totalIps;
//
//    //what is this? can it be removed? -Nil
//    uint integralMin = maxSeconds/60.0;
//    string folder = "cache-pbad/"+MC->toString()+"/progress_"+to_string(integralMin)+"/";
//    string fileName = folder+G1->getName()+"_"+G2->getName()+"_0.csv";
//    ofstream ofs(fileName);
//    ofs<<"time,score,avgEnergyInc,Temperature,realTemp,pBad,lower,higher,timer"<<endl;
//}
//
//void SANA::constantTempIterations(long long int iterTarget) {
//    initDataStructures();
//    long long int iter;
//    for (iter = 1; iter < iterTarget ; ++iter) {
//        if (iter%iterationsPerStep == 0) trackProgress(iter);
//        SANAIteration();
//    }
//    trackProgress(iter);
//}
//
///* when we run sana at a fixed temp, scores generally go up
//(especially if the temp is low) until a point of "thermal equilibrium".
//This function should return the avg pBad at equilibrium.
//we keep track of the score every certain number of iterations
//if the score went down at least half the time,
//this suggests that the upward trend is over and we are at equilirbium
//once we know we are at equilibrium, we use the buffer of pbads to get an average pBad
//'logLevel' can be 0 (no output) 1 (logs result in cerr) or 2 (verbose/debug mode)*/
//double SANA::getPBad(double temp, double maxTimeInS, int logLevel) {
//    //new state for the run at fixed temperature
//    constantTemp = true;
//    Temperature = temp;
//    enableTrackProgress = false;
//
//    //note: this is a circular buffer that maintains scores sampled at intervals
//    vector<double> scoreBuffer;
//    //the larger 'numScores' is, the stronger evidence of reachign equilibrium. keep this value odd
//    const uint numScores = 11;
//    uint iter = 0;
//    uint sampleInterval = 10000;
//    bool reachedEquilibrium = false;
//    initDataStructures(); //this initializes the timer and resets the pBad buffer
//    bool verbose = (logLevel == 2); //print everything going on, for debugging purposes
//    uint verbose_i = 0;
//    if (verbose) cerr<<endl<<"****************************************"<<endl
//                     <<"starting search for pBad for temp = "<<temp<<endl;
//    while (not reachedEquilibrium) {
//        SANAIteration();
//        iter++;
//        if (iter%sampleInterval == 0) {
//            if (verbose) {
//                cerr<<verbose_i<<" score: "<<currentScore<<" (avg pBad: "
//                    <<slowMeanPBad()<<")"<<endl;
//                verbose_i++;
//            }
//            //circular buffer behavior
//            //(since the buffer is tiny, the cost of shifting everything is negligible)
//            scoreBuffer.push_back(currentScore);
//            if (scoreBuffer.size() > numScores) scoreBuffer.erase(scoreBuffer.begin());
//            if (scoreBuffer.size() == numScores) {
//                //check if we are at eq:
//                //if the score went down more than up, it suggests we are at eq
//                uint scoreTrend = 0;
//                for (uint i = 0; i < numScores-1; i++) {
//                    if (scoreBuffer[i+1] < scoreBuffer[i]) scoreTrend--;
//                    if (scoreBuffer[i+1] > scoreBuffer[i]) scoreTrend++;
//                }
//                reachedEquilibrium = (scoreTrend <= 0);
//                if (verbose) {
//                    cerr<<"scoreTrend = "<<scoreTrend<<endl;
//                    if (reachedEquilibrium) {
//                        cerr<<endl<<"Reached equilibrium"<<endl<<"scoreBuffer:"<<endl;
//                        for (uint i = 0; i < scoreBuffer.size(); i++) cerr<<scoreBuffer[i]<<" ";
//                        cerr<<endl;
//                    }
//                }
//            }
//            if (timer.elapsed() > maxTimeInS) {
//                if (verbose) {
//                    cerr<<"ran out of time. scoreBuffer:"<<endl;
//                    for (uint i = 0; i < scoreBuffer.size(); i++) cerr<<scoreBuffer[i]<<endl;
//                    cerr<<endl;
//                }
//                break;
//            }
//        }
//    }
//    double pBadAvgAtEq = slowMeanPBad();
//    double nextIps = (double)iter / (double)timer.elapsed();
//    pair<double, double> nextPair (temp, nextIps);
//    ipsList.push_back(nextPair);
//    if (logLevel >= 1) {
//        cout<<"> getPBad("<<temp<<") = "<<pBadAvgAtEq<<" (score: "<<currentScore<<")";
//        if (reachedEquilibrium) cout<<" (time: "<<timer.elapsed()<<"s)";
//        else cout<<" (didn't detect eq. after "<<maxSeconds<<"s)";
//        cout<<" iterations = "<<iter<<", ips = "<<nextIps<<endl;
//        if (verbose) cerr<<"final result: "<<pBadAvgAtEq<<endl
//                         <<"****************************************"<<endl<<endl;
//    }
//
//    //restore normal execution state
//    constantTemp = false;
//    enableTrackProgress = true;
//    Temperature = TInitial;
//
//    return pBadAvgAtEq;
//}