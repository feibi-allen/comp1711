#include <stdio.h>
int is_prime(int my_number){
    int prime = 1;
    for (int i = 2; i < my_number; i++ ){
        if (my_number%i == 0){
            prime = 0;
        }
    }
    return prime;
}

int main(){
    int my_number = 7;
    int is_it_prime = is_prime(my_number);
    printf("%d\n", is_it_prime);
    return 0;
}