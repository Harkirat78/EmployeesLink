#include "../include/headerA3.h"

/*
This function takes a sequence
number (i.e., an int) as input and prints the data of the employee at that position in the current
LL, assuming that the head of the linked list is at position 1.

Function name: printOne
Inputs: struct pointer, int
Returns: void
*/
void printOne(a3Emp *headLL, int whichOne) {

    //check if the head of the linked list is NULL which means there are no employees in the list
    if (headLL == NULL) {
        printf("There are currently no employees in the system.\n");
        return; //exit the function
    }
    //new current struct pointer used to point to head of linked list
    a3Emp * current = headLL;
    int count = 1; //variable count initalized to 1 used to find inputted position

    //loop will iterate from head to tail of list and traverse the linked list to find the employee at the specified position
    while (current != NULL) {
        //check if count is equal to the given position
        if (count == whichOne) {
            //print content for employee (everything in that node besides address)
            printf("Employee id: %d\n", current->empId);
            printf("First name: %s\n", current->fname);
            printf("Last name: %s\n", current->lname);
            printf("Dependents: ");
            //loop will iterate through all dependencies for that particular employee and prints there names accordingly
            for (int i = 0; i < current->numDependents; i++) {
                printf("%s", current->dependents[i]);
                //check if its the last dependecy or not and adds comman accordingly
                if (i < current->numDependents - 1) {
                    printf(", ");
                }
            }
            printf("\n\n");
            return; //end the function
        }
        current = current->nextEmployee; //move current to point to next employee node
        count++; //increment count by 1
    }
    //if the specified position is out of range, print an error message
    printf("Error: position out of range.\n");
}

