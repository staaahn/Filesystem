#include "copyFile.h"

#define BUF 512

int copyFile(struct filesystem_volume volume, struct arguments command) {
    //collect new file name and size
    char buffer[BUF];
    char* buffer = malloc(volume.blockSize);
    size_t size;

    int fileSize = atoll(command.args[2]);
    char* oldFileName = command.args[1];
    char* newFileName = command.args[3];

    fopen(volume.filename, "r");

    //create new file with user input name, open for write 
    FILE* newFileName;
    fopen(newFileName, "w");
    
    //while data in old file, write that data to new file
    while(size = fread(buffer, 1, BUF, oldFileName)){
        fwrite(buffer, 1, size, newFileName);
    }

    //close all files
    fclose(volume.filename);
    fclose(newFileName);
    return 0;
}
