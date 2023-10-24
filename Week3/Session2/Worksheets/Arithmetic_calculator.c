#include <stdio.h>
float arithmeticOpp(float num1, float num2, char opp){
    float num3;
    switch (opp)
    {
    case '+':
        num3 = num1+num2;
        break;
    case '-':
        num3 = num1-num2;
        break;
    case '*':
        num3 = num1*num2;
        break;
    case '/':
        num3 = num1/num2;
        break;
    default:
        break;
    }
    return num3;
}

int main() {
    float num1,num2;
    char opp;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    printf("Enter opperator: ");
    scanf("%s", &opp);
    printf("%f\n", arithmeticOpp(num1,num2,opp));
    return 0;
}