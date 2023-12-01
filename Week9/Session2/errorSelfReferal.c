#include <stdio.h>

 struct list {
    int data;
    struct list next_element;
};

int main()
{
    struct list first_node;
    // Run this program. Learn from the error. 

    // Why the error. 

    // list creats a new node in each list struct
    // this results in an infinitly large list as there is no end point
    // list* next_element will create address of next node instead of new node

}