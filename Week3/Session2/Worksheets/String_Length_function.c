#include <stdio.h>
int lenString(char * myString){
    int len = 0;
    for (int i = 0 ; myString[i]!='\0'; i++){
        len ++;
    }
    return len;
}


int main(){
    char string[15];
    scanf("%s", string);
    int len = lenString(string);
    printf("%d\n", len);
    return 0;
}