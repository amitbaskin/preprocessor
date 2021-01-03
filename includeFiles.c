#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "includeFiles.h"
#include "removeComments.h"
#include "copyFile.h"
#include "openFile.h"

enum status {OUT, HASH_TAG, I, N, C, L, U, D, E, IN};

void includeFiles(FILE **readFilePtr, FILE **writeFilePtr){
    char *putBack = malloc(MAX_ROW_LEN);
    char *putBackOriginalPtr = putBack;
    char *includeFileName = malloc(MAX_ROW_LEN);
    char *includeFileNameOriginalPtr = includeFileName;
    FILE *includeFilePtr = NULL;
    int chr;
    char real;
    int state = OUT;
    while ((chr = getc(*readFilePtr)) != EOF){
        real = (char) chr;
        switch (state) {
            case OUT:
                if (chr == '#') {
                    state = HASH_TAG;
                    *putBack++ = (char) chr;
                } else putc(chr, *writeFilePtr);
                break;
            case HASH_TAG:
                if (chr == 'i') {
                    state = I;
                    *putBack++ = (char) chr;
                }
                else {
                    state = OUT;
                    *putBack = '\0';
                    putBack = putBackOriginalPtr;
                    fputs(putBack, *writeFilePtr);
                }
                break;
            case I:
                if (chr == 'n') {
                    state = N;
                    *putBack++ = (char) chr;
                }
                else {
                    state = OUT;
                    *putBack = '\0';
                    putBack = putBackOriginalPtr;
                    fputs(putBack, *writeFilePtr);
                }
                break;
            case N:
                if (chr == 'c') {
                    state = C;
                    *putBack++ = (char) chr;
                }
                else {
                    state = OUT;
                    *putBack = '\0';
                    putBack = putBackOriginalPtr;
                    fputs(putBack, *writeFilePtr);
                }
                break;
            case C:
                if (chr == 'l') {
                    state = L;
                }
                else {
                    *putBack++ = (char) chr;
                    state = OUT;
                    *putBack = '\0';
                    putBack = putBackOriginalPtr;
                    fputs(putBack, *writeFilePtr);
                }
                break;
            case L:
                if (chr == 'u') {
                    state = U;
                    *putBack++ = (char) chr;
                }
                else {
                    state = OUT;
                    *putBack = '\0';
                    putBack = putBackOriginalPtr;
                    fputs(putBack, *writeFilePtr);
                }
                break;
            case U:
                if (chr == 'd') {
                    state = D;
                    *putBack++ = (char) chr;
                }
                else {
                    state = OUT;
                    *putBack = '\0';
                    putBack = putBackOriginalPtr;
                    fputs(putBack, *writeFilePtr);
                }
                break;
            case D:
                if (chr == 'e') {
                    state = E;
                    *putBack++ = (char) chr;
                }
                else {
                    state = OUT;
                    *putBack = '\0';
                    putBack = putBackOriginalPtr;
                    fputs(putBack, *writeFilePtr);
                }
                break;
            case E:
                if (chr == ' ' || chr == '\t') {
                    *putBack++ = (char) chr;
                    break;
                }
                if (chr == '"') {
                    state = IN;
                } else {
                    state = OUT;
                    *putBack = '\0';
                    putBack = putBackOriginalPtr;
                    fputs(putBack, *writeFilePtr);
                } break;
            case IN:
                if (chr == '\n'){
                    *putBack++ = (char) chr;
                    *putBack = '\0';
                    putBack = putBackOriginalPtr;
                    fputs(putBack, *writeFilePtr);
                    state = OUT;
                    break;
                }
                if (chr != '"') {
                    *includeFileName++ = (char) chr;
                    *putBack++ = (char) chr;
                    break;
                } else {
                    *includeFileName = '\0';
                    openFile(includeFileNameOriginalPtr, &includeFilePtr, "r");
                    copyFile(&includeFilePtr, writeFilePtr);
                    includeFileName = includeFileNameOriginalPtr;
                    state = OUT;
                    putBack = putBackOriginalPtr;
                    break;
                }
            default:
                break;
        }
    } rewind(*writeFilePtr);
    printFile(*writeFilePtr);
}
