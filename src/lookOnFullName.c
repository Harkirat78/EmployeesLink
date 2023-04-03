#include "../include/headerA3.h"

/*
This function takes input, the full name of the employee, it searches the current LL, and returns the position of this
employee in the current LL.

Function name: lookOnFullName
Inputs: struct, string
Returns: int
*/
int lookOnFullName(struct employee *headLL, char whichName[100]) {

    //check if list is empty if true return -1
    if(headLL == NULL){
        printf("The list is currently empty");
    }
    a3Emp * curr = headLL; //struct pointer points to head of linked list
    int pos = -1; //set initial position to -1
    char fullName[100]; //string is the name for the concatenated full name

    //loop will iterate till end of linked list
    while (curr != NULL) {
        pos++; //increment positon
        //concatenate first and last names to fullName
        strcpy(fullName, curr->fname);
        strcat(fullName, " ");
        strcat(fullName, curr->lname);
        //check if that position node has the same inputted name
        if (strcmp(whichName, fullName) == 0) { //compare with input full name
            return pos; //return the position of the node
        }
        curr = curr->nextEmployee; //point to the next node
    }
    return -1; //if name is not found return -1
}



