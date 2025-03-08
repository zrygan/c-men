#include "include/fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

long long recursive_fibonacci(int num) {
    if (num < 0) return -1;
    else if (num <= 1) return num;

    return recursive_fibonacci(num - 1) + recursive_fibonacci(num - 2);
}

/**
 * Calculates the num-th number in the fibonacci sequence using 
 * DYNAMIC PROGRAMMING
 * 
 * @params:
 *  num:    the num-th number of the fibonacci sequence
 *  dp:     the dynamic programming array of the fibonacci sequence
 * 
 * @return:
 *  num-th number in the fibonacci sequence 
 * 
 * @constrains:
 *  dp must be sorted such that dp[n-1] is the nth fibonacci number 
 */
long long dynamic_programming_fibonacci(int num){
    if (num < 0) return -1;
    else if (num <= 1) return num;

    long long *dp = malloc(sizeof(long long) * (num + 1));
    if (dp == NULL) return -1;

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= num; ++i){
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    
    long long res = dp[num];
    free(dp);
    return res;
}
