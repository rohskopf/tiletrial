#pragma once
#include <string>
#include <vector>
//#include "mpi.h"


namespace TT_NS
{
    class TT
    {
    public:

        class Memory *memory;
        class Functions *functions;
        class Timer *timer;

        TT(int, char **);
        ~TT();
        void create();
        void initialize();
        void run();
        void finalize();
        int nprocs;
        int rank;

        int task; // task to perform
        int k; // length of each tile
        int seqlen; // length of original sequence
        int ntiles; // number of tiles, i.e. length of list/vector containing tiles
        
        char *seq_char; // original sequence in char array, used for reading the SEQUENCE File
        std::string sequence; // original sequence
        
    };
}

