#ifndef INCLUDE_FILES_H
#define INCLUDE_FILES_H
#define MAX_ROW_LEN 500
#include <stdio.h>
enum status {OUT, HASH_TAG, I, N, C, L, U, D, E, IN};
void includeFiles(FILE **readFilePtr, FILE **writeFilePtr);
#endif
