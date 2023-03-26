#include "../include/headerA3.h"

void recruitEmployee(a3Emp **headLL) {
    a3Emp *newEmp = (a3Emp*)malloc(sizeof(a3Emp));

    printf("Enter the first name of the employee: ");
    scanf("%s", newEmp->fname);

    printf("Enter the last name of the employee: ");
    scanf("%s", newEmp->lname);
    printf("\n");
    // Generate empId using given rule
    int sum = 0;
    for (int i = 0; i < strlen(newEmp->fname); i++) {
        sum += (int)newEmp->fname[i];
    }
    newEmp->empId = sum + strlen(newEmp->lname);

    // Check if empId already exists in LL, generate new empId if necessary
    a3Emp *currEmp = *headLL;
    while (currEmp != NULL) {
        if (currEmp->empId == newEmp->empId) {
            newEmp->empId += rand() % 999 + 1;  // Add random number between 1 and 999
            currEmp = *headLL;  // Start search again from beginning of LL
        } else {
            currEmp = currEmp->nextEmployee;
        }
    }

    newEmp->numDependents = 0;
    newEmp->dependents = NULL;

    char ans = 'y';
    while (tolower(ans) == 'y') {
        newEmp->numDependents++;
        newEmp->dependents = (char**)realloc(newEmp->dependents, newEmp->numDependents * sizeof(char*));
        newEmp->dependents[newEmp->numDependents - 1] = (char*)malloc(MAX_LENGTH * sizeof(char));
        printf("Enter name of dependent# %d: ", newEmp->numDependents);
        scanf("%s", newEmp->dependents[newEmp->numDependents - 1]);
        printf("Do you have any more dependents? ");
        scanf(" %c", &ans);
        printf("\n");
    }

    if (*headLL == NULL) {
        *headLL = newEmp;
        newEmp->nextEmployee = NULL;
    } else {
        currEmp = *headLL;
        while (currEmp->nextEmployee != NULL) {
            currEmp = currEmp->nextEmployee;
        }
        currEmp->nextEmployee = newEmp;
        newEmp->nextEmployee = NULL;
    }

    printf("You have %d dependents.\n\n", newEmp->numDependents);
    printf("Your computer-generated empId is %d\n", newEmp->empId);
}

