#ifndef TORRENT_H_INCLUDED
#define TORRENT_H_INCLUDED
#include "Chunk.h"
/**
 * Torrent Torrent.h
 *
 * @date 02/01/2015
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * Estructura Torrent, que nos permite el manejo de sus dichos atributos.
 */
typedef struct {
    char *torrentFileName;
    int chunksQ;
    Chunk *chunks;
} Torrent;

#endif
