//
// Created by anastasiwei on 24.04.2021.
//

#ifndef SHELL_SHELL_H
#define SHELL_SHELL_H
#define SHELL_TOK_BUF_SIZE 64
#define SHELL_TOK_DELIM " \t\r\n\a"
#define RUNNING 1



void commands_loop(void);

char* read_line(void);

int check_mem(char* b);

char** parse_line(char* buf);

#endif //SHELL_SHELL_H


