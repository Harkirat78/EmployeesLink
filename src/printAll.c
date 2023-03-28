#include "../include/headerA3.h"


void printAll(struct employee *headLL) {
    //check if the head of the linked list is NULL
    if (headLL == NULL) {
        printf("There are currently no employees in the system.\n");
        return;
    }

    //print a message indicating the function is listing the employees
    printf("Currently, there are:\n");

    //initialize a counter for employees
    int count = 0;

    //start from the head of the list
    a3Emp *curr = headLL;

    //loop through the list and print details of each employee
    while (curr != NULL) {
        //increment the employee counter
        count++;
        //print employee details
        printf("Employee #%d:\n", count);
        printf("\tEmployee id: %d\n", curr->empId);
        printf("\tFirst name: %s\n", curr->fname);
        printf("\tLast name: %s\n", curr->lname);
        printf("\tDependents [%d]: ", curr->numDependents);
        //loop iterates over dependents array and prints their names
        for (int i = 0; i < curr->numDependents; i++) {
            printf("%s", curr->dependents[i]);
            //check if current dependent is last in array and add commas accordingly
            if (i != curr->numDependents - 1) {
                printf(", ");
            }
        }
        printf("\n\n");

        //move to the next employee in the list
        curr = curr->nextEmployee;
    }
}
