#include "../include/headerA3.h"

/*
This function removes all employees from the linked list.

Function name: fireAll
Input: double pointer to struct employee
Returns: void
*/
void fireAll(a3Emp **headLL) {

    //check if list is empty
    if(headLL == NULL){
        printf("The list is already empty\n");
        return;
    }
    a3Emp * current = *headLL; //struct points to head of linked list
    a3Emp * next; //struct pointer next 

    //loop will iterate till end of linked list
    while (current != NULL) {
        next = current->nextEmployee; //point to the next node of linked list (employees)

        //ffree the dependent strings first
        for (int i = 0; i < current->numDependents; i++) {
            free(current->dependents[i]);
        }
        free(current->dependents); //free the dependent string array itself
        free(current); //free the employee node
        current = next; //repeat this process till list is empty
    }
    //set head to NULL so it does not point to any employee as there are none
    *headLL = NULL;
}

