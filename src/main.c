#include <stdio.h>
#include "include/fibonacci.h"
#include "include/c_men.h"
#include <time.h>

int main() {
    int cache_size = 100;
    
    // Memoize the Fibonacci function
    MemoizationState* memoize_state = prepare(recursive_fibonacci, cache_size);
    

    // Measure time for memoized Fibonacci
    clock_t start, end;
    double elapsed;
    int N;
    scanf("%d", &N);
    
    start = clock();
    printf("MEM = %lld\n", memoization(N, memoize_state));  // Use the memoized function with context
    end = clock();
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("MEM :: %lf\n", elapsed);

    // Measure time for dynamic programming Fibonacci
    start = clock();
    printf("DP = %lld\n", dynamic_programming_fibonacci(N));
    end = clock();
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("DP :: %lf\n", elapsed);

    // Measure time for dynamic programming Fibonacci
    start = clock();
    printf("BF = %lld\n", recursive_fibonacci(N));
    end = clock();
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("BF :: %lf\n", elapsed);
    
    // Cleanup memoization state
    cleanup(memoize_state);

    return 0;
}
