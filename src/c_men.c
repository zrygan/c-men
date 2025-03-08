#include "include/c_men.h"
#include <stdlib.h>

long long memoization(int n, MemoizationState* memoization_object) {
    // Error checking
    if (!memoization_object || n < 0 || n > memoization_object->cache_size) {
        return -1;
    }

    // If value is cached
    if (memoization_object->cache[n] != -1) {
        return memoization_object->cache[n];
    }

    // if not yet cached
    if (n == 0) {
        memoization_object->cache[n] = 0;
    } else if (n == 1) {
        memoization_object->cache[n] = 1;
    } else {
        // Compute Fibonacci using memoization to avoid recalculation
        // TODO:    generalize this so that is applicable to other functions
        //          currently it is only the Fibonacci sequence
        memoization_object->cache[n] = memoization(n - 1, memoization_object) 
                                     + memoization(n - 2, memoization_object);
    }

    return memoization_object->cache[n];
}

MemoizationState* prepare(LongLongFunction func, int cache_size) {
    MemoizationState* memoization_object = (MemoizationState*) malloc(sizeof(MemoizationState));
    if (!memoization_object) return NULL; 

    memoization_object->cache = (long long*) malloc((cache_size + 1) * sizeof(long long));
    if (!memoization_object->cache) {
        free(memoization_object);
        return NULL; 
    }

    // Initialize cache with -1 (indicating uninitialized)
    for (int i = 0; i <= cache_size; i++) {
        memoization_object->cache[i] = -1;
    }

    memoization_object->function = func;   
    memoization_object->cache_size = cache_size;
    
    return memoization_object;
}

void cleanup(MemoizationState* memoization_object) {
    if (memoization_object) {
        if (memoization_object->cache) {
            free(memoization_object->cache);
        }
        free(memoization_object);
    }
}
