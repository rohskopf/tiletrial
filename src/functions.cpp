/*
This class houses the functions used to tile the sequence.
*/

#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <random>
//#include "mpi.h"

#include "memory.h"
#include "functions.h"
#include "container.h"
#include "timer.h"

using namespace std;

using namespace TT_NS;

Functions::Functions(TT *tt) : Pointers(tt) {

}

Functions::~Functions() 
{

};

/*
Initialize
*/
void Functions::initialize()
{

}

/*
Task 1 - allocates a custom "Container" class which houses the tiles as char* arrays.
*/
Container* Functions::task1(string& str)
{
  
  // Declare a pointer to container which will house the tiles.
  Container *container;
    
  // Allocate container of tiles
  memory->allocate(container, ntiles);
  
  // Perform the tiling
  int indx=0;
  for (int i=0; i<ntiles; i++){
    // Allocate memory for tile
    memory->allocate(container[i].tile,k);
    for (int j=0; j<k; j++){
      container[i].tile[j] = str[i+j];
    }
  }
    
  return container;
  
}

/*
Task 2 - Uses vector<string> and the push_back() function to create the tiles.
*/
std::vector<string> Functions::task2(string& str)
{

  // Declare the vector of tiles (strings) with proper number of tiles
  vector<string> vec(ntiles);
  
  // Perform the tiling
  for (int i=0; i<ntiles; i++){
    for (int j=0; j<k; j++){
      vec[i].push_back(str[i+j]);
    }
  }
  
  return vec;
  
}

/*
Task 3 - Uses vector<string> the substr function to create the tiles.
*/
std::vector<string> Functions::task3(string& str)
{

  // Declare the vector of tiles (strings) with proper number of tiles
  vector<string> vec(ntiles);
  
  // Perform the tiling
  for (int i=0; i<ntiles; i++){
    vec[i] = str.substr(i,k);
  }
  
  return vec;
  
}
