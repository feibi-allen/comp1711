#include <stdio.h>
int lenString(char * myString){
    int len = 0;
    for (int i = 0 ; myString[i]!='\0'; i++){
        len ++;
    }
    return len;
}

char * concatStrings(char * string1, char * string2, char * catString){
    int len = lenString(string1);
    int i;
    for (i = 0; i > len ; i++){
        catString[i] = string1[i];
    }
    for (i = 0; string2[i]!='\0' ; i++){
        catString[len + i] = string2[i];
    }
    catString[i] = '\0';
    return catString;
}

int main(){
    char myString1[5] = "abcd";
    char myString2[5] = "fghi";
    char catString[12];
    concatStrings(myString1, myString2, catString);
    printf("%s\n", catString);
    return 0;
}