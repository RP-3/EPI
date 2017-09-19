/*
Write a function that takes two arrays of integers ranging from 0 - 9, interprets them as a single
integers and multiplies them together. You should use O(n) space.
*/

/*
* Begin test setup
*/
#include <stdio.h>
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test(char assertion[], void (*func)(int[], int[], int[], int, int), int a[], int b[], int result[], int sizeA, int sizeB, int expectation[]);
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


void test(char assertion[], void (*func)(int[], int[], int[], int, int), int a[], int b[], int result[], int sizeA, int sizeB, int expectation[]){

    func(a, b, result, sizeA, sizeB);

    if(int_array_equal(result, expectation, sizeA + sizeB)){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected :  "); print_int_array(expectation, sizeA + sizeB);
        printf("    But got  :  "); print_int_array(result, sizeA + sizeB);
    }
}

/*
* End test setup and begin implementation
*/

#include <stdlib.h>

// we could use shorts here instead of ints... 
void multiply_int_arrays(int a[], int b[], int result[], int sizeA, int sizeB);
void multiply_int_arrays(int a[], int b[], int result[], int sizeA, int sizeB){

    int resultSize = sizeA + sizeB;
    int i, j, k, currentDigit, carry = 0, offset = 1;

    for(i = sizeA - 1; i >= 0; i--){

        k = resultSize - offset + 1;

        for(j = sizeB -1; j >= 0; j--){

            k--;

            // work out the current digit we're working with
            // ignore sign for now. Work it out at the end, taking previous carries into account
            currentDigit = (abs(a[i]) * abs(b[j])) + carry;

            if(currentDigit > 9){
                carry = currentDigit / 10;
                currentDigit %= 10;
            }else{
                carry = 0;
            }

            result[k] += currentDigit;
            if(result[k] > 9){
                carry += (result[k] / 10);
                result[k] %= 10;
            }

            if(j == 0 && carry){
                result[k - 1] += carry;
                carry = 0;
            }
        }

        offset++;
    }

    // add a negative sign to the first int if necessary
    if(a[0] * b[0] < 0){
        for(k=0; k<resultSize; k++){
            if(result[k] > 0){
                result[k] = - result[k];
                break;
            }
        }
    }
}


int main(){

    int t1a1[1] = {0};
    int t1a2[1] = {0};
    int t1result[2] = {0, 0};
    int t1expect[2] = {0, 0};
    
    int t2a1[1] = {0};
    int t2a2[2] = {1, 4};
    int t2result[3] = {0, 0, 0};
    int t2expect[3] = {0, 0, 0};
    
    int t3a1[1] = {1};
    int t3a2[2] = {1, 4};
    int t3result[3] = {0, 0, 0};
    int t3expect[3] = {0, 1, 4};
    
    int t4a1[4] = {1, 2, 3, 4};
    int t4a2[4] = {5, 6, 7, 8};
    int t4result[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int t4expect[8] = {0, 7, 0, 0, 6, 6, 5, 2};

    int t5a1[2] = {3, 4};
    int t5a2[2] = {7, 8};
    int t5result[4] = {0, 0, 0, 0};
    int t5expect[4] = {2, 6, 5, 2};

    int t6a1[2] = {-3, 4};
    int t6a2[2] = {7, 8};
    int t6result[4] = {0, 0, 0, 0};
    int t6expect[4] = {-2, 6, 5, 2};

    test("0 * 0 should equal 0", multiply_int_arrays, t1a1, t1a2, t1result, 1, 1, t1expect);
    test("0 * 14 should equal 0", multiply_int_arrays, t2a1, t2a2, t2result, 1, 2, t2expect);
    test("1 * 14 should equal 14", multiply_int_arrays, t3a1, t3a2, t3result, 1, 2, t3expect);
    test("1234 * 5678 should equal 7,006,652", multiply_int_arrays, t4a1, t4a2, t4result, 4, 4, t4expect);
    test("34 * 78 should equal 2,652", multiply_int_arrays, t5a1, t5a2, t5result, 2, 2, t5expect);
    test("-34 * 78 should equal -2,652", multiply_int_arrays, t6a1, t6a2, t6result, 2, 2, t6expect);

    return 0;
}
