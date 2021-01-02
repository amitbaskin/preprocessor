#ifndef OPEN_FILE_H
#include <stdio.h>
#define OPEN_FILE_H
#define OPEN_ERR_MSG "Cannot open file: %s"
int openFile(char *fileName, FILE *fp, char *mode);
#endif
