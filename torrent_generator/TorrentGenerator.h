#ifndef TORRENTGENERATOR_H_INCLUDED
#define TORRENTGENERATOR_H_INCLUDED
 // C LIBRARIES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Chunk.h"

/**
 * TorrentGenerator TorrentGenerator.h
 *
 * @date 20/12/2014
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * [partitioning Metodo encargado de particionar el archivo]
 * @param  fileName 			[El nombre del archivo]
 * @return int                	[Un entero correspondiente a si se pudo o no particionar.]
 */
int partitioning(char *fileName);

#endif

