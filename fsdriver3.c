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
    char opt[8] = "foo"; // 8 letter word
    char line[255]; // 255 letter word
    int arg_count = 0;
    while(strcmp(opt, "exit") != 0) {
        printf("$ "); // prompt
        scanf("%s", line);
        // tokenize()
        // opt = args[0];
        if(strcmp(opt, "ls") {
            listDir(arguments, arg_count);
        } else if(strcmp(opt, "mkdir") {
            createDir(arguments, arg_count);
        } else if(strcmp(opt, "touch") {
            createFile(arguments, arg_count);
        } else if(strcmp(opt, "rm") {
            removeFile(arguments, arg_count);
        } else if(strcmp(opt, "cp") {
            copyFile(arguments, arg_count);
        } else if(strcmp(opt, "mv") {
            moveFile(arguments, arg_count);
        } else if(strcmp(opt, "set") {
            setMetaData(arguments, arg_count);
        } else if() {
            special1(arguments, arg_count);
        } else if() {
            special2(arguments, arg_count);
        }
    }

    /* Close Partition */
    closePartitionSystem();
    return 0;
}

// // Driver File

// createFile() {
//   LBA_write( stuff) 
// }

// readFile() {
//  LBA_read 
// }

// listDir() {
//   LBA_read()
// }

// createDir() {
//   LBA_write()
// }

// #include "CreateFile.h"
// #include "ListDir.h"
// #include "CreateDir.h"


// main () {
//   startpartition (stuff) // beer
//   while(true) {
//     //menu
//     1. create a dir
//       createDir(dir name);
//     2. list dir
//       listDir();
//     3. create a file
//     4. rm a file
//             enter the filename
//             removed file (filename)
//     10. enter q to quit
//   }
    
//   closepartition (stuff) // beer
// }


