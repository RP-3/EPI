/*
Write a function that multiplies two positive integers. The only operators
you should use are assignment '=' and bitshifters '>>, <<, |, &, ~, ^'.

You can while-loops, if-statements (if, ||, &&) and functions that you
write yourself. Note: for-loops are a no-no since ++ and -- aren't allowed.

Hint: This is really two problems wrapped into one:
write a helper function that adds two integers together. This should run
in constant time. 

Then consider the multiplication problem separately. It should be possible
to make this, too, run in constant time. 
*/

#include <stdio.h>

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test (char assertion[], int (*func)(int, int), int a, int b, int expectation);
void test (char assertion[], int (*func)(int, int), int a, int b, int expectation){

    int result = func(a, b);

    if(result == expectation){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected %d to equal %d\n", result, expectation);
    }
}

int int_add(int a, int b);
int int_multiply(int a, int b);

int int_add(int a, int b){

    int result = 0;
    int carrying = 0;
    int bit = 1;

    int a_set = 0;
    int b_set = 0;

    while(a > 0 || b > 0 || carrying){

        a_set = (a & 1);
        b_set = (b & 1);

        if(carrying){

            carrying = 0;

            if(a_set & b_set){
                carrying = 1;
                result = result | bit;
            }else 
            if(a_set | b_set){
                carrying = 1;
            }else{
                result = result | bit;
            }
        }else{

            if(a_set & b_set){
                carrying = 1;
            }else 
            if(a_set | b_set){
                result = result | bit;
            }
        }

        a = a >> 1;
        b = b >> 1;
        bit = bit << 1;
    }

    return result;
}

/*
We make use of the fact that
(5 * 10) is the same as 
((1*10) + (4*10)), which is also the same as
( (2*5) + (8*5) ).
*/
int int_multiply(int a, int b){

    int bit = 1, // integer to use as mask
        place = 0, // integer representation of the position of our mask
        result = 0;

    // for all possible bits (factors) of a...
    while(bit > 0){

        // if bit is a factor of a...
        if(a & bit)
            // multiply b by bit and add it to result
            result = int_add(result, b << place);

        bit = bit << 1; // increment the position of our mask
        place = int_add(place, 1); // and keep track of the integer representation of that position
    }

    return result;
}

int main(){

    test("The product of 0 and 0 is 0", int_multiply, 0, 0, 0);
    test("The product of 0 and 1 is 0", int_multiply, 0, 1, 0);
    test("The product of 1 and 0 is 0", int_multiply, 1, 0, 0);
    test("The product of 1 and 1 is 1", int_multiply, 1, 1, 1);
    test("The product of 6 and 5 is 30", int_multiply, 6, 5, 30);

    return 0;
}
