#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* This is for read/write buffers */
#define MD_READ_BUF_SIZE 1024
#define MD_WRITE_BUF_SIZE 1024
#define MD_BUF_FLUSH -1

/* This is for command chaining */
#define MD_CMD_NORM 0
#define MD_CMD_OR 1
#define MD_CMD_AND 2
#define MD_CMD_CHAIN 3

/* This is for convert_number() */
#define MD_CONVERT_LOWERCASE 1
#define MD_CONVERT_UNSIGNED 2

/* 1 if using system getline() */
#define MD_USE_GETLINE 0
#define MD_USE_STRTOK 0

#define MD_HIST_FILE ".simple_shell_history"
#define MD_HIST_MAX 4096

/* Global environment variables */
extern char **environ;

/**
 * struct md_liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct md_liststr
{
	int num;
	char *str;
	struct md_liststr *next;
} md_list_t;

/**
 * struct md_passinfo - contains pseudo-arguments to pass into a function,
 * allowing a uniform prototype for a function pointer struct
 * @arg: a string generated from getline containing arguments
 * @argv: an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct md_passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	md_list_t *env; /* Linked list local copy of environ */
	md_list_t *history;
	md_list_t *alias;
	extern char **environ; /* Global environment variables */
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory management */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} md_info_t;

#define MD_INFO_INIT                                 \
	{                                               \
		NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
			0, 0, 0                               \
	}

/**
 * struct md_builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct md_builtin
{
	char *type;
	int (*func)(md_info_t *);
} md_builtin_table;

#endif /* _SHELL_H_ */
