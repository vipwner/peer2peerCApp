#ifndef CHUNK_H_INCLUDED
#define CHUNK_H_INCLUDED
/**
 * Chunk Chunk.h
 *
 * @date 02/01/2015
 * @author Álvaro Jose Lobaton Restrepo. Codigo: 1130054
 * @author Jhon Jairo Pantoja. Codigo: 1125572
 * @author Leydi Joanna Carvajal Henao. Codigo:1125189
 */

/**
 * Estructura que describe un chunk, permitiendonos almacenar sus atributos.
 */
typedef struct {
    char *idChunk;
    char *SHA;
    FILE *file;
    int bytesReaded;
    int status; // Indica si esta descargado o aun esta pendiente su descarga.
} Chunk;

#endif
