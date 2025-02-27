#ifndef TORRENTLOADER_H_INCLUDED
#define TORRENTLOADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringFunctions.h"
#include "Chunk.h"
#include "Torrent.h"
/**
 * TorrentLoader TorrentLoader.h
 * 
 * @date 02/01/2015
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */
/**
 * [loadTorrent Metodo encargado de cargar un archivo Torrent.]
 * @param  torrentFileName [Nombre del archivo .torrent]
 * @param  chunks          [Contenedor de los chunks del archivo .torrent a ser cargado.]
 * @return int             [Correspondiente al numero de chunks del torrent.]
 */
int loadTorrent(char* torrentFileName, Chunk *chunks);

#endif
