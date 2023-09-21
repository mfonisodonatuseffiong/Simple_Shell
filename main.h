#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>


#define BUFFER_SIZE 1024
#define TOKEN_BUFFSIZE 124
#define DELIM " \t\r\n\a"


extern char **environ;


typedef struct data
{
	char **argv;
	char *input;
	char **arguments;
	int stat;
	int count;
	char **env;
	char *pid;
} shell_data;


typedef struct builtin
{
	char *name;
	int (*function)(shell_data *data);
} cmd_builtin;


typedef struct cmd_line
{
	char *line;
	struct cmd_list *next;
} cmd_list;


typedef struct sep_list
{
	char sep;
	struct sep_list *next;
} sep_t;


typedef struct var_list
{
	int var_length;
	char *value;
	int val_length;
	struct var_list *next;
} var_t;


int string_len(const char *string);
char *string_dup(const char *string);
int string_cmp(char 8string1, char 8string2);
void memory_cpy(void *dest, const void *src, unsigned int size);
int -stoi(char *string);
char *_itos(int n);
int get_length(int i;)
void get_signint(int sign);
int (*get_built(char *command))(shell_data);
char *_read(int *fe);

#endif

