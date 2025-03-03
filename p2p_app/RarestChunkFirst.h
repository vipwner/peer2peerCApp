#ifndef RARESTCHUNKFIRST_H_INCLUDED
#define RARESTCHUNKFIRST_H_INCLUDED
// C LIBRARIES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Chunk.h"
#include "Node.h"

/**
 * RarestChunkFirst RarestChunkFirst.h
 *
 * @date 02/01/2015
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * [getRarestChunkFirst Metodo encargado de obtener la posicion del chunk mas raro.]
 * @param  rarestSHA     [Cadena correspondiente al SHA del chunk mas raro que se encontro]
 * @param  torrentChunks [Contenedor de los Chunks del torrent.]
 * @param  chunkNumber   [Corresponde al numero de chunks.]
 * @param  nodes         [Contenedor de nodos de la red.]
 * @param  nodeNumber    [Corresponde al numero de nodos.]
 * @return int           [Posicion del rarest chunk.]
 */
int getRarestChunkFirst(char *rarestSHA, Chunk *torrentChunks, int chunkNumber,
                        Node *nodes, int nodeNumber);
/**
 * [getMinPosOf Metodo que permite obtener el la posicion del valor menor de un arreglo.]
 * @param  array [Contenedor.]
 * @param  len   [Tamano del contenedor.]
 * @return int   [Correspondiente a la posicion.]
 */
int getMinPosOf(int *array, int *posArr, int len);

/**
 * [searchNode Metodo que permite determinar si dicho SHA del chunk mas raro
 * esta en un nodo]
 * @param  id         [Corresponde al id del nodo encontrado.]
 * @param  ip         [Corresponde a la ip del nodo encontrado.]
 * @param  port       [Corresponde al puerto del nodo encontrado.]
 * @param  nodes      [Contenedor de nodos.]
 * @param  nodeNumber [Numero de nodos.]
 * @param  rarestSHA  [Corresponde a la cadena que contiene el SHA del rarestChunk]
 * @return int        [Correspondiente a la validacion si esta o no el SHA en dicho nodo.]
 */
int searchNode(char *id, char *ip, char *port, Node *nodes, int nodeNumber,
               char *rarestSHA);
#endif