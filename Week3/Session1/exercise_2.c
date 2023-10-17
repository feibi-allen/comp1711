#include <stdio.h>
int main() {
    int num;
    printf("Input number: ");
    scanf("%d", &num);
    if ((num % 4 == 0) && (num % 5 == 0))
    {
        printf("U good\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}