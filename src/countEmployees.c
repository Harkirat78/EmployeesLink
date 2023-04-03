#include "../include/headerA3.h"

/*
This function will find and return the total amount of employees within the linked list

Function name: countEmployees
Input: struct pointer
Returns: int
*/
int countEmployees(a3Emp *headLL) {

    int count = 0; //variable will hold amount of employees within list

    //check if list is empty and if true return 0
    if(headLL == NULL){
        printf("The list is currently empty");
        return 0;
    }
    a3Emp * current = headLL; //struct pointer points to head of linked list

    //loop will iterate to the end of the linked list
    while (current != NULL) {
        count++; //add 1 for each node/employee 
        current = current->nextEmployee; //move/point to next node
    }
    return count; //return the amount of nodes(employees) back to main
}
