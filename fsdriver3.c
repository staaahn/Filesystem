#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "fsLow.h" /* (startPartitionSystem) (closePartitionSystem) (LBAwrite) (LBAread) */
#include "tokenize.c" /* (tokenize) (print) */

#define LINE_LENGTH 256 // CHAR
#define MAX_ARGS 8
#define ARG_LENGTH 32 // CHAR

// struct arguments {
//     char arguments[MAX_ARGS][ARG_LENGTH];
//     char* opt;
//     int arg_count;
// };

int main (int argc, char *argv[]) {
    char* filename;
	uint64_t volumeSize;
	uint64_t blockSize;
    int retVal;
    

    /* Check for correct argc */
	if (argc == 4){
		filename     = argv[1];
		volumeSize   = atoll (argv[2]); // must be greater than 500,000 and a power of 2
		blockSize    = atoll (argv[3]); // must be greater than 512 and a power of 2
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
        // return EXIT_FAILURE;
    } else if(retVal == -2) {
        printf("\tresult: insufficient space for the volume\n");
        // return EXIT_FAILURE;
    } else {
        printf("\tresult: %d\n", retVal);
        // return EXIT_FAILURE;
    }

    /* MENU */
    char* opt = malloc(sizeof(char) * ARG_LENGTH);
    char line[LINE_LENGTH];
    char arguments[MAX_ARGS][ARG_LENGTH];
    int arg_count = 0;

    printf("\nNOTE: type \"exit\" to exit this prompt\n"); // prompt
    // while(strcmp(opt, "exit") != 0) {
        printf("$ "); // prompt
        fgets(line, LINE_LENGTH, stdin);
        tokenize(line, &arguments, &arg_count);
        print(arguments, arg_count);
        opt = arguments[0];
        // if(strcmp(opt, "ls") == 0) {
        //     listDir(arguments, arg_count);
        // } else if(strcmp(opt, "mkdir") == 0) {
        //     createDir(arguments, arg_count);
        // } else if(strcmp(opt, "touch") == 0) {
        //     createFile(arguments, arg_count);
        // } else if(strcmp(opt, "rm") == 0) {
        //     removeFile(arguments, arg_count);
        // } else if(strcmp(opt, "cp") == 0) {
        //     copyFile(arguments, arg_count);
        // } else if(strcmp(opt, "mv") == 0) {
        //     moveFile(arguments, arg_count);
        // } else if(strcmp(opt, "set") == 0) {
        //     setMetaData(arguments, arg_count);
        // } else if(strcmp(opt, "special1") == 0) {
        //     special1(arguments, arg_count);
        // } else if(strcmp(opt, "special2") == 0) {
        //     special2(arguments, arg_count);
        // }
    // }
    // free(opt);

    /* Close Partition */
    // closePartitionSystem();
    return EXIT_SUCCESS;
}
