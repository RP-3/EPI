/*
Write a function that takes a pointer to an array of unsigned ints and an
index within that array. The function should partition the array, in place,
into three sections: less than, equal to, and greater than the element at
the given index within the array.
*/

/*
* Begin test setup
*/
#include <stdio.h>
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test (char text[], void (*func)(int, int[], int), int pivot, int arg[], int arg_size);
void copy_array(int source[], int dest[], int size);
void print_int_array(int source[], int size);
int is_partitioned(int a[], int pivot, int size);

void test (char text[], void (*func)(int, int[], int), int pivot, int arg[], int arg_size){

    int pivot_value = arg[pivot];
    int result[arg_size];
    copy_array(arg, result, arg_size);
    func(pivot, result, arg_size);

    if(is_partitioned(result, pivot_value, arg_size)){
        printf("%s %s \u2713 %s\n", text, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", text, KRED, RESET);
        printf("    Failed result:  "); print_int_array(result, arg_size);
    }
}

void print_int_array(int source[], int size){
    printf("[");
    for(int i=0; i<size; i++)
        printf(" %d ", source[i]);
    printf("]\n");
}

void copy_array(int source[], int dest[], int size){
    for(int i=0; i<size; i++)
        dest[i] = source[i];
}

int is_partitioned(int a[], int pivot, int size){
    
    int past_smalls = 0;
    int past_mids = 0;

    for(int i=0; i<size; i++){
        if(!past_smalls){
            if(a[i] >= pivot)
                past_smalls = 1;
        } else if(!past_mids){
            if(a[i] < pivot)
                return 0;
            
            if(a[i] > pivot)
                past_mids = 1;
        } else {
            if(a[i] <= pivot)
                return 0;
        }
    }

    return 1;
}

/*
* End test setup and begin implementation
*/

void swap(int *a, int*b);
void swap(int *a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void dutch_flag_partition(int index, int arg[], int size);

/*
* First approach: partition the array in two passes
*/
void dutch_flag_partition(int index, int arg[], int size){

    int left = 0;
    int right = size - 1;
    int pivot = arg[index];

    // push less-thans to the left
    while(left < right){
        if(arg[left] >= pivot){
            swap(&arg[left], &arg[right--]);
        }else{
            left++;
        }
    }

    right = size - 1;
    left++;

    // push greater-thans to the right
    while(left < right){
        if(arg[left] > pivot){
            swap(&arg[left], &arg[right--]);
        }else{
            left++;
        }
    }
}

/*
* Second approach: partition the array in a single pass
* into pre-determined buckets. 
* Break the array into four subarrays:
* - less than the pivot
* - equal to the pivot
* - undetermined
* - greater than the pivot
* Iterate over the undetermined portion of the array (which is the
* entire array to begin with), shifting each element into its 
* correct bucket, until there is no undetermined portion remaining. 
*/

void dutch_flag_partition(int index, int arg[], int size){

    int pivot = arg[index];
    int smaller = 0; // elements smaller than the pivot placed *before* this index
    int equal = 0; // elements equal to the pivot exist from smaller to equal-1
    int larger = size-1; // elements grater than the pivot exist on and after this index

    while(equal <= larger){
        if(arg[equal] < pivot){
            swap(&arg[smaller++], &arg[equal++]);
        }
        else if(arg[equal] == pivot){
            equal++;
        }else{
            swap(&arg[equal], &arg[larger--]);
        }
    }
}

int main() {

    int test1[14] = { 7, 1, 6, 2, 5, 3, 4, -3, -2, 5, 4, 3, 2, 1 };

    test("The textbook example", dutch_flag_partition, 3, test1, 14);

    test("with an index of 0", dutch_flag_partition, 0, test1, 14);
    test("with an index of 1", dutch_flag_partition, 1, test1, 14);
    test("with an index of 2", dutch_flag_partition, 2, test1, 14);
    test("with an index of 4", dutch_flag_partition, 4, test1, 14);
    test("with an index of 5", dutch_flag_partition, 5, test1, 14);
    test("with an index of 6", dutch_flag_partition, 6, test1, 14);

    return 0;
}
