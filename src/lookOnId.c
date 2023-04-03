#include "../include/headerA3.h"

/*
This function will take input, an empId, it searches the current LL using the given empId, and returns the position of this
employee in the current LL. For example, position for empId 430 in the current LL is returned.
When printed in main, following information is printed.

Function name: lookOnId
Inputs: struct pointer, int
Returns: int
*/
int lookOnId(struct employee *headLL, int whichEmpId) {

    //check if list is empty if true return -1
    if(headLL == NULL){
        printf("The list is currently empty");
        return -1;
    }
    int position = -1; //variable used return what position the inputted employee's ID is located
    int counter = 0; //variable set to 0 and will be incremented based on where the empID position is (counter is 0 at first since head is position 0)

    //loop will iterate till end if linked list
    while (headLL != NULL) {
        //check if the inputted employee Id is equivalent to that employee 
        if (headLL->empId == whichEmpId) {
            position = counter; //set position to counter as counter represents its positon in indexes
            break; //if the position is found end the loop
        }
        headLL = headLL->nextEmployee; //move to next node of linked list if the position is not found
        counter++; //increment counter to show the position has changed
    }
    return position; //return the position back to main and -1 if it was not found
}


