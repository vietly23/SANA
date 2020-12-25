#include <iostream>
#include <cstdlib>
#include "arguments/ArgumentParser.hpp"
#include "utils/randomSeed.hpp"
#include "modes/Mode.hpp"
#include "arguments/modeSelector.hpp"

int main(int argc, char* argv[]) {
    std::cout << unitbuf; //set cout to flush after each insertion

    ArgumentParser args(argc, argv);

    // Assign to unused_ret to shut the compiler warning about igoring return value
    int sysRet = system("hostname -f; date");
    if (sysRet != 0) {
        cerr<<"'hostname -f; date' returned error code "<<sysRet<<endl;
    }

    args.writeArguments();

    if (args.doubles["-seed"] != 0) {
        setSeed(args.doubles["-seed"]);
    } else {
        setRandomSeed();
    }

    std::cout << "Seed: " << getRandomSeed() << std::endl;

    Mode* mode = modeSelector::selectMode(args);
    mode->run(args);
    delete mode;
}
