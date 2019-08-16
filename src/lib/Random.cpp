#include <random>
#include <unistd.h>

#include <sana/Random.hpp>

RandomNumberGenerator::RandomNumberGenerator() {
    SetSeed(gethostid() + time(0) + getpid());
}

RandomNumberGenerator::RandomNumberGenerator(const int& seed) {
    SetSeed(seed);
}

void RandomNumberGenerator::SetSeed(unsigned int seed) {
    currentSeed = seed;
    numberGenerator.seed(currentSeed);
}

unsigned int RandomNumberGenerator::GetSeed() {
    return currentSeed;
}



