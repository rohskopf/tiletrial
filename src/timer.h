/*
 timer.h
*/

#pragma once

#include <string>
#include "pointers.h"
#include <time.h>
#include <sys/time.h>

namespace TT_NS
{
    class Timer : protected Pointers
    {
    public:
        Timer(class TT *);
        ~Timer();

        void reset();
        double elapsed();
        void print_elapsed();
        std::string DateAndTime();

    private:

    timeval time_ref;

    };
}
