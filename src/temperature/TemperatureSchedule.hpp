#ifndef SANA_TEMPERATURESCHEDULE_HPP
#define SANA_TEMPERATURESCHEDULE_HPP

namespace sana {
    struct TemperatureSchedule {
        TemperatureSchedule(double initialTemp, double temperatureDecay);
        /**
         * Calculates temperature for the specific iteration or current elapsed time.
         * TODO: Explain more how the temperature system works?
         * @param iter
         * @param initialTemp
         * @param temperatureDecay
         * @return
         */
        virtual double calculateTemperature(long long iter, long long elapsedTime) = 0;
        const double initialTemp;
        const double temperatureDecay;
    };

    struct ConstantSchedule : public TemperatureSchedule {
        ConstantSchedule(double initialTemp, double temperatureDecay);
        double calculateTemperature(long long iter, long long elapsedTime) override;
    };

    // NOTE: Not sure what to call it? Find better name later.
    struct IterationSchedule : public TemperatureSchedule {
        IterationSchedule(double initialTemp, double temperatureDecay, long long maxIterations);
        double calculateTemperature(long long iter, long long elapsedTime) override;
        const long long maxIterations;
    };

    struct TimeSchedule : public TemperatureSchedule {
        TimeSchedule(double initialTemp, double temperatureDecay, long long maxTime);
        double calculateTemperature(long long iter, long long elapsedTime) override;
        const long long maxTime;
    };
}
#endif //SANA_TEMPERATURESCHEDULE_HPP
