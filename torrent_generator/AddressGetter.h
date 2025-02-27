#ifndef ADDRESSGETTER_H_INCLUDED
#define ADDRESSGETTER_H_INCLUDED
 // C LIBRARIES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getName(char *path, int path_len, char *copy_p);
int getPosOf(char a, char *string);

#endif