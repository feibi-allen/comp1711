#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandom(int array[3][4]){
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0; j < 4; j++) {
            array[i][j] = rand() % 10;
        }
    }
}

void printArray(int a[][4] ){
  for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n");
     }
}

int main(){
    int A[3][4];
    int B[3][4];

    fillRandom(A);
    fillRandom(B);

    printArray(A);
    printArray(B);
}
