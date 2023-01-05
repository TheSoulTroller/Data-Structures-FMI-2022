#pragma once
#include <chrono>
using namespace std::chrono;

class Timer {
private:
    high_resolution_clock::time_point start;

public:
    Timer() : start(high_resolution_clock::now()) {}
    ~Timer() {
    }

    void stop(const std::string& algorthmName) {
        const long long duration = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
        cout << algorthmName << " finished in " << duration << " microseconds" << endl;
        this->~Timer();
    }

};