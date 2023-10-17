#include <stdio.h>
int main() {
    int firstInt;
    int SecondInt;
    int addedInt;

    printf("Input first int: ");
    scanf("%d" , &firstInt);
    printf("Input second int: ");
    scanf("%d" , &SecondInt);

    addedInt = firstInt+SecondInt;

    printf("The sum is %d\n", addedInt);

    return 0;
}