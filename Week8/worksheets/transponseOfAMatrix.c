#include <stdio.h>

void printMatrix(int array[2][3]){
    for (int i = 0;i<2;i++){
        for (int j = 0; j<3; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void transpose(int array[2][3]){
    int temp = array[1][2];
    array[1][2] = array[0][0];
    array[0][0] = temp;
}

int main(){
    int array[2][3] = {{1,2,3},{4,5,6}};
    printMatrix(array);
    transpose(array);
    printf("\n");
    printMatrix(array);
    return 0;
}