#include "include/c_men.h"
#include <stdio.h>

void memoization_longlong(LongLongFunction func, int input){
    printf("%lld", func(input));
}