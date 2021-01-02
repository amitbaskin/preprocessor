#include <stdio.h>
#include "openFile.h"

int openFile(char *fileName, FILE *fp, char *mode){
    fp = fopen(fileName, mode);
    if (fp == NULL) {
        printf(OPEN_ERR_MSG, fileName);
        return 1;
    } return 0;
}
