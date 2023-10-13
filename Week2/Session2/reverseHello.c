#include <stdio.h>
int main() {
    char str[] = "Hello";
    int length = 0;

    // manually dtermine string length \0 = end of array
    while (str[length] != '\0') {
        length++;
    }
    // print string in reverse, including the null-termination character
    for (int i = length; i >= 0; i--){
        if (str[i] == '\0') {
            printf(" ");
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}