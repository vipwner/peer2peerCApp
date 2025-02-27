#ifndef CHUNK_H_INCLUDED
#define CHUNK_H_INCLUDED

/**
 * Chunk Chunk.h
 *
 * @date 20/12/2014
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * Estructura que nos permite almacenar los atributos del chunk.
 */
typedef struct 
{
	char idChunk[100];
	char SHA[40];
}Chunk;

#endif