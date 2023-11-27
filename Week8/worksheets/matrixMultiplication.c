#include <stdio.h>

void printArray(int ROW, int COL, int array[ROW][COL]){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int arrayA[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    int arrayB[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };
    int result[3][3];
    
    printArray(2,3,arrayA);
    printArray(3,2,arrayB);

    
}