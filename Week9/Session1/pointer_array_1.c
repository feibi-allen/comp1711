#include <stdio.h>

int main()
{
    int vector[5] = {1,2,3,4,5};

    int* address;

    address = vector; 

    printf("\n \n address = %p\n", address);

    printf( " vector = %p\n\n",vector);

    printf ("address[1] = %p  ,  vector[1] = %d  \n\n",(address+1),vector[1]);

}