#include <stdio.h>
int str_len(char * string){
    int count = 0;
    int i = 0;
    while (string[i] != '\0'){
        count ++;
        i ++;
    }
    return count;
}

int main(){
    char string[15] = "asjhfyt";
    int len = str_len(string);
    printf("%d\n", len);
    return 0;
}