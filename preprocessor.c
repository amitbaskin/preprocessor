#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "preUtils.h"
#include "processArg.h"
#include "openFile.h"
#include "removeComments.h"
#include "includeFiles.h"

int main(int argc, char **argv) {
    char *fileNameC1;
    char *fileNameC2;
    FILE *filenameCPtr = NULL;
    FILE *filenameC1Ptr = NULL;
    FILE *filenameC2Ptr = NULL;
    int result;
    unsigned long len;
    char *first;
    char *fileNameC;
    first = argv[0];
    fileNameC = argv[1];
    len = processArg(argc, argv);
    result = openFile(fileNameC, &filenameCPtr, "r");
    printf("\n%d\n", result);
    fileNameC1 = malloc(len + 2);
    appendToExtension(fileNameC, len, '1', fileNameC1);
    result = openFile(fileNameC1, &filenameC1Ptr, "w+");
    printf("\n%d\n", result);
    removeComments(filenameCPtr, filenameC1Ptr);
    fileNameC2 = malloc(len + 2);
    appendToExtension(fileNameC, len, '2', fileNameC2);
    result = openFile(fileNameC2, &filenameC2Ptr, "w+");
    printf("\n%d\n", result);
    rewind(filenameC1Ptr);
    includeFiles(&filenameC1Ptr, &filenameC2Ptr);
    return 0;
}
