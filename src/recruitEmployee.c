#include "../include/headerA3.h"

void recruitEmployee(struct employee **headLL) {
    // Get employee data from user
    char fname[MAX_LENGTH], lname[MAX_LENGTH];
    printf("Enter the first name of the employee: ");
    scanf("%s", fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", lname);
    
    // Calculate empId
    int sum = 0;
    for (int i = 0; i < strlen(fname); i++) {
        sum += fname[i];
    }
    int empId = sum + strlen(lname);
    
    // Check if empId already exists and add random numbers if necessary
    struct employee *curr = *headLL;
    while (curr != NULL) {
        if (curr->empId == empId) {
            empId += rand() % 999 + 1;
            curr = *headLL; // Start checking from beginning again
        } else {
            curr = curr->nextEmployee;
        }
    }
    
    // Create new employee node and add to end of linked list
    struct employee *newEmp = malloc(sizeof(struct employee));
    if (newEmp == NULL) {
        printf("Error: Out of memory\n");
        return;
    }
    newEmp->empId = empId;
    strcpy(newEmp->fname, fname);
    strcpy(newEmp->lname, lname);
    
    // Get dependent data from user
    char **dependents = malloc(MAX_DEPENDENTS * sizeof(char *));
    if (dependents == NULL) {
        printf("Error: Out of memory\n");
        free(newEmp);
        return;
    }
    int numDependents = 0;
    while (numDependents < MAX_DEPENDENTS) {
        char depName[MAX_LENGTH];
        printf("Enter name of dependent# %d: ", numDependents+1);
        scanf("%s", depName);
        dependents[numDependents] = malloc((strlen(depName)+1) * sizeof(char));
        if (dependents[numDependents] == NULL) {
            printf("Error: Out of memory\n");
            free(newEmp);
            for (int i = 0; i < numDependents; i++) {
                free(dependents[i]);
            }
            free(dependents);
            return;
        }
        strcpy(dependents[numDependents], depName);
        numDependents++;
        char response;
        printf("Do you have any more dependents? ");
        scanf(" %c", &response);
        if (response == 'n' || response == 'N') {
            break;
        }
    }
    printf("You have %d dependents.\n", numDependents);
    
    newEmp->numDependents = numDependents;
    newEmp->dependents = dependents;
    newEmp->nextEmployee = NULL;
    
    if (*headLL == NULL) {
        *headLL = newEmp;
    } else {
        struct employee *curr = *headLL;
        while (curr->nextEmployee != NULL) {
            curr = curr->nextEmployee;
        }
        curr->nextEmployee = newEmp;
    }
    
    printf("Your computer-generated empId is %d\n", empId);
}

