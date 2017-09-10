/*
In excel and other spreadsheet software, columns are encoded by letters.
I.e., column A refers to column 1, column Z refers to column 26. 

Column encodings can be multiple characters
I.e., column AA refers to column 27, column AB to column 28 etc.

Write a function that takes an alphabet string and returns its corresponding column number as an integer

Hint: It's probably helpful to understand how the base system works. http://en.wikipedia.org/wiki/Positional_notation
*/

#include <string.h>
#include <stdio.h>

#define offset 64

int implementation(char input[]);

int implementation(char input[]){

    int result = 0;
    int index = strlen(input) - 1;
    int column_multiplier = 1;

    while(index >= 0){
        result += ((input[index] - offset) * column_multiplier);
        column_multiplier *= 26;
        index--;
    }

    return result;
};

int main(){

    char test[] = "AB";
    int result = implementation(test);
    printf("%d\n", result);
    return 0;
}
