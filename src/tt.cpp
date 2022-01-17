#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

/* TileTrial (TT) include files */
#include "tt.h"
#include "memory.h"
#include "functions.h"
#include "container.h"
#include "timer.h"

/* MPI include file */
//#include "mpi.h"

using namespace std;

using namespace TT_NS;

TT::TT(int narg, char **args)
{

    /************************** Set up OpenMPI/OpenMP/CUDA settings **************************/

    // Parallelization settings would go here.

    /************************** Initial Screen Output **************************/
    if (rank == 0)
    {
        std::cout << " +-----------------------------------------------------------------+" << std::endl;
        std::cout << " +                          TileTrial 0.0                          +" << std::endl;
        std::cout << " +-----------------------------------------------------------------+" << std::endl;
        //std::cout << " Running on " << nprocs << " procs" << std::endl;
    }

    /************************** Proceed **************************/

    // Extract desired task
    if (narg != 4){
      printf(" Need 3 args (task, k, seqlen)\n");
    }
    task = atoi(args[1]);
    k = atoi(args[2]);
    seqlen = atoi(args[3]);
    
    printf(" Will use functions->task%d\n", task);
    printf(" Tile length (k): %d\n", k);
    printf(" Original sequence length (seqlen): %d\n", seqlen);
    // Calculate length of vector of strings
    ntiles = seqlen-k+1;
    printf(" Length of list/vector of tiles (ntiles): %d\n", ntiles);
    //std::cout << task << std::endl;

    // Dynamically allocated pointers
    create();

    // Read the original sequence in the SEQUENCE file.
    initialize();
    
    // Run the code and desired task.
    run();

    // Delete dynamically allocated pointers
    finalize();
    
}

void TT::create()
{
    memory = new Memory(this);
    functions = new Functions(this);
    timer = new Timer(this);
    //container = new Container(this);

}

void TT::initialize()
{

  memory->allocate(seq_char,seqlen);
  // Read contents of SEQUENCE file into str
  std::ifstream readfile;
  readfile.open("SEQUENCE");
  for (int i=0;i<seqlen;i++){
      readfile>>seq_char[i];
  }
  readfile.close();
  
  // Convert char* to string
  sequence.assign(seq_char, seqlen);
  
  functions->k=k;
  functions->seqlen=seqlen;
  functions->ntiles=ntiles;

}

/*
This function runs the tiling functions located in the Functions class.
Which function is run depends on the user input variable "task".
*/
void TT::run()
{
  FILE * fh_out; // Output file for writing the tiles
  fh_out = fopen("TILES","w");
  
  if (task==1){
  
    // Declare output of function
    Container *list;
    
    // Call function with timer
    timer->reset();
    list = functions->task1(sequence);
    timer->print_elapsed();
    
    // Print the contents
    for (int i=0; i<ntiles; i++){
      for (int j=0; j<k; j++){
        fprintf(fh_out, "%c", list[i].tile[j]);
      }
      fprintf(fh_out, "\n");
    }    
    
    // Deallocate the list
    memory->deallocate(list);
    
  }
  else if (task==2){
  
    // Declare output of function
    vector<string> list;
    
    // Call function with timer
    timer->reset();
    list = functions->task2(sequence);
    timer->print_elapsed();
    
    // Print the contents
    for (int i=0; i<ntiles; i++){
      fprintf(fh_out, "%s\n", list[i].c_str());
    }
    
  }
  else if (task==3){
  
    // Declare output of function
    vector<string> list;
    
    // Call function with timer
    timer->reset();
    list = functions->task3(sequence);
    timer->print_elapsed();
    
    // Print the contents
    for (int i=0; i<ntiles; i++){
      fprintf(fh_out, "%s\n", list[i].c_str());
    }
    
  }
  else{
    printf(" Undefined task\n");
    exit(1);
  }

  fclose(fh_out);
}

void TT::finalize()
{

  //delete container;
  delete functions;
  delete memory;
  
  memory->deallocate(seq_char);

}

TT::~TT()
{
  delete timer;
};
