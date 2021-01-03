#ifndef OPEN_FILE_H
#include <stdio.h>
#define OPEN_FILE_H
#define OPEN_ERR_MSG "\nCannot open file: %s"
#define MALLOC_ERR "\nMemory Allocation Error"
int openFile(char *fileName, FILE **fp, char *mode);
#endif
