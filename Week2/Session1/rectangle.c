#include <stdio.h>
int main() {
    int width;
    int length;
    int area;

    printf("Please input width: ");
    scanf("%d", &width);
    printf("Please enter length: ");
    scanf("%d", &length);

    area = width*length;

    printf("The area is %d\n" , area);

    return 0;

}