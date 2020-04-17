#ifndef stucts_h
#define stucts_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARGS 8
#define ARG_LENGTH 32 // CHAR

struct filesystem_volume{
    char* filename;
    uint64_t volumeSize;
	uint64_t blockSize;
    uint64_t blockCount;
    int* map;
    int retVal;
};

struct arguments {
    char args[MAX_ARGS][ARG_LENGTH];
    char* opt;
    int argc;
};

/* Name can only be 16 characters long */
int addName(char* name, char* buffer);

#endif /* stucts_h */