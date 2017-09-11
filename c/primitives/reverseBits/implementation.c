/*
Write a function that reverses the bits in an int. 

I.e., if the least significant bits are ...01000110, 
the function should return 01100010...

Try not to entirely brute force it by manually
swapping like in swapBits.
*/

#include <stdio.h>
// test setup
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test (char assertion[], int (*func)(int), int l, int expectation);
void test (char assertion[], int (*func)(int), int l, int expectation){

    int result = func(l);

    if(result == expectation){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected %d to equal %d\n", result, expectation);
    }
}

// helper--used only to initialize and precompute some cached vals
int brute_swap(int c);
int brute_swap(int c){

    int result = c;

    if(((result >> 7) & 1) != ((result >> 0) & 1))
        result = result ^ (128 | 1); // last bit and first bit
    
    if(((result >> 6) & 1) != ((result >> 1) & 1))
        result = result ^ (64  | 2); // second-last bit and second bit
    
    if(((result >> 5) & 1) != ((result >> 2) & 1))
        result = result ^ (32  | 4); // third-last bit and third bit

    if(((result >> 4) & 1) != ((result >> 3) & 1))
        result = result ^ (16  | 8); // etc.

    return result;
}

// initializer to cache likely vals
int PRECOMPUTED_SWAPS[255];
void initialize_precomputed_swaps(){
    for(int i = 0; i < 256; i++){
        PRECOMPUTED_SWAPS[i] = brute_swap(i);
    }
}   

// implementation
int reverse_bits(int l);

int reverse_bits(int l){

    int mask = 0xffff;

    // break the 32-bit input into four 8-bit words
    // lookup the inverse of each in the swap cache
    // reassemble 8 bit words in reverse order.
    return  (PRECOMPUTED_SWAPS[ l & mask <<  0 ] << 24 ) |
            (PRECOMPUTED_SWAPS[ l & mask <<  8 ] << 16 ) |
            (PRECOMPUTED_SWAPS[ l & mask << 16 ] <<  8 ) |
            (PRECOMPUTED_SWAPS[ l & mask << 24 ] <<  0 ) ;
}

int main(){

    initialize_precomputed_swaps(); // build a cache of a reverse of every possible 8-bit word

    test("It should reverse 01000110 (70) to 01100010... (1644167168)", reverse_bits, 70, 1644167168);

    return 0;
}
