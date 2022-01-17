#pragma once
#include <vector>
#include <string>
//#include "mpi.h"
#include <iostream>
#include <new>
#include <cstdlib>
#include "pointers.h"
#include "container.h"

namespace TT_NS
{
  class Functions: protected Pointers
  {
  public:
    Functions(class TT *);
    ~Functions();

    int rank;

    // Functions.
    void initialize();
    
    // Different tasks
    Container* task1(std::string&);
    std::vector<std::string> task2(std::string&);
    std::vector<std::string> task3(std::string&);
    
    // Settings
    int task; // 1 - using custom Container class with Memory class allocation
              // 2 - using vector<string>, and push_back to fill the tiles
              // 3 - using vector<string>, and 
 
    // Variables
    int k;
    int seqlen;
    int ntiles;

  };
}

