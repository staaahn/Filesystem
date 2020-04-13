#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "fsLow.h"
#include "tokenize.c"


int main (int argc, char *argv[]) {
    char * filename;
	uint64_t volumeSize;
	uint64_t blockSize;
    int retVal;
    

    /* Check for correct argc */
	if (argc == 4){
		filename = argv[1];
		volumeSize = atoll (argv[2]);
		blockSize = atoll (argv[3]);
	} else {
        printf("Need 3 args (filename volumeSize blcokSize\n");
        return EXIT_FAILURE;
    }

    /* Create Partition */
    printf("Opening %s, Volume Size: %llu;  BlockSize: %llu\n", filename, (ull_t)volumeSize, (ull_t)blockSize);
    retVal = startPartitionSystem (filename, &volumeSize, &blockSize);	
	printf("Opened  %s, Volume Size: %llu;  BlockSize: %llu; Return %d\n", filename, (ull_t)volumeSize, (ull_t)blockSize, retVal);
    if(retVal == 0) {
        printf("\tresult: success\n");
    } else if(retVal == -1) {
        printf("\tresult: file exists but can not open for write\n");
    } else if(retVal == -2) {
        printf("\tresult: insufficient space for the volume\n");
    } else {
        printf("\tresult: %d\n", retVal);
    }

    /* MENU */
    char* opt = malloc(sizeof(char) * 8); // 8 letter word
    char* line = malloc(sizeof(char) * 255); // 255 letter word
    char** arguments;
    int arg_count = 0;
    while(strcmp(opt, "exit") != 0) {
        printf("NOTE: type \"exit\" to exit this prompt\n"); // prompt
        printf("$ "); // prompt
        scanf("%s", line);
        tokenize(line, arguments, arg_count);
        opt = arguments[0];
        if(strcmp(opt, "ls") == 0) {
            listDir(arguments, arg_count);
        } else if(strcmp(opt, "mkdir") == 0) {
            createDir(arguments, arg_count);
        } else if(strcmp(opt, "touch") == 0) {
            createFile(arguments, arg_count);
        } else if(strcmp(opt, "rm") == 0) {
            removeFile(arguments, arg_count);
        } else if(strcmp(opt, "cp") == 0) {
            copyFile(arguments, arg_count);
        } else if(strcmp(opt, "mv") == 0) {
            moveFile(arguments, arg_count);
        } else if(strcmp(opt, "set") == 0) {
            setMetaData(arguments, arg_count);
        } else if(strcmp(opt, "special1") == 0) {
            special1(arguments, arg_count);
        } else if(strcmp(opt, "special2") == 0) {
            special2(arguments, arg_count);
        }
    }

    /* Close Partition */
    closePartitionSystem();
    return EXIT_SUCCESS;
}
