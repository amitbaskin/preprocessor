#include <stdio.h>
#include <string.h>
#include "processArg.h"

unsigned long processArg(int argc, char **argv){
    char *fileName;
    unsigned long fileNameLength;
    int i;
    if (argc != 2) {
        printf(USAGE_MSG);
        return 0;
    } fileName = argv[1];
    fileNameLength = strlen(fileName);
    for (i=0; i<fileNameLength; i++){
        if (fileName[i] == '.' && i == fileNameLength-2){
            if (fileName[++i] == 'c') return fileNameLength;
            else {
                printf(USAGE_MSG);
                return 0;
            }
        }
    } printf(USAGE_MSG);
    return 0;
}
