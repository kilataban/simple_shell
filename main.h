#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int ac, char *av[]);
void command(char *av[]);
char *getCommand(char *command);

#endif /*MAIN_H*/
