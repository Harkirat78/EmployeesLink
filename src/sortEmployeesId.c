#include "../include/headerA3.h"

/*
This function sorts and rearranges employees in the linked list based on the employee ID.
Employees with ID's closer to 0 get positioned closer to head, in ascending order

Function name: sortEmployeesId
Input: struct pointer
Reutrns: void
*/
void sortEmployeesId(struct employee *headLL) {

    //checking for empty list
    if (headLL == NULL) {
        return; //end function if true
    }
    //initialize variables
    int swapped; //variable used to keep track of whether any swaps occurred in the current iteration
    a3Emp * ptr1; //struct pointer used to iterate through the linked list
    a3Emp * lptr = NULL; //struct pointer used to keep track of the last swapped element
  
    //loop will iterate till end of linked list and will perform partial bubble-sort on the linked list
    do {
        swapped = 0; //initiallize to 0 as nothing has been sorted yet
        ptr1 = headLL; //point to head of linked list

        //iterate through the linked list, comparing adjacent nodes and swapping them if necessary
        while (ptr1->nextEmployee != lptr) {
            //check if the employee ID is greater than the next employee ID
            if (ptr1->empId > ptr1->nextEmployee->empId) {
                //following blocks of code will swap the data of two nodes

                //swap employee ID
                int tempId = ptr1->empId; //initialize variable temp to the employee ID
                ptr1->empId = ptr1->nextEmployee->empId; //set employee ID to next employee ID
                ptr1->nextEmployee->empId = tempId; //complete the swap 

                //swap first name
                char tempFname[MAX_LENGTH]; //temp string to hold first name
                strcpy(tempFname, ptr1->fname); //copy name to string
                strcpy(ptr1->fname, ptr1->nextEmployee->fname); //copy other employees first name to previous
                strcpy(ptr1->nextEmployee->fname, tempFname); //complete swap

                //swap last name
                char tempLname[MAX_LENGTH]; //temp string to hold last name
                strcpy(tempLname, ptr1->lname); //copy last name to string
                strcpy(ptr1->lname, ptr1->nextEmployee->lname); //copy other employees last name to previous
                strcpy(ptr1->nextEmployee->lname, tempLname); //complete swap

                //swap the number of dependents
                int tempNumDependents = ptr1->numDependents; //initialize temporary to the number of dependents
                ptr1->numDependents = ptr1->nextEmployee->numDependents; //set to the next nodes
                ptr1->nextEmployee->numDependents = tempNumDependents; //complete swap

                //swap depeendent array(names)
                char ** tempDependents = ptr1->dependents; //initialize temporary string for dependents names
                ptr1->dependents = ptr1->nextEmployee->dependents; //copy other dependents name to previous
                ptr1->nextEmployee->dependents = tempDependents; //complete swap

                swapped = 1; //indicate that a swap has occured
            }
            //move to next node/employee in linked list
            ptr1 = ptr1->nextEmployee;
        }
        lptr = ptr1; //set the last swapped element to the current element
    } while (swapped); //repeat the bubble sort until no more swaps occur
}
