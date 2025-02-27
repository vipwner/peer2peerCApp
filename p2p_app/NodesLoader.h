#ifndef NODESLOADER_H_INCLUDED
#define NODESLOADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "StringFunctions.h"
#include "Peer2Peer.h"

/**
 * NodesLoader NodesLoader.h
 * 
 * @date 02/01/2015
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * [loadNodes Metodo encargado de Cargar los nodos, en su respectiva estructura claro.]
 * @param  nodesContainer [Contenedor de tipo Node, que contiene varios nodos.]
 * @return int            [Correspondiente al numero de nodos.]
 */
int loadNodes(Node *nodesContainer);
/**
 * [setChunksNode Metodo encargado de cargar los chunks de un nodo.]
 * @param  content       [Contenido del chunk.]
 * @param  contentLenght [Tamano del contenido.]
 * @param  chunks        [Arreglo de chunks.]
 * @return int           [Correspondiente a la cantidad de chunks en el nodo.]
 */
int setChunksNode(char* content, int contentLenght, Chunk *chunks);

#endif