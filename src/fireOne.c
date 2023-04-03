#include "../include/headerA3.h"

/*
The user is prompted to give a value between 1 and the total number of employees in the current LL and that specific employee 
in that position will be fired/removed.

Function name: fireOne
Input: double pointer, int
Returns: void
*/
void fireOne (a3Emp ** headLL, int whichOne){

    //check if the list is empty or not and end the function if true end the function
    if(*headLL == NULL){
        printf("The list is currently empty\n\n");
        return;
    }
    a3Emp * temp = *headLL; //struct pointer points to the head of the linked list used temp since we do not want to free head or cause potential memory leaks

    //check if node inputted is 1, if so it is quite simple to remove the employee
    if (whichOne == 1) {
        *headLL = temp->nextEmployee; //point to the first employee
        printf("Employee [Id: %d] fired.\n", temp->empId);
        //free the dependents for first employee
        for (int i = 0; i < temp->numDependents; i++) {
            free(temp->dependents[i]);
        }
        free(temp->dependents);
        free(temp); //remove all data for the first employe
        return; //end function
    }
    //loop will iterate till it reaches n-1 (whichOne-1) node to find the nth node in linked list
    for (int i = 1; temp != NULL && i < whichOne - 1; i++) {
        temp = temp->nextEmployee; //move ot next node
    }
    //if the employee could not be found output and error message
    if (temp == NULL || temp->nextEmployee == NULL) {
        printf("Error: Invalid employee number\n");
        return;
    }
    //block of code removes the nth node from the linked list
    a3Emp * next = temp->nextEmployee->nextEmployee; //points to node of the node after the node to be deleted
    printf("Employee [Id: %d] fired.\n", temp->nextEmployee->empId); //output message to user for which employee was fired
    //free dependents first
    for (int i = 0; i < temp->nextEmployee->numDependents; i++) {
        free(temp->nextEmployee->dependents[i]);
    }
    free(temp->nextEmployee->dependents);
    //then free the employee struct
    free(temp->nextEmployee); //remove that employee/node
    temp->nextEmployee = next; //move to the next node
    temp = NULL;
}
