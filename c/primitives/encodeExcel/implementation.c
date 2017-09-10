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

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

#define offset 64

void test (char assertion[], int (*func)(char[]), char argument[], int expectation);
void test (char assertion[], int (*func)(char[]), char argument[], int expectation){

    int result = func(argument);

    if(result == expectation){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Expected %d to equal %d\n", result, expectation);
    }
}

int encode_excel(char input[]);

int encode_excel(char input[]){

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

    test("The encoded value of of A is 1", encode_excel, "A", 1);
    test("The encoded value of of Z is 26", encode_excel, "Z", 26);
    test("The encoded value of of AA is 27", encode_excel, "AA", 27);
    test("The encoded value of of AB is 28", encode_excel, "AB", 28);
    test("The encoded value of of BA is 677", encode_excel, "BA", 53);

    return 0;
}
