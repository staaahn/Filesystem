#include "structs.h"

int addName(char* name, char* buffer) {
    int len = strlen(name);
    if(len <= 16) { 
        for(int i=0; i < strlen(name); i++) {
            buffer[i] = name[i];
        }
        return 1;
    }
    return 0;
}