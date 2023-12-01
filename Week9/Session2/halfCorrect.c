#include <stdio.h>
#include <stdlib.h>

 typedef struct list {
    int data;
    struct list* next_element;
} list;



int main()
{
    list first_node;

    first_node.data = 5;

    first_node.next_element = (list*) malloc(sizeof(struct list));

    printf("first_node data = %d \n", first_node.data);
   
    printf("first_node next_element address = %p \n", first_node.next_element);

    //printf("first_node data = %d \n", first_node.next_element.data);
    // above doesnt work because it is trying to get data from an address not the object in the address
    // get the data from 'fdaghfkdajg' for example, its just a string of letters and numbers

}