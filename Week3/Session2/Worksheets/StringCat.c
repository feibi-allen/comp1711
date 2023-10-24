#include <stdio.h>
void main(){
    char stringy[6] = "sjdhf";
    char strin[6] = "dhieh";
    char catString[11] = stringy + strin;
    printf("%s\n", catString);
}