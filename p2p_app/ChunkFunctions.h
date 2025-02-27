#ifndef CHUNKFUNCTIONS_H_INCLUDED
#define CHUNKFUNCTIONS_H_INCLUDED
 // C LIBRARIES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StringFunctions.h"
#include "FileRAW.h"
/**
 * Rebuilder Rebuilder.h
 * 
 * @date 02/01/2015
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * [fileRebuilding Metodo encargado de la reconstrucion del archivo.]
 * @param nameFileWe  [Nombre del archivo a ser escrito.]
 * @param chuksNumber [Numero de chunks.]
 */
void fileRebuilding(char *nameFileWe, int chunksNumber);
int getIDChunk(char *id, char *SHA);
#endif
