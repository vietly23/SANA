#ifndef TIMER_HPP
#define TIMER_HPP
#include <string>

class Timer {
public:
    Timer();

    void start();
    double elapsed() const;
    std::string elapsedString() const;

private:
    long long startTime;
    static long long get();
};


#endif
