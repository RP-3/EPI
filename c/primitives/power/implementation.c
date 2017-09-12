/*
Write a function that takes a double (x) and an int (y)
and returns a double representing x^y. 

Try to minimise the number of multiplication operations
you use when you do this. 
*/

#include <stdio.h>
// test setup
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test (char assertion[], double (*func)(double, int), double base, int exp, double expectation);
void test (char assertion[], double (*func)(double, int), double base, int exp, double expectation){

    double result = func(base, exp);

    if(result == expectation){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected %f to equal %f\n", result, expectation);
    }
}

/*
Note: Implementation makes use of some clever factoring of powers.
E.g., 
2^5 = 2^4  * 2^1 // if the exponent is odd, it out once to make it even
    = 4^2  * 2^1 // given an even exponent, square the base and half the exponent
    = 16^1 * 2^1 // repeat until the exponent is on
With every time we half the exponent we're halving the number of multiplications
we'd have to do if we did it 'brute forced'. 
*/

double double_power(double x, int y);
double double_power(double x, int y){

    double result = 1.0;
    double base = x;
    int exponent = y;

    if(y < 0){ // if y is negative
        base = 1.0/base; // switch x for 1/x
        exponent = -exponent; // make y positive
    }

    while(exponent){ // while an exponent remains

        if(exponent & 1) // if the exponent is odd
            result *= base; // factor the exponent out into the result
            // Note that this if should only be hit, at maximum, twice--
            // once at the start if the exponent is odd, and always once
            // at the end when the exponent is eventually >> to 1. 


        base *= base; // square the base
        exponent >>= 1; // half the exponent
        // Note that eventually the exponent will be 1, at which point
        // the final answer is calculated
    }

    return result;
}

int main(){

    test("It coerces anything to the power of zero to 1", double_power, 2.0, 0, 1.0);
    test("It coerces anything to the power of 1 to itself", double_power, 2.0, 1, 2.0);
    test("It converts double_power(2.0, 5) = 32", double_power, 2.0, 5, 32.0);
    test("It handles the unary negative int power", double_power, 2.0, -1, 0.5);
    test("It handles general negative int powers", double_power, 2.0, -2, 0.25);
    return 0;
}
