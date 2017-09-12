/*
Write a function that reverses the digits in an int. 

I.e., if the input is 1132, the function should return
2311 as an int.

Try to solve this without ever converting the input
to a string. 
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

// implementation
int reverse_digits(int input);
int reverse_digits(int input){

    int result = 0;
    int sign = 1;

    if(input < 0){
        sign = -1;
        input = -input;
    }
    
    while(input){
        
        result = (result * 10) + (input % 10);
        input = input / 10;
    }
    
    return sign * result;
}

int main(){

    test("It should reverse 1132 to 2311", reverse_digits, 1132, 2311);
    test("It handles inputs with 0s", reverse_digits, 1102, 2011);
    test("It retains the input's sign", reverse_digits, -1234, -4321);
    test("It works for odd numbers of negative digist", reverse_digits, -12345, -54321);

    return 0;
}
