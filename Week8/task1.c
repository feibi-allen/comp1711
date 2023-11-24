#include <stdio.h>

void printArray(int a[][4] ){
  for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}

void changeMatrix(int array[][4], int col, int row, int value){
    array[row][col] = value;
}

int main(){

    int array[3][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    
    printArray(array);

    int colIndexToChange = 1;
    int rowIndexToChange = 1;
    int valueToChangeto = 5;
    
    changeMatrix(array,colIndexToChange,rowIndexToChange,valueToChangeto);

    printArray(array);

    return 0;

}

