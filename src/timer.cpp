/*
 timer.cpp
*/

#include "timer.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace TT_NS;

Timer::Timer(TT *tt): Pointers(tt)
{
#if defined(WIN32) || defined(_WIN32)
    QueryPerformanceCounter(&time_ref);
    QueryPerformanceFrequency(&frequency);
#else
    gettimeofday(&time_ref, NULL);
#endif
}

Timer::~Timer() {}

void Timer::reset()
{
#if defined(WIN32) || defined(_WIN32)
    QueryPerformanceCounter(&time_ref);
#else
    gettimeofday(&time_ref, NULL);
#endif
}

double Timer::elapsed()
{
#if defined(WIN32) || defined(_WIN32)
    LARGE_INTEGER time_now;
    QueryPerformanceCounter(&time_now);
    return static_cast<double>(time_now.QuadPart - time_ref.QuadPart)
        / static_cast<double>(frequency.QuadPart);
#else
    timeval time_now;
    gettimeofday(&time_now, NULL);
    return (time_now.tv_sec - time_ref.tv_sec) + (time_now.tv_usec - time_ref.tv_usec) * 1.0e-6;
#endif
}

void Timer::print_elapsed()
{
    std::cout << "  Time Elapsed: " << elapsed() << " sec."
        << std::endl << std::endl;
}


std::string Timer::DateAndTime()
{
    time_t current;
    std::time(&current);

#if defined(WIN32) || defined(_WIN32)
    errno_t err_t;
    struct tm local;

    char str_now[32];

    err_t = localtime_s(&local, &current);
    err_t = asctime_s(str_now, 32, &local);
    return str_now;
#else
    struct tm *local;
    local = std::localtime(&current);

    return asctime(local);
#endif
}
