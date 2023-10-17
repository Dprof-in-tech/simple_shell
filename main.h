#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define MAX_ARGS 1024
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
void check(void);
char *allocate_memory(void);
char *tokenizer(char **input_line);
int is_file(const char *path);
int is_numeric(const char *str);
int main(void);
int handle_env(char *command);
void handle_exit(char *command, char *arguments[]);
void handle_shell(char *command, char *arguments[]);
void remove_newline(char *str);
char *handle_path(char *command, char *arguments[]);
void handle_fullshell(char *exe_path, char *arguments[]);
ssize_t readFile(int file, void *buffer, size_t count);
#endif
