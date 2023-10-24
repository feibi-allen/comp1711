#include <stdio.h>

int lenString(char * myString){
    int len = 0;
    for (int i = 0 ; myString[i]!='\0'; i++){
        len ++;
    }
    return len;
}

void reverseArry(char * myArry){
    int len = lenString(myArry), count=0, i;
    char temp[len];
    for (i = len-1; i>=0; i--){
        temp[count] = myArry[i];
        count++;
    }
    temp[len]='\0';

    for (i = 0; temp[i]!='\0'; i++){
        myArry[i] = temp[i];
    }
    myArry[len] = '\0';
}

int main(){
    char myString[50];
    printf("Give me string: ");
    scanf("%s", myString);
    reverseArry(myString);
    printf("Reverse is %s\n", myString);
    return 0;
}