/*
Write a function that takes a single int, n, 
and returns 1 if is a numeric palindrome, and
0 if it is not. 

No negative numbers are palindromes. 

See tests for examples. 

Try to avoid coercing the input to a string.
*/

// test setup
#include <stdio.h>
#include <math.h>
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

// implementation
int numeric_palindrome(int input);

int numeric_palindrome(int input){

    if(input < 0)
        return 0;

    int length = (int)(log10(input)) + 1;
    int msd_mask = (int)(pow(10, length -1));
    int left, right;


    for(int i=0; i<length/2; i++){

        left = input / msd_mask;
        right = input % 10;

        if(left != right)
        return 0;

        input %= msd_mask;
        input /= 10;
        msd_mask /= 100;
    }

    return 1;
}

int main(){

    test("it returns true for 0", numeric_palindrome, 0, 1);
    test("it returns true for 1", numeric_palindrome, 1, 1);
    test("it returns true for 7", numeric_palindrome, 7, 1);
    test("it returns true for 11", numeric_palindrome, 11, 1);
    test("it returns true for 121", numeric_palindrome, 121, 1);
    test("it returns true for 333", numeric_palindrome, 333, 1);
    test("it returns true for 10101", numeric_palindrome, 10101, 1);
    test("it returns true for 2147447412", numeric_palindrome, 2147447412, 1);

    test("it returns false for -1", numeric_palindrome, -1, 0);
    test("it returns false for 12", numeric_palindrome, 12, 0);
    test("it returns false for 100", numeric_palindrome, 100, 0);
    test("it returns false for 2147483647", numeric_palindrome, 2147483647, 0);

    return 0;
}
