#include <iostream>

#include "arguments/MethodSelector.hpp"
#include "arguments/measureSelector.hpp"

#include "utils/Timer.hpp"
#include "methods/NoneMethod.hpp"
#include "methods/HillClimbing.hpp"
#include "methods/SANA.hpp"
#include "methods/RandomAligner.hpp"
#include "methods/wrappers/NETALWrapper.hpp"
#include "methods/wrappers/MIGRAALWrapper.hpp"
#include "methods/wrappers/GHOSTWrapper.hpp"
#include "methods/wrappers/PISwapWrapper.hpp"
#include "methods/wrappers/OptNetAlignWrapper.hpp"
#include "methods/wrappers/SPINALWrapper.hpp"
#include "methods/wrappers/GREATWrapper.hpp"
#include "methods/wrappers/NATALIEWrapper.hpp"
#include "methods/wrappers/GEDEVOWrapper.hpp"
#include "methods/wrappers/WAVEWrapper.hpp"
#include "methods/wrappers/MagnaWrapper.hpp"
#include "methods/wrappers/PINALOGWrapper.hpp"
#include "methods/wrappers/SANAPISWAPWrapper.hpp"
#include "methods/wrappers/CytoGEDEVOWrapper.hpp"

#include "schedulemethods/ScheduleMethod.hpp"
#include "schedulemethods/scheduleUtils.hpp"
#include "schedulemethods/LinearRegressionVintage.hpp"

using namespace std;


Method* MethodSelector::initMethod(const Graph& G1, const Graph& G2, ArgumentParser& args, MeasureCombination& M) {
    string aligFile = args.strings["-eval"];
    if (aligFile != "") return new NoneMethod(&G1, &G2, aligFile);
    string name = toLowerCase(args.strings["-method"]);
    string startAligName = args.strings["-startalignment"];
    double alpha = args.doubles["-alpha"];
    string wrappedArgs = args.strings["-wrappedArgs"];
    double maxGraphletSize = args.doubles["-maxGraphletSize"] != 0 ? args.doubles["-maxGraphletSize"] : 4; 

    if (name != "sana" and (args.strings["-fcolor1"] != "" 
                         or args.strings["-fcolor2"] != ""))
        cerr <<"Warning: only sana takes colors into consideration" << endl;

    if (name == "sana")        return static_cast<Method*>(initSANA(G1, G2, args, M, startAligName));
    if (name == "hc")          return new HillClimbing(&G1, &G2, &M, startAligName);
    if (name == "random")      return new RandomAligner(&G1, &G2);
    if (name == "none")        return new NoneMethod(&G1, &G2, startAligName);
    //wrappers
    if (name == "lgraal")      return static_cast<Method*>(initLgraalWrapper(G1, G2, args));
    if (name == "hubalign")    return static_cast<Method*>(initHubAlignWrapper(G1, G2, args));
    if (name == "netal")       return new NETALWrapper(&G1, &G2, wrappedArgs);
    if (name == "migraal")     return new MIGRAALWrapper(&G1, &G2, wrappedArgs);
    if (name == "ghost")       return new GHOSTWrapper(&G1, &G2, wrappedArgs);
    if (name == "piswap")      return new PISwapWrapper(&G1, &G2, alpha, startAligName, wrappedArgs);
    if (name == "optnetalign") return new OptNetAlignWrapper(&G1, &G2, wrappedArgs);
    if (name == "spinal")      return new SPINALWrapper(&G1, &G2, alpha, wrappedArgs);
    if (name == "great")       return new GREATWrapper(&G1, &G2, wrappedArgs);
    if (name == "natalie")     return new NATALIEWrapper(&G1, &G2, wrappedArgs);
    if (name == "gedevo")      return new GEDEVOWrapper(&G1, &G2, wrappedArgs, maxGraphletSize);
    if (name == "wave")        return new WAVEWrapper(&G1, &G2, wrappedArgs);
    if (name == "magna")       return new MagnaWrapper(&G1, &G2, wrappedArgs);
    if (name == "pinalog")     return new PINALOGWrapper(&G1, &G2, wrappedArgs);
    if (name == "cytogedevo")  return new CytoGEDEVOWrapper(&G1, &G2, wrappedArgs);

    //the whole point of this class (MethodSelector) is to call the methods' constructors
    //with the appropriate parameters based on the input arguments.
    //passing the argument list to a method constructor breaks the design pattern -Nil
    if (name == "sana+piswap") return new SANAPISWAPWrapper(&G1, &G2, args, M);

    //deprecated
    if (name == "dijkstra")    throw runtime_error("dijkstra no longer supported");
    if (name == "tabu")        throw runtime_error("tabu search no longer supported");
    if (name == "greedylccs")  throw runtime_error("greedy lccs no longer supported");
    if (name == "waveSim")     throw runtime_error("weighted alignment voter no longer supported");
    throw runtime_error("Error: unknown method '" + name + "'");
}

void MethodSelector::validateTimeOrIterLimit(ArgumentParser& args) {
    double ts = args.doubles["-ts"], tm = args.doubles["-tm"], t = args.doubles["-t"],
           it = args.doubles["-it"], itk = args.doubles["-itk"],
           itm = args.doubles["-itm"], itb = args.doubles["-itb"];
    uint execLimitArgCount = (t>0)+(ts>0)+(tm>0)+(it>0)+(itk>0)+(itm>0)+(itb>0);
    if (execLimitArgCount != 1)
        throw runtime_error("exactly one of '-t', -ts', '-tm', '-it', '-itk', '-itm', '-itb' must be >0");
}

SANA* MethodSelector::initSANA(const Graph& G1, const Graph& G2, 
        ArgumentParser& args, MeasureCombination& M, string startAligName) {
    string TIniArg = args.strings["-tinitial"];
    string TDecayArg = args.strings["-tdecay"];
    string scheduleMethodName = args.strings["-schedulemethod"];

    //this is a special argument value that does a comparison between all temperature schedule methods
    //made for the purpose of running the experiments for the paper on the tempertaure schedule
    if (scheduleMethodName == "comparison") {
        Alignment startAlig;
        if (startAligName != "") startAlig = Alignment::loadEdgeList(G1, G2, startAligName);
        SANA sana(&G1, &G2, 0, 0, 0, 0, 0, &M, 
                  args.strings["-combinedScoreAs"], startAlig, "", "");
        scheduleMethodComparison(&sana);
        exit(0);
    }

    double TInitial = 0, TDecay = 0;
    bool useMethodForTIni = (TIniArg == "auto");
    bool useMethodForTDecay = (TDecayArg == "auto");

    //read explicit values if not using an automatic method
    if (not useMethodForTIni) {
        try { TInitial = stod(TIniArg); }
        catch (...) { throw runtime_error("invalid -tinitial argument: "+TIniArg); }
    } 
    if (not useMethodForTDecay) {
        try { TDecay = stod(TDecayArg); }
        catch (...) { throw runtime_error("invalid -tinitial argument: "+TDecayArg); }
    }

    validateTimeOrIterLimit(args);
    double ts = args.doubles["-ts"], tm = args.doubles["-tm"], t = args.doubles["-t"],
           it = args.doubles["-it"], itk = args.doubles["-itk"],
           itm = args.doubles["-itm"], itb = args.doubles["-itb"];
    double maxSeconds = 0;
    long long int maxIterations = 0;
    if (t > 0) maxSeconds = 60*t;
    if (ts > 0) maxSeconds = ts;
    if (tm > 0) maxSeconds = 60*tm;
    if (it > 0) maxIterations = (long long int) it;
    if (itk > 0) maxIterations = (long long int) (itk * 1e3);
    if (itm > 0) maxIterations = (long long int) (itm * 1e6);
    if (itb > 0) maxIterations = (long long int) (itb * 1e9);

    Alignment startAlig;
    if (startAligName != "") startAlig = Alignment::loadEdgeList(G1, G2, startAligName);

    SANA* sana = new SANA(&G1, &G2, TInitial, TDecay, maxSeconds, maxIterations,
        args.bools["-add-hill-climbing"], &M, args.strings["-combinedScoreAs"],
        startAlig, args.strings["-o"], args.strings["-localScoresFile"]);

    if (useMethodForTIni or useMethodForTDecay) {
        if (scheduleMethodName == "auto" ) { //if user uses 'auto', choose for them
            scheduleMethodName = LinearRegressionVintage::NAME;
        }
        ScheduleMethod::setSana(sana);
        auto scheduleMethod = getScheduleMethod(scheduleMethodName);
        scheduleMethod->setSampleTime(2);
        ScheduleMethod::Resources maxRes(60, 200.0); //#samples, seconds
        if (useMethodForTIni) {
            sana->setTInitial(scheduleMethod->computeTInitial(maxRes));
        }
        if (useMethodForTDecay) {
            sana->setTFinal(scheduleMethod->computeTFinal(maxRes));
            sana->setTDecayFromTempRange();
        }
        scheduleMethod->printScheduleStatistics();
    }
    if (args.bools["-dynamictdecay"]) sana->setDynamicTDecay();
    return sana;
}

LGraalWrapper* MethodSelector::initLgraalWrapper(const Graph& G1,const Graph& G2, ArgumentParser& args) {
    string objFunType = args.strings["-objfuntype"];
    double alpha;
    if (objFunType == "generic") {
        throw runtime_error("generic objective function not supported for L-GRAAL");
    } else if (objFunType == "alpha") {
        alpha = args.doubles["-alpha"];
    } else if (objFunType == "beta") {
        double beta = args.doubles["-beta"];
        alpha = measureSelector::betaDerivedAlpha("lgraal", G1.getName(), G2.getName(), beta);
    } else {
        throw runtime_error("unknown value of -objfuntype: "+objFunType);
    }
    double iters = args.doubles["-lgraaliter"];

    double ts = args.doubles["-ts"], tm = args.doubles["-tm"], t = args.doubles["-t"];

    if ((ts > 0 and tm > 0) or (ts <= 0 and tm <= 0 and t <= 0))
        throw runtime_error("specify exactly one of '-ts' and '-tm' for LGRAAL");
    double seconds = (ts > 0 ? ts : 60*tm);

    return new LGraalWrapper(&G1, &G2, alpha, iters, seconds);
}

HubAlignWrapper* MethodSelector::initHubAlignWrapper(const Graph& G1, const Graph& G2, ArgumentParser& args) {
    string objFunType = args.strings["-objfuntype"];
    double alpha;
    if (objFunType == "generic") {
        throw runtime_error("generic objective function not supported for HubAlign");
    } else if (objFunType == "alpha") {
        alpha = args.doubles["-alpha"];
    } else if (objFunType == "beta") {
        double beta = args.doubles["-beta"];
        alpha = measureSelector::betaDerivedAlpha("hubalign", G1.getName(), G2.getName(), beta);
    } else {
        throw runtime_error("unknown value of -objfuntype: "+objFunType);
    }
    return new HubAlignWrapper(&G1, &G2, alpha);
}

