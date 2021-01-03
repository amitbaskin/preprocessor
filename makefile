preprocessor: copyFile.c copyFile.h includeFiles.c includeFiles.h openFile.c openFile.h preprocessor.c preUtils.c preUtils.h processArg.c processArg.h removeComments.c removeComments.h
	gcc -Wall -ansi -pedantic -lm copyFile.c copyFile.h includeFiles.c includeFiles.h openFile.c openFile.h preprocessor.c preUtils.c preUtils.h processArg.c processArg.h removeComments.c removeComments.h
