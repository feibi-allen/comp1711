#include <stdio.h>
int CircleArea(float radius) {
        float area;
        area = 3.14159*radius*radius;
        return area;
}

int main(){
    float radius = 10;
    float area = CircleArea(radius);
    printf("%f", area);
    return 0;
}