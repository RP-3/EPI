/*
The parity of a word is 1 if the number of 1s in the word is odd,
otherwise it is 0. 

For example, the parity of 1011 is 1, and that of 10001000 is 0.

Write a function that computes the parity of an arbitrarily long
byte array. 
*/

#include <stdio.h>

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test (char assertion[], int (*func)(int), int argument, int expectation);
void test (char assertion[], int (*func)(int), int argument, int expectation){

    int result = func(argument);

    if(result == expectation){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected %d to equal %d\n", result, expectation);
    }
}

int parity(int input);
int parity(int input){

    int parity;

    while(input > 0){
        parity = (parity + (input & 1)) % 2;
        input = input >> 1;
    }

    return parity;
}

int main(){

    test("The parity of 1011 is 1", parity, 11, 1);
    test("The parity of 10001000 is 0", parity, 136, 0);

    return 0;
}
