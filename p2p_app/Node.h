#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include "Chunk.h"

/**
 * Node Node.h
 *
 * @date 02/01/2015
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * Estructura que describe un Nodo, por ende
 * para facilitar el manejo con sus atributos.
 */
typedef struct
{
    char* idNode;
    char* ipNode;
    char* portNode;
    int chunksQ;
    Chunk *chunks;
}Node;

#endif
