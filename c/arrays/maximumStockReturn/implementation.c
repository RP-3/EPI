/*
Write a function that takes an array of ints denoting the daily stock price
and returns the maximum profit that could be made by buying and selling one
share of that stock. 

Your solution should work in linear time and constant space.
*/

/*
* Begin test setup
*/
#include <stdio.h>
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test(char assertion[], int (*func)(int[],  int), int a[], int size, int expectation);
void print_int_array(int source[], int size);
int int_array_equal(int a[], int b[], int size);

void print_int_array(int source[], int size){
    printf("[");
    for(int i=0; i<size; i++)
        printf(" %d ", source[i]);
    printf("]\n");
}

int int_array_equal(int a[], int b[], int size){
    for(int i=0; i<size; i++)
        if(a[i] != b[i])
            return 0;

    return 1;
}


void test(char assertion[], int (*func)(int[],  int), int a[], int size, int expectation){

    int result = func(a, size);

    if(expectation == result){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected :  %d", expectation);
        printf("    But got  :  %d\n", result);
    }
}

/*
* End test setup and begin implementation
*/

#include <stdlib.h>

// we could use shorts here instead of ints... 
int maximum_stock_return(int a[], int size);
int maximum_stock_return(int a[], int size){

    int lowestLow = a[0], maxProfit = 0;
    int i;
    
    for(i=0; i<size; i++){

        if(a[i] < lowestLow)
            lowestLow = a[i];

        if((a[i] - lowestLow) > maxProfit)
            maxProfit = a[i] - lowestLow;
    }

    return maxProfit;
}

int main(){

    int t1a1[10] = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    int t1expect = 30; // buy 260, sell 290

    test("It should work on the textbook example", maximum_stock_return, t1a1, 10, t1expect);

    return 0;
}
