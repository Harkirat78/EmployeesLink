#include "../include/headerA3.h"

int main(int argc, char * argv[]) {

    struct employee *headLL = NULL;

    char fileName[MAX_LENGTH];
    strcpy(fileName, argv[1]);

    loadEmpData(&headLL, fileName);
    recruitEmployee(&headLL);
    printAll(headLL);
    //fireAll(&headLL);

    return 0;
}
