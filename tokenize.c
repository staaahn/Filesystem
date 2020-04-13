#define LINE_LENGTH 256 // CHAR
#define MAX_ARGS 8
#define ARG_LENGTH 32 // CHAR
#define DELIMITERS " "

void print(char args[MAX_ARGS][ARG_LENGTH], int argc) {
    for(int i = 0; i < argc; i++) {
        printf("%d : %s\n", i, args[i]);
    }
}

void tokenize(char line[LINE_LENGTH], char args[MAX_ARGS][ARG_LENGTH], int* argc) {
    char* token;
    char* rest = line;
    *argc = 0;
    while ((token = strtok_r(rest, DELIMITERS, &rest))) {
        if(*argc > MAX_ARGS) {
            printf("****** TO MANY ARGS ******\n");
            break;
        }
        strcpy(args[*argc], token);
        *argc += 1;
    }
}


