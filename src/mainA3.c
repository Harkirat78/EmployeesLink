#include "../include/headerA3.h"

/*
this program is for a company and provides a flexible and efficient way to allow
users to easily add, edit, and remove employee information as needed. The function utilizes a linked list
to store numerous employees along with their data and provides an efficient menu that provides multiple options
such as added, removing, printing employees from a linked list.
*/
int main(int argc, char * argv[]) {

    a3Emp * headLL = NULL; //initalize the head of the linked list to point to NULL

    //use helperA3.c files function to help load data for 4 employees
    loadEmpData(&headLL, argv[1]);

    int position; //variable used in case 3 for function 3 to store user input for the desired position for the employee
    int empId; //variable used in case 4 for function 4 to store user input for the employee ID
    int position2; //variable used in case 4 for function 4 to store returned value for position based on employee ID
    char fullName[100]; //string variable used in case 5 for function 5 to store user input for the full name of the desired employee
    int result; //variable used in case 5 for function 5 to store returned value for function 5
    int counter; //variable used in case 6 for function 6 and stores its returned value
    int employeeNum; //variable used in case 8 for function 8 stores user input for employee Id based on which employee the user wishes to remove
    char confirm; //char variable used in case 9 for function 9 to store user input to confirm if they are sure to remove all employees from list

    int option; //variable will store user input for the option they enter based on the menu

    //do-while loop will iterate until user enters 10 to stop the loop
    do {
        //block of print statements output the 10 options the user can select
        printf("Welcome to the Employee Management System\n");
        printf("Please choose an option:\n");
        printf("1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n");

        scanf("%d", &option); //obtain user input 

        //switch-case statements used for conditions
        switch(option) {
            //option 1 will simply call first function
            case 1:
                recruitEmployee(&headLL);
                break;
            //option 1 will simply call first function
            case 2:
                printAll(headLL);
                break;
            //option 3 will print data of the nth employee
            case 3:
                printf("\nEnter a position: "); //prompt user for position
                scanf("%d", &position);
                printf("\n");
                printOne(headLL, position); //print the detials for that employee based on position
                break;
            //option 4 will search for employee based on empId
            case 4:
                printf("Enter an employee ID: "); //prompt user for ID
                scanf("%d", &empId);

                position2 = lookOnId(headLL, empId); //store return value from function
                //check if employee position is found
                if (position2 == -1) {
                    printf("Employee with ID %d not found.\n", empId);
                } else {
                    a3Emp * current = headLL; //struct pointer used to iterate through list
                    //loop will iterate for amount of position/till reached
                    for (int i = 0; i < position2; i++) {
                        current = current->nextEmployee; //point to next
                    }
                    //print employee details
                    printf("\nEmployee id: %d\n", current->empId);
                    printf("First name: %s\n", current->fname);
                    printf("Last name: %s\n", current->lname);
                    printf("Dependents: ");
                    //loop will iterate for amount of dependents for that employee
                    for (int i = 0; i < current->numDependents; i++) {
                        printf("%s", current->dependents[i]); //print dependent name
                        //check if it is last dependent and add semicolon 
                        if (i < current->numDependents - 1) { 
                            printf(", ");
                        }
                    }
                    printf("\n");
                }
                break;
            //option 5 will search for employee based on full name
            case 5:
                printf("Enter the full name of the employee: "); //prompt for full name

                int c; //variable to clear input buffer to allow proper input
                while ((c = getchar()) != '\n' && c != EOF); //clear input buffer

                fgets(fullName, 100, stdin); //obtain full name
                fullName[strlen(fullName)-1] = '\0'; //remove trailing newline char

                result = lookOnFullName(headLL, fullName); //store return value

                //check if employee found or not
                if (result == -1) {
                    printf("\nEmployee with full name %s not found.\n", fullName);
                } else {
                    //struct pointer used to iterate through list
                    struct employee * emp = headLL;
                    //loop will iterate for amount of result
                    for (int i = 0; i < result; i++) {
                        emp = emp->nextEmployee;
                    }
                    //print employee data
                    printf("\nEmployee id: %d\n", emp->empId);
                    printf("First name: %s\n", emp->fname);
                    printf("Last name: %s\n", emp->lname);
                    printf("Dependents: ");
                    //loop will iterate for amount of dependents for that employee
                    for (int i = 0; i < emp->numDependents; i++) {
                        printf("%s", emp->dependents[i]);
                        //check if it is last dependent and add semicolon 
                        if (i != emp->numDependents - 1) {
                            printf(", ");
                        }
                    }
                    printf("\n\n");
                }
                break;
            //option 6 will count the total number of employees
            case 6:
                counter = countEmployees(headLL); //stores return value 
                printf("Total number of employees = %d\n\n", counter); //output amount
                break;
            //option 7 will sort the employees based on their empId
            case 7:
                sortEmployeesId(headLL); //call function
                printf("\nAfter sorting on empId, the employees are as follows:\n\n");
                printAll(headLL); //output employees list after sorting
                break;
            //option 8 will remove the nth employee in the current LL
            case 8:
                printf("Currently there are %d employees.\n\n", countEmployees(headLL));
                printf("Which employee do you wish to fire - enter a value between 1 and %d: ", countEmployees(headLL)); //prompt user for removable employee
                scanf("%d", &employeeNum);
                fireOne(&headLL, employeeNum); //call function
                printf("There are now %d employees.\n\n", countEmployees(headLL));
                break;
            //option 9 will remove all employees in the current LL
            case 9:
                printf("Are you sure you want to fire everyone: "); //prompt if user confirms they want to fire every employee
                scanf(" %c", &confirm);
                getchar(); //consume newline character
                //check if user is sure
                if (confirm == 'y') {
                    fireAll(&headLL);
                    printf("All fired. Linked list is now empty.\n\n");
                }
                else{
                    printf("Ok, return back to the menu\n\n");
                }
                break;
            //option 10 will exit menu
            case 10:
                printf("Exiting...\n");
                //block of code used to free linked list after user is done with menu
                a3Emp * current = headLL;
                a3Emp * next;
                while (current != NULL) {
                    for (int i = 0; i < current->numDependents; i++) {
                        free(current->dependents[i]);
                    }
                    free(current->dependents);
                    next = current->nextEmployee;
                    free(current);
                    current = next;
                }
                headLL = NULL;
                break;
            //request user to reenter if input is invalid (<0 or >10)
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while(option != 10);

    return 0;
}

