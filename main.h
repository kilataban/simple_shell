#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>

void execu(char **av, char *envp[]);
char *getPath(char *command);
int _strlen(char *str);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *str1, char *str2);

#endif/*MAIN_H*/
