#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "openFile.h"

int openFile(char *fileName, FILE **fp, char *mode){
    *fp = fopen(fileName, mode);
    if (*fp == NULL) {
        printf(OPEN_ERR_MSG, fileName);
        perror(fileName);
        return 1;
    } return 0;
}
