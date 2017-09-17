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

void test(char assertion[], void (*func)(int[], int), int arg[], int size, int expectation[]);
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


void test(char assertion[], void (*func)(int[], int), int arg[], int size, int expectation[]){

    int result[size];
    copy(arg, result, size);
    func(result, size);

    if(int_array_equal(result, expectation, size)){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected :  "); print_int_array(expectation, size);
        printf("    But got  :  "); print_int_array(result, size);
    }
}

/*
* End test setup and begin implementation
*/

void increment_integer_array(int a[], int size);
void increment_integer_array(int a[], int size){

    int carry = 1;

    for(int i = size-1; i>= 0; i--){
        
        a[i] += carry;
        if(a[i] > 9){
            carry = 1;
            a[i] = 0;
        }else{
            break;
        }
    }

    // if(a[0] == 10) expand the array by one and return pow(10, size + 1)

}


int main(){

    int t1[3] = {1, 2, 0};
    int r1[3] = {1, 2, 1};

    int t2[3] = {1, 2, 9};
    int r2[3] = {1, 3, 0};

    int t3[3] = {1, 9, 9};
    int r3[3] = {2, 0, 0};

    int t4[4] = {1, 9, 9, 9};
    int r4[4] = {2, 0, 0, 0};

    int t5[2] = {9, 9};
    int r5[3] = {1, 0, 0};

    test("it increments the least significant 0", increment_integer_array, t1, 3, r1);
    test("it increments the least significant 9", increment_integer_array, t2, 3, r2);
    test("it carries multiple 9s", increment_integer_array, t3, 3, r3);
    test("it carries multiple 9s and 0s", increment_integer_array, t4, 4, r4);
    test("it increases magnitude when it has to", increment_integer_array, t5, 2, r5); // <-- what's the best way to approach this in C?
        // a) allocate a result array and return a pointer
        // b) pass in a result array that is size+1 and return void

    return 0;
}