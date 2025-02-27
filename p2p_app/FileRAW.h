#ifndef FILERAW_H_INCLUDED
#define FILERAW_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * FileRAW FileRAW.h
 *
 * @date 02/01/2015
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * [readFile Metodo encargado de leer un archivo.]
 * @param fileName   [char* Correspondiente al nombre del archivo.]
 * @param content    [char 	Correspondiente al contenido que se leera.]
 * @param contentTam [int 	Correspondiente al tamano del contenido a leer.]
 */
void readFile(char* fileName, char *content, int contentTam);
/**
 * [writeFile Metodo encargado de escribir en un archivo.]
 * @param fileName   [char* Correspondiente al nombre del archivo.]
 * @param line       [char 	Corresponde a la linea que se escribira.]
 * @param lineLenght [int 	Correspondiente al tamano de la linea.]
 */
void writeFile(char* fileName, char *line, int lineLenght);
void writeFile_(char *fileName, char *content, int contentLenght);
int getFileSize(char *fileName);
#endif
