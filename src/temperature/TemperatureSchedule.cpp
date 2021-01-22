#include "TemperatureSchedule.hpp"

#include <cmath>

sana::ConstantSchedule::ConstantSchedule(double initialTemp, double temperatureDecay) : TemperatureSchedule(initialTemp,
        temperatureDecay) {
}

double sana::ConstantSchedule::calculateTemperature(long long iter, long long elapsedTime) {
    return initialTemp;
}
sana::IterationSchedule::IterationSchedule(double initialTemp, double temperatureDecay, long long maxIterations) :
TemperatureSchedule(initialTemp, temperatureDecay), maxIterations(maxIterations) {
}

double sana::IterationSchedule::calculateTemperature(long long iter, long long elapsedTime) {
    double fraction = iter / (double) maxIterations;
    return initialTemp * std::exp(-temperatureDecay * fraction);
}

sana::TemperatureSchedule::TemperatureSchedule(double initialTemp, double temperatureDecay) :
initialTemp(initialTemp), temperatureDecay(temperatureDecay) {
}


sana::TimeSchedule::TimeSchedule(double initialTemp, double temperatureDecay, long long maxTime) :
TemperatureSchedule(initialTemp, temperatureDecay), maxTime(maxTime) {
}

double sana::TimeSchedule::calculateTemperature(long long int iter, long long int elapsedTime) {
    double fraction = elapsedTime / maxTime;
    return initialTemp * std::exp(-temperatureDecay * fraction);
}