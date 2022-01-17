#include <stdlib.h>
#include <iostream>
#include "tt.h"
//#include "mpi.h"

using namespace TT_NS;

int main(int argc, char *argv[])
{

  /* Initialize MPI */
  //MPI_Init(&argc,&argv);

  /* Begin a TT instance */
  TT *tt = new TT(argc, argv);

  /* Delete the memory */
  delete tt;

  /* Close MPI */
  //int MPI_Comm_free(MPI_Comm *comm);
  //MPI_Finalize();

  return EXIT_SUCCESS;
}

