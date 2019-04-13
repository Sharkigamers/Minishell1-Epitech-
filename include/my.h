/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** proto of the minishell
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

#ifndef MY_
#define MY_

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\x1B[0m"
#define BLUE "\033[1;34m"

typedef struct arg
{
    char **argv;
    int argc;
    char *save_path;
    int return_value;
    int used_cd;
    char *catargv;
} arg_t;

/* lib */

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, char const stop_str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
void my_printf(char *fmt, ...);
int my_strdbncmp(char const *s1, char const *s2, char stop_s1, char stop_s2);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src, char *save);
char *my_realstrcat(char *dest, char const *src);
int my_atoi(char const *str);
void my_puterrorstr(char *str);
int my_strcmpn(char const *s1, char const *s2, int n);

/* prog */

int minishell(char **env);
int in_loop(char ***save_env, arg_t *arg, char **buf);
int prompt(char **buf, char **save_env);
void last_free(char ***save_env);
void seg_error(arg_t *arg, int status);

/* env */

int cond_env(char ***save_env, char *buf, arg_t *arg);
void malloc_env(char **env, char ***save_env, arg_t *arg);
void malloc_setenv(char ***save_env, char *buf);
void malloc_unsetenv(char ***save_env, char *buf);
int gest_unset_error(char *buf);
void free_uncpy(char ***cpy_save_env);
void free_cpy(char ***cpy_save_env);

/* cd */

void cond_cd(arg_t *arg, char ***save_env);
void change_pwd(char ***save_env);
void fill_oldpwd(char ***save_env, int i, char *pwd);
void cond_dash(char **oldpwd, char ***save_env, int i);
int cond_last_dash(arg_t *arg);
void init_oldpwd(char ***save_env);

/* argv */

char **fill_argv(char *buf);
int fill_argc(arg_t *arg);

/* exec */

int exec(char **save_env, arg_t *arg);
int wave(arg_t *arg, char **save_env);
void last_check_failed_exec(int *success, char **full_path, arg_t *arg);
int check_folder(char *path, arg_t *arg);
void cond_exec(int nb_arg, char ***from_path, arg_t *arg);
void print_error(char *str, arg_t *arg);
int check_binary(char *argu);


/* exit */

int exit_cond(char **buf, arg_t *arg);

/* redirrections */

void redi_to_right(arg_t *arg, char **save_env);

#endif
