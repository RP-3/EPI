/*
Write a function that when given two rectangles (as defined by 
the struct below) will return the minimum overlapping
rectangle between the given inputs. 

Rectangles are considered overlaping even if they share an edge.

If there is no overlap between the inputs, return a rectangle
with coordinates at the origin and a width and height of -1
*/

struct Rectangle {
    int x, y, width, height;
};

/*
*   Test setup
*/
#include <stdio.h>
#include <math.h>
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void test (char assertion[], struct Rectangle (*func)(struct Rectangle, struct Rectangle), struct Rectangle a, struct Rectangle b, struct Rectangle expectation);
void test (char assertion[], struct Rectangle (*func)(struct Rectangle, struct Rectangle), struct Rectangle a, struct Rectangle b, struct Rectangle expectation){

    struct Rectangle result = func(a, b);

    if(
        result.x == expectation.x ||
        result.y == expectation.y ||
        result.width == expectation.width ||
        result.height == expectation.height
    ){
        printf("%s %s \u2713 %s\n", assertion, KGRN, RESET);
    }else{
        printf("%s %s \u2717 %s\n", assertion, KRED, RESET);
        printf("    Detected diff:");
        printf("    Expecting %d to equal %d\n", result.x, expectation.x);
        printf("    Expecting %d to equal %d\n", result.y, expectation.y);
        printf("    Expecting %d to equal %d\n", result.width, expectation.width);
        printf("    Expecting %d to equal %d\n", result.height, expectation.height);
    }
}

/*
*   Begin solution
*/

#include <stdlib.h>

int rectangles_overlap(struct Rectangle a, struct Rectangle b);

int rectangles_overlap(struct Rectangle a, struct Rectangle b){

    if(
        (a.x + a.width ) < b.x || // a ends before b starts (x axis)
        (b.x + b.width ) < a.x || // a starts after b ends (x axis)
        (a.y + a.height) < b.y || // a ends before b starts (y axis)
        (b.y + b.height) < a.y    // a starts after b ends (y axis)
    )
        return 0;

    return 1;
}

// comparison function for sorting
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

struct Rectangle rectangle_intersection(struct Rectangle a, struct Rectangle b);

struct Rectangle rectangle_intersection(struct Rectangle a, struct Rectangle b){

    if(rectangles_overlap(a, b) == 0) // exit if rectangles don't overlap
        return (struct Rectangle){ .x = 0, .y = 0, .width = -1, .height = -1 };

    // get the x and y coords of the two rectangles in sorted order
    int x_coords[] = { a.x, a.x + a.width, b.x, b.x + b.width };
    int y_coords[] = { a.y, a.y + a.height, b.y, b.y + b.height };
    qsort (x_coords, 4, sizeof(*x_coords), comp);
    qsort (y_coords, 4, sizeof(*y_coords), comp);

    /*
    * The minimum overlap between two rectangles is the smallest rectangle that can be
    * made with the eight points provided. That, in turn, is the inner two points of the
    * four points on each axis. We can find this by sorting the x-axis points and y-axis
    * points (in asc or desc order) and taking the middle two to be those of our 
    * resulting minimum-overlapped rectangle.
    */

    return (struct Rectangle){ .x = x_coords[1], .y = y_coords[1], .width = x_coords[2] - x_coords[1], .height = y_coords[2] - y_coords[1] };
}

/*
*   Test execution
*/
int main() {

    struct Rectangle a = { .x = 0, .y = 0, .width = 1, .height = 1 };
    struct Rectangle b = { .x = 1, .y = 1, .width = 4, .height = 3 };
    struct Rectangle c = { .x = 4, .y = 0, .width = 1, .height = 5 };
    struct Rectangle e = { .x = 9, .y = 9, .width = 1, .height = 1 };

    struct Rectangle null_rect = { .x = 0, .y = 0, .width = -1, .height = -1 };
    struct Rectangle unit_rect = { .x = 1, .y = 1, .width = 0, .height = 0 };
    struct Rectangle result_rect = { .x = 4, .y = 1, .width = 1, .height = 3 };

    test("it does not detect an overlap where none exists", rectangle_intersection, a, e, null_rect);
    test("it detects a shared corner and returns a unit rectangle", rectangle_intersection, a, b, unit_rect);
    test("it detects a shared area and returns the minimum overlapped rectangle", rectangle_intersection, b, c, result_rect);

    return 0;
}

