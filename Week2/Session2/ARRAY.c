#include <stdio.h>
int main() {
    int a [10];
    int count;

    //for loop to populate array
    for (count = 0; count < 10; count++) {
        a[count] = count * 10 + count;

    }
    printf("The first and third elements are %d and %d\n", a[0], a[2]);
    // the * means to get inside the element you pointed to
    printf("For pointers: %d and %d\n", *a ,*(a+2));
    return 0;

}