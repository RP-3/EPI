/*
Write a function that takes a sorted array of integers and removes duplicate
entries from it. It should return the number of elements removed. 
*/

/*
* Begin test setup
*/
#include <stdio.h>
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test(char assertion[], int (*func)(int[],  int), int a[], int size, int expectation[]);
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


void test(char assertion[], int (*func)(int[],  int), int a[], int size, int expectation[]){

    func(a, size);

    if(int_array_equal(a, expectation, size)){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected :  "); print_int_array(expectation, size);
        printf("    But got  :  "); print_int_array(a, size);
    }
}

/*
* End test setup and begin implementation
*/

#include <stdlib.h>

void swap_ints(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// we could use shorts here instead of ints... 
int deduplicate_int_array(int a[], int size);
int deduplicate_int_array(int a[], int size){

    int i;
    int j = 0;

    // overwrite duplicate values
    for(i=1; i < size; i++)
        if(a[i] != a[j])
            a[++j] = a[i];

    // reset extra spaces to 0
    for(i=1; i < (size - j); i++)
        a[size - i] = 0;

    return size - j;
}


int main(){

    int t1a1[9] = {2, 3, 5, 5, 7, 11, 11, 11, 13};
    int t1expect[9] = {2, 3, 5, 7, 11, 13, 0, 0, 0};

    test("It should dedupe the basic example", deduplicate_int_array, t1a1, 9, t1expect);

    return 0;
}
