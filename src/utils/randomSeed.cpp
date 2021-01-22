#include "utils/randomSeed.hpp"

#include <random>
#include <unistd.h>

using namespace std;

unsigned int currentSeed;
static bool doneInit = false;

void setSeed(unsigned int seed) {
	currentSeed = seed;
	doneInit = true;
}

void setRandomSeed() {
	currentSeed = gethostid() + time(nullptr) + getpid();
	doneInit = true;
}

unsigned int getRandomSeed() {
	if (not doneInit) setRandomSeed();
	return currentSeed;
}
