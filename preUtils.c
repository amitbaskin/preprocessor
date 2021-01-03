#include <stdio.h>
#include "preUtils.h"

void appendToExtension(char *fileName, unsigned long fileNameLength, char extension, char *output){
    int i;
    for (i=0; i<fileNameLength; i++, output++, fileName++){
        *output = *fileName;
    } *output++ = extension;
    *output = '\0';
}

void printFile(FILE *file){
    int chr;
    char real;
    while ((chr = getc(file)) != EOF){
        real = (char) chr;
        putchar(chr);
    }
}
