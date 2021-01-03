#include <stdio.h>
#include "removeComments.h"
#include "openFile.h"

enum status {HASH_TAG, I, N, C};

void removeComments(FILE *readFilePtr, FILE *writeFilePtr){
    int chr;
    char real;
    int state = HASH_TAG;
    while ((chr = getc(readFilePtr)) != EOF){
        real = (char) chr;
        switch (state) {
            case HASH_TAG:
                if (chr == '/') state = N;
                else putc(chr, writeFilePtr);
                break;
            case N:
                if (chr == '*') state = I;
                else {
                    putc('/', writeFilePtr);
                    putc(chr, writeFilePtr);
                    state = HASH_TAG;
                } break;
            case I:
                if (chr == '*') state = C;
                break;
            case C:
                if (chr == '/') state = HASH_TAG;
                else state = I;
                break;
            default: putc(chr, writeFilePtr);
        }
    }
}
