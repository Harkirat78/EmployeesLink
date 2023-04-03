#include "../include/headerA3.h"

/*
this function allows the user to manually enter the
employee data from standard input and add their information to the end of the linked list
passed as a parameter to this function. The user enters the fname, lname of the employee. It
then prompts to enter the dependent names one by one

Function name: recruitEmployee
Inputs: struct
Returns: void
*/
void recruitEmployee(a3Emp **headLL) {

    //dynamically allocate space for amount of struct for the new employee 
    a3Emp * newEmp = malloc(sizeof(a3Emp));
    //check if memory allocated successfully
    if (newEmp == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }
    //prompt user for first and last name of the employee
    printf("Enter the first name of the employee: ");
    scanf("%s", newEmp->fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", newEmp->lname);
    printf("\n");

    //generate empId using given rule, empId = (sum of ascii values of characters in the first name) + (length of the employee’s last name
    int sum = 0; //variable to store sum of first calculation
    for (int i = 0; i < strlen(newEmp->fname); i++) {
        sum = sum + (int)newEmp->fname[i]; //cast
    }
    newEmp->empId = sum + strlen(newEmp->lname); //add to the length of employee last name

    //check if empId already exists in LL, generate new empId if necessary
    a3Emp * currEmp = *headLL; //set the current employee to point to the head of the linked list
    //loop will iterate till currEmp reaches NULL
    while (currEmp != NULL) {
        if (currEmp->empId == newEmp->empId) { //check if the employee ID already exists
            newEmp->empId += rand() % 999 + 1;  //add random number between 1 and 999
            currEmp = *headLL;  //start search again from beginning of LL
        } else {
            currEmp = currEmp->nextEmployee; //search through the list of employees
        }
    }
    //initalize to default values
    newEmp->numDependents = 0;
    newEmp->dependents = NULL;

    
    char ans = 'y'; //char variable initalized to 'y' used for the following loop
    //loop will run until user enters any other value besides 'y' and is used to add and store dependents for the specific employee
    while (tolower(ans) == 'y') { //using tolower function from ctype library in case user enters capital Y or lowercase y 
        newEmp->numDependents++; //each employee must have atleast 1 dependent
        //allocate space for the dependent using 2D allocation/array of pointers 
        newEmp->dependents = realloc(newEmp->dependents, sizeof(char*)*newEmp->numDependents);
        newEmp->dependents[newEmp->numDependents - 1] = malloc(sizeof(char)*MAX_LENGTH);
        //prompt user to enter name of dependent and whether they have more than 1
        printf("Enter name of dependent# %d: ", newEmp->numDependents);
        scanf("%s", newEmp->dependents[newEmp->numDependents - 1]); //subtract one since array indexes start at 0
        printf("Do you have any more dependents? ");
        scanf(" %c", &ans);
        printf("\n");
    }
    //check if head is pointing to NULL
    if (*headLL == NULL) {
        *headLL = newEmp; //make head point to the new employee
        newEmp->nextEmployee = NULL; //added to end of list
    //if list is not empty then traverse through the list until currEmp points to the last node of the list
    } else {
        currEmp = *headLL; //make the point to the head
        //loop will iterate till end of linked list and will traverse through the list
        while (currEmp->nextEmployee != NULL) {
            currEmp = currEmp->nextEmployee; //keep pointing to next node till null is reached
        }
        //add newly created employee to end of linked list
        currEmp->nextEmployee = newEmp; 
        newEmp->nextEmployee = NULL;
    }
}


