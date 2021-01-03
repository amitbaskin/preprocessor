#include <stdio.h>
#include "copyFile.h"

void copyFile(FILE **readFile, FILE **writeFile){
    int chr;
    char real;
    while ((chr = getc(*readFile)) != EOF){
        real = (char) chr;
        putc(chr, *writeFile);
    }
}
