/*
Write a function that takes an array integers ranging from 0 - 9, interprets them as a single
integer and increments the array. You should use O(1) space and O(n) time.
*/

/*
* Begin test setup
*/
#include <stdio.h>
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test(char assertion[], void (*func)(int[], int, int[]), int arg[], int result[], int size, int expectation[]);
void copy(int source[], int dest[], int size);
void print_int_array(int source[], int size);
int int_array_equal(int a[], int b[], int size);

void print_int_array(int source[], int size){
    printf("[");
    for(int i=0; i<size; i++)
        printf(" %d ", source[i]);
    printf("]\n");
}

void copy(int source[], int dest[], int size){
    for(int i=0; i<size; i++)
        dest[i] = source[i];
}

int int_array_equal(int a[], int b[], int size){
    for(int i=0; i<size; i++)
        if(a[i] != b[i])
            return 0;

    return 1;
}


void test(char assertion[], void (*func)(int[], int, int[]), int arg[], int result[], int size, int expectation[]){

    func(arg, size, result);

    if(int_array_equal(result, expectation, size)){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected :  "); print_int_array(expectation, size + 1);
        printf("    But got  :  "); print_int_array(result, size + 1);
    }
}

/*
* End test setup and begin implementation
*/

void increment_integer_array(int a[], int size, int result[]);
void increment_integer_array(int a[], int size, int result[]){

    int carry = 1, i = size - 1;

    for(i = size-1; i>= 0; i--){
        result[i+1] = a[i] + carry;
        if(result[i+1] > 9){
            carry = 1;
            result[i+1] = 0;
        }else{
            carry = 0;
        }
    }

    result[0] = carry ? 1 : 0;
}


int main(){

    int t1[3] = {1, 2, 0};
    int t1output[4];
    int r1[4] = {0, 1, 2, 1};

    int t2[3] = {1, 2, 9};
    int t2output[4];
    int r2[4] = {0, 1, 3, 0};

    int t3[3] = {1, 9, 9};
    int t3output[4];
    int r3[4] = {0, 2, 0, 0};

    int t4[4] = {1, 9, 9, 9};
    int t4output[5];
    int r4[5] = {0, 2, 0, 0, 0};

    int t5[2] = {9, 9};
    int t5output[3];
    int r5[3] = {1, 0, 0};

    test("it increments the least significant 0", increment_integer_array, t1, t1output, 3, r1);
    test("it increments the least significant 9", increment_integer_array, t2, t2output, 3, r2);
    test("it carries multiple 9s", increment_integer_array, t3, t3output, 3, r3);
    test("it carries multiple 9s and 0s", increment_integer_array, t4, t4output, 4, r4);
    test("it increases magnitude when it has to", increment_integer_array, t5, t5output, 2, r5);

    return 0;
}