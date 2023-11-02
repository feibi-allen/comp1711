#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double x;
    double y;
} POINT;

void fillPoints(POINT * pointArry){
    for (int i = 0; i< 11; i++){
        pointArry[i].x = rand();
        pointArry[i].y = rand();
    }
}
void printPoints(POINT * pointArry){
    for (int i = 0; i <11; i++){
        printf("(%lf , %lf)\n", pointArry[i].x, pointArry[i].y);
    }
}

int main(){
    POINT pointArry[11];
    fillPoints(pointArry);
    printPoints(pointArry);
    return 0;
}