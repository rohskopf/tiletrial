#pragma once
#include "mpi.h"
#include "tt.h"

namespace TT_NS
{
    class Pointers
    {
    public:
        Pointers(TT *ptr) :
            tt(ptr),
            memory(ptr->memory),
            timer(ptr->timer)
            {}

        virtual ~Pointers() {}

    protected:
        TT *tt;
        Memory *&memory;
        Timer *&timer;
    };
}

