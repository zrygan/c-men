#include "../src/fibonacci.h"

int recurssive_fibonacci(int num){
    if num == 0 return 0;
    else if num == 1 return 0;

    return recurssive_fibonacci(num - 2) + recurssive_fibonacci(num - 1);
}

print("%d", recurssive_fibonacci(3));