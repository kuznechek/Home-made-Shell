#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/shell.h"

//
// Created by anastasiwei on 24.04.2021.
//

void commands_loop(void)
{
    char *command_line;
    char **args;
    int status;

    do {
        printf("> ");

        command_line = read_line();
        args = parse_line(command_line);
        status = execute(args);

        free(command_line);
        free(args);
    } while (status);
}

char* read_line(void)
{
    char* buf = NULL;
    ssize_t buf_size = 0;
    getline(&buf, &buf_size, stdin);
    return buf;
}
char** parse_line(char* buf)
{
    int buf_size = SHELL_TOK_BUF_SIZE;
    int pos = 0;
    char** tokens_array = malloc(buf_size * sizeof (char*));
    char* token;

    if (check_mem(tokens_array) == -1)
        exit(-1);

    token = strtok(buf, SHELL_TOK_DELIM);

    while (token != NULL) {
        tokens_array[pos] = token;
        pos++;

        if (pos >= buf_size) {
            buf_size += SHELL_TOK_BUF_SIZE;
            tokens_array = realloc(tokens_array, buf_size + sizeof(char*));
            if (check_mem(tokens_array) == -1)
                exit(-1);
        }
        token = strtok(NULL, SHELL_TOK_DELIM);
    }
    tokens_array[pos] = NULL;
    return tokens_array;
}
int check_mem(char* b)
{
    if (!b) {
        printf("Ошибка выделения памяти\n");
        return -1;
    }
    return 0;
}
