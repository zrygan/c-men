#ifndef C_MEN_H
#define C_MEN_H

/**
 * a function data type for functions where:
 *  input:  int 
 *  output: long long
 */
typedef long long (*LongLongFunction)(int);

void memoization_longlong(LongLongFunction func, int input);

#endif