# TileTrial

Comparing the performance of different methods of tiling a sequence (e.g. DNA sequence).

TileTrial is a framework for comparing the performance of different functions for a *tiling* operation.

A tiling operation is like this: given a string, return a "tile" of that string which is a substring of length `k`. The tiles serve as windows of the original string, shifted by 1.

## Installing TileTrial

In a linux environment, go to `src` and do:

    make clean
    make
    
which creates an executable called `tiletrial`.

## Running TileTrial

Before running, you need a file called `SEQUENCE` that houses a string to be tiled.

In the command line, do:

    tiletrial task k seqlen
   
where
- `task` is an integer declaring which function you run. Currently supports 1, 2, or 3.
- `k` is the length of the tiles.
- `seqlen` is the length of the original sequence.

The program then has two outputs of interest: (1) `TILES` which contain the tiles of the string in `SEQUENCE`, and (2) the elapsed time which can be used to compare the performance of different functions (tasks).

## Current Functions

#### Task 1

Task 1 uses the custom `Container` class, which houses a `char` array. We declare a pointer to the `Container` class. We then allocate its memory to equal the number of tiles, using our custom `Memory` class, specifically the general allocation function [located here](https://github.com/rohskopf/tiletrial/blob/9b881416397595e079908c60b2511649f40e8919/src/memory.h#L16-L30). Then the tiling operation is performed.
```cpp
Container* Functions::task1(string& str)
{
  
  // Declare a pointer to custom container which will house the tiles (see container.cpp)
  Container *container;
    
  // Allocate container of tiles using the custom memory template (see memory.cpp)
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
```

#### Task 2

Task 2 uses `vector<string>` since `std::vector` is a built-in container for any type in the standard library. During the tiling operation, we use the `push_back` function for strings, which is slower than Task 1, but it works.

```cpp
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
```

#### Task 3

Task 3 uses `vector<string>`, like Task 2, but instead of using the slow `push_back` function we use `substr`, which is much faster because of pre-allocation that happens under the hood.

```cpp
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
```

## Examples

Go to `examples` and generate a sequence with 10 million characters:

    python gen_sequence.py 10000000
    
Now run `tiletrial` using one of the existing 3 tasks, e.g. Task 1 with `k=100` and a `10^7` length string:

    tiletrial 1 100 10000000
    
TileTrial will then produce an output like:

    Time Elapsed: 5.01 sec.

Run this a few times with different tasks, record the average time, and repeat using other tasks to compare. We could automate this procedure with a bash/python script to quickly compare the performance of different tasks.

## Extending TileTrial (Adding New Functions to Compare)

If you want to add a new function, simply create a new function in `functions.cpp`, along with the appropriate declaration in `function.h`.

Add your function to the `run` function of `tt.cpp`, where the given timer functions in the code go before and after the function so we can time it.
