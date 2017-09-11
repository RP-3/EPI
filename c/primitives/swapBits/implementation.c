/*
Write a function that takes a 64-bit long and two int indices. 
It should swap the bits in the Long at the two indices, and 
return the resulting Long.

E.g., 01001001 swapped and indices 1 and 6 becomes 00001011
                                                   .^....^.
*/

#include <stdio.h>

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test (char assertion[], long (*func)(long, int, int), long l, int a, int b, long expectation);
void test (char assertion[], long (*func)(long, int, int), long l, int a, int b, long expectation){

    long result = func(l, a, b);

    if(result == expectation){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected %ld to equal %ld\n", result, expectation);
    }
}

long swap_bits(long l, int i, int j);
long swap_bits(long l, int i, int j){

    // if the bits at i and j are the same
    if(((l >> i) & 1) == ((l >> j) & 1))
        // do nothing to the input
        return l;

    return l ^ ((1l << i) | (1l << j));
}

int main(){

    test("It should correctly swap 01001001 (73) at 1 and 6 to 00001011 (11)", swap_bits, 73, 1, 6, 11);
    test("It should correctly swap 01000110 (70) at 0 and 7 to 01000110 (70)", swap_bits, 70, 0, 7, 70);
    return 0;
}
