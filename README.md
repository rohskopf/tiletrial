# TileTrial

Comparing the performance of different methods of tiling a sequence (e.g. DNA sequence).

A tiling operation is like this: given a string, return a "tile" of that string which is a substring of length `k`. The tiles serve as windows of the original string, shifted by 1.

### Installing TileTrial

In a linux environment, go to `src` and do:

    make clean
    make
    
which creates an executable called `tiletrial`.

### Running TileTrial

Before running, you need a file called `SEQUENCE` that houses a string to be tiled.

In the command line, do:

    tiletrial task k seqlen
   
where
- `task` is an integer declaring which function you run. Currently supports 1, 2, or 3.
- `k` is the length of the tiles.
- `seqlen` is the length of the original sequence.

The program then outputs `TILES` which contain the tiles of the string in `SEQUENCE`.

### Current Functions

```cpp
int main() {
  int y = SOME_MACRO_REFERENCE;
  int x = 5 + 6;
  cout << "Hello World! " << x << std::endl();
}
```

### Examples

Go to `examples` and generate a sequence with 10 million characters:

    python gen_sequence.py 10000000
    
Now run `tiletrial` using one of the existing 3 tasks:

    tiletrial 1 100 10000000
    
Record the time and run using the other tasks to compare.

### Extending TileTrial

If you want to add a new function, simply create a new function in `functions.cpp`, along with the appropriate declaration in `function.h`.

Add your function to the `run` function of `tt.cpp`, where the given timer functions in the code go before and after the function so we can time it.
