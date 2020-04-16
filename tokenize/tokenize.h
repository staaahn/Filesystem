#ifndef tokenize_h
#define tokenize_h

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 256 // CHAR
#define MAX_ARGS 8
#define ARG_LENGTH 32 // CHAR
#define DELIMITERS " \t\n"

struct arguments {
    char args[MAX_ARGS][ARG_LENGTH];
    char* opt;
    int argc;
};

void tokenize(char line[LINE_LENGTH], struct arguments *command);

#endif /* tokenize_h */