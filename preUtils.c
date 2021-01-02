#include "preUtils.h"

void appendToExtension(char *fileName, unsigned long fileNameLength, char extension, char *output){
    int i;
    for (i=0; i<fileNameLength; i++, output++, fileName++){
        *output = *fileName;
    } *output++ = extension;
    *output = '\0';
}
