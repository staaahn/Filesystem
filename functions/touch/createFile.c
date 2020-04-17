#include "createFile.h"

int createFile(struct filesystem_volume volume, struct arguments command) {
    /* Get args */
    char* name = command.args[1];
    int filesize = atoll (command.args[2]); // size in LBAs

    printf("Creating filename: %s\n", name);

    // Check to see if existing file has the same name
    filesystem_volume *temp = malloc(sizeof(filesystem_volume));

    if (strcmp(temp->name, name) == 0) {
        printf("File already exists\n");
        return -1;
    }

    /* Create a buffer for of 'f' */
    char* buffer = malloc(volume.blockSize);
    printf("filesize: %d\n", filesize);
    int result = addName(name, buffer);
    if (result != 1) {
        printf("Fi")
        return 0;
    }
    for (int i = 0; i < volume.blockSize; i++) 
        buffer[i] = 'f';

    /* Write 'f' into 'filesize' number of blocks */
    for (int j = 0; j < filesize; j++) {
        uint64_t result = LBAwrite( buffer, 1,j);
        //volume.map[j] = 1;
    }
    printf("- COMPLETE\n");
    return 1;
}