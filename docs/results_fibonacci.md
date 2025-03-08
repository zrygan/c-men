# Results of `C-MEN` for the Fibonacci Sequence 

> Zhean Robby Ganituen [<`zrygan`>](https://github.com/zrygan/) <br>
> March 2025

Analysis of C-MEN function memoizer on the algorithms for the n-th Fibonacci Sequence.

## Preliminaries

The n-th Fibonacci Sequence can be solved using two approaches:

1. **Recursive** where you will recursively solve Fibonacci(n - 1) + Fibonacci(n - 2) until you get to the desired number.

2. **Button-Up Dynamic Programming** that uses an iterative approach to get to the desired number, skipping steps in the iteration that has been previoussly solved.

### Implementation:

Below are the pseudocode of the Recursive and Dynamic Programming approach:

```
Recursive-Fibonacci (n)
    IF n < 0. RETURN
    IF N <= 1. RETURN n

    RETURN Recursive-Fibonacci(n - 1) + Recursive-Fibonacci(n - 2)
```

1. `Recursive-Fibonacci` wastes a lot of computational time since it will always re-calculate "sub-steps" which were already calculated.
2. Space complexity: O(*n*) where *n* is the depth of the recursion.
3. Time complexity: O(*2^n*) since the function splits into two recursive call for every function call.


```
DP-Fibonacci (n)
    IF n < 0. RETURN
    IF n <= 1. RETURN n

    solutions <- an array of size n + 1

    solutions[0] <- 0
    solutions[1] <- 1

    FOR i = 2 to n DO
        solutions[i] = solutions[i - 2] + solutions[i - 1]
    
    RETURN solutions[n]
```
1. `DP-Fibonacci` wastes a lot of computational time since it will always re-calculate "sub-steps" which were already calculated.
2. Space and Time complexity: O(*n*) since it stores the answers as an array of size *n* and it iterated from 2 to *n*.

The `C` implementation of both functions are in `src/fibonacci.c`.

## A Posteriori Analysis

We tested the performance of the Fibonacci Sequence algorithms with the `C-MEN` memoization function. The following test code measures and compares the execution time of the memoized, dynamic programming, and recursive Fibonacci functions.

```c
int cache_size = 100;
    
// Memoize the Recursive Fibonacci algorithm
MemoizationState* memoize_state = prepare(recursive_fibonacci, cache_size);

// Measure time for memoized Fibonacci
// uses #include <time.h>
clock_t start, end;
double elapsed;

// A POSTERIORI FOR C-MEN
start = clock();
printf("MEM = %lld\n", memoization(30, memoize_state));  
end = clock();
elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("MEM :: %lf\n", elapsed);

// A POSTERIORI FOR DP-Fibonacci
start = clock();
printf("DP = %lld\n", dynamic_programming_fibonacci(30));
end = clock();
elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("DP :: %lf\n", elapsed);

// A POSTERIORI FOR Recursive-Fibonacci
start = clock();
printf("BF = %lld\n", recursive_fibonacci(30));
end = clock();
elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("BF :: %lf\n", elapsed);

// Cleanup memoization state
cleanup(memoize_state);
```

## Results
The memoized approach optimizes the recursive Fibonacci function by storing intermediate results. This significantly reduces redundant calculations and drastically improves performance for larger values of n. The cache size parameter ensures that intermediate results up to a certain limit are stored for efficient lookups.

### Performance Comparison

The results are obtained by averaging the execution time over 10 runs of each algorithm for a given value of `n`.

```
Test 1 [n = 30]
C-MEN               : 0.001000
Recursive-Fibonacci : 0.001000
DP-Fibonacci        : 0.010000

Test 2 [n = 55]
C-MEN               : 0.001000
Recursive-Fibonacci : 0.000000
DP-Fibonacci        : 0.007000
```