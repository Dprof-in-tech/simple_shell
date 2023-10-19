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

/**
 * struct info_t - Structure to store linked list
 * @environ: first member
 * @env_changed: second member
 */

typedef struct info_t
{
	char **environ;
	int env_changed;
} info_t;
extern char **environ;
void check(void);
void allocate_memory(char **input_line);
void free_memory(char *input_line);
char *tokenizer(char **input_line);
int is_file(const char *path);
int is_numeric(const char *str);
int main(void);
int cmpstr(const void *b, const void *c);
void custom_get_environ(info_t *info);
void handle_exit(char *command, char *arguments[]);
void handle_shell(char *command, char *arguments[]);
void remove_newline(char *str);
char *handle_path(char *command, char *arguments[]);
void handle_fullshell(char *exe_path, char *arguments[]);
void changeDirectory(char *arguments[]);
ssize_t readFile(int file, void *buffer, size_t count);
#endif
