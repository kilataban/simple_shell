#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void command(char *av[]);
char *execu(char *command);
int stat(const char *pathname, struct stat *statbuf);


#endif /*MAIN_H*/
