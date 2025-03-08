#ifndef C_MEN_H
#define C_MEN_H

typedef long long (*LongLongFunction)(int);

/**
 * A struct that holds the memoization state
 */
typedef struct {
    long long* cache;
    LongLongFunction function;
    int cache_size;
} MemoizationState;

/**
 * The memoized function.
 * Takes in a recursive backtracking function and memoizes it doing the recursive
 * calls if needed or accessing the cache if value has already been calculated.
 */
long long memoization(int n, MemoizationState* memoization_object);

/**
 * Prepares a function to be memoized.
 */
MemoizationState* prepare(LongLongFunction func, int cache_size);

/**
 * Cleanup function to free memory allocated for memoization.
 * @param memoization_object: The memoization memoization_object to clean up.
 */
void cleanup(MemoizationState* memoization_object);

#endif
