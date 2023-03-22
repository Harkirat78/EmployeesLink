#include "../include/headerA3.h"


void printAll(struct employee *headLL) {
    if (headLL == NULL) {
        printf("There are currently no employees in the system.\n");
        return;
    }

    printf("Currently, there are:\n");

    int count = 0;
    struct employee *curr = headLL;
    while (curr != NULL) {
        count++;
        printf("Employee #%d:\n", count);
        printf("Employee id: %d\n", curr->empId);
        printf("First name: %s\n", curr->fname);
        printf("Last name: %s\n", curr->lname);
        printf("Dependents [%d]: ", curr->numDependents);
        for (int i = 0; i < curr->numDependents; i++) {
            printf("%s", curr->dependents[i]);
            if (i != curr->numDependents - 1) {
                printf(", ");
            }
        }
        printf("\n");

        curr = curr->nextEmployee;
    }
}

